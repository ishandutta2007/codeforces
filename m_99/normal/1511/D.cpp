#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

string get(int cur){
	if(cur==0){
		return "aa";
	}
	char c = 'a' + cur;
	string ret = "";
	ret += c;
	rep(i,cur-1){
		ret += 'a' + i;
		ret += c;
	}
	ret += get(cur-1);
	ret += c;
	ret += c;
	return ret;
}

int main(){
	
	int n,k;
	cin>>n>>k;
	
	string s = get(k-1);
	
	string t = s;
	if(t.size()>1)t.erase(t.begin());
	while(s.size()<n){
		s += t;
	}
	
	while(s.size()!=n)s.pop_back();
	cout<<s<<endl;
	
    return 0;
}