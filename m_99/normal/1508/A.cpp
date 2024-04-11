#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

string get(string s,string t,char c){
	string ret = "";
	int n = s.size()/2;
	int c0 = 0,c1 = 0;
	rep(_,n){
		while(s[c0]!=c){
			ret += s[c0];
			c0++;
		}
		while(t[c1]!=c){
			ret += t[c1];
			c1++;
		}
		c0++;
		c1++;
		ret += c;
	}
	while(c0!=s.size()){
		ret += s[c0];
		c0++;
	}
	while(c1!=t.size()){
		ret += t[c1];
		c1++;
	}
	return ret;
}

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		cin>>n;
		
		vector<string> s(3);
		rep(i,3)cin>>s[i];
		vector<int> cnt(3,0);
		rep(i,3){
			rep(j,2*n){
				if(s[i][j]=='0')cnt[i]++;
			}
		}
		string ans;
		rep(i,3){
			for(int j=i+1;j<3;j++){
				if(cnt[i]>=n&&cnt[j]>=n){
					ans = get(s[i],s[j],'0');
					goto L;
				}
				if(cnt[i]<=n&&cnt[j]<=n){
					ans = get(s[i],s[j],'1');
					goto L;
				}
			}
		}
		
		
		L:;
		cout<<ans<<endl;
		
	}
	
	
    return 0;
}