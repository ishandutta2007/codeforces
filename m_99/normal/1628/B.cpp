#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		int n;
		cin>>n;
		vector<string> s(n);
		rep(i,n){
			cin>>s[i];
		}
		bool f = false;
		rep(i,n){
			if(s[i].size()==1)f = true;
			if(s[i].size()==2){
				if(s[i][0]==s[i][1])f = true;
			}
			if(s[i].size()==3){
				if(s[i][0]==s[i][2])f = true;
			}
		}
		if(f){
			printf("YES\n");
			continue;
		}
		
		{
			set<string> S;
			rep(i,n){
				string t(s[i].rbegin(),s[i].rend());
				if(S.count(t)){
					f = true;
					break;
				}
				S.insert(s[i]);
			}
		}
		{
			set<string> S2,S3;
			rep(i,n){
				string t(s[i].rbegin(),s[i].rend());
				if(t.size()==2){
					if(S2.count(t)){
						f = true;
						break;
					}
					S3.insert(s[i]);
				}
				else{
					if(S3.count(t.substr(0,2))){
						f = true;
						break;
					}
					S2.insert(s[i].substr(0,2));
				}
			}
		}
		if(f)printf("YES\n");
		else printf("NO\n");
	}
	
	return 0;
}