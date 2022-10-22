#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000

bool check(string s){
	int c = 0;
	rep(i,s.size()){
		if(s[i]=='(')c++;
		else c--;
		if(c<0)return false;
	}
	return c==0;
}

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		string s;
		cin>>s;
		bool f = false;
		rep(i,1<<3){
			string t = s;
			rep(j,t.size()){
				int x = t[j] - 'A';
				if((i>>x)&1)t[j] = '(';
				else t[j] = ')';
			}
			if(check(t)){
				f=true;
				break;
			}
		}
		if(f)printf("YES\n");
		else printf("NO\n");
	}
	
    return 0;
}