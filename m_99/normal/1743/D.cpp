#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf32 1000000001
#define Inf64 2000000000000000001

string get(string s,string t){
	reverse(s.begin(),s.end());
	reverse(t.begin(),t.end());
	string ret(s.size(),'0');
	rep(i,s.size()){
		if(s[i]=='1')ret[i] = '1';
		if(i<t.size()&&t[i]=='1')ret[i] = '1';
	}
	reverse(ret.begin(),ret.end());
	return ret;
}
int main(){
	
	int n;
	cin>>n;
	string s;
	cin>>s;
	reverse(s.begin(),s.end());
	while(s.size()>0 && s.back()=='0')s.pop_back();
	reverse(s.begin(),s.end());
	n = s.size();
	
	if(n==0){
		cout<<0<<endl;
		return 0;
	}
	
	string ans = s;
	int m = n;
	rep(i,n){
		if(s[i]=='1')m--;
		else break;
	}
	
	rep(i,n){
		if(i+m>n)break;
		ans = max(ans,get(s,s.substr(i,m)));
	}
	cout<<ans<<endl;
	
	return 0;
}