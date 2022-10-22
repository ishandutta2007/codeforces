#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		int n;
		cin>>n;
		string s;
		cin>>s;
		
		string t = "";
		rep(i,n){
			if(t.size()>0&&s[i]==t.back())continue;
			t += s[i];
		}
		
		sort(t.begin(),t.end());
		bool f = true;
		
		rep(i,t.size()){
			if(i+1!=t.size()){
				if(t[i]==t[i+1])f=false;
			}
		}
		if(f)printf("YES\n");
		else printf("NO\n");
		
		
		
	}
	
    return 0;
}