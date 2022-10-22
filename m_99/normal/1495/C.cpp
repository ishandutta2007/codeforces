#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000



int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n,m;
		scanf("%d %d",&n,&m);
		
		vector<string> s(n);
		rep(i,n)cin>>s[i];
		
		int x = 1;
		if(n%3==1)x = 0;
		rep(i,n){
			if(i%3==x){
				rep(j,m)s[i][j] = 'X';
			}
		}
		
		for(int i=x+1;i<n;i+=3){
			if(i+2>=n)break;
			bool f = false;
			rep(j,m){
				if(s[i][j]=='X'){
					s[i+1][j] = 'X';
					f=true;
					break;
				}
			}
			if(!f){
				rep(j,m){
					if(s[i+1][j]=='X'){
						s[i][j] = 'X';
						f=true;
						break;
					}
				}
			}
			if(!f){
				s[i][0] = 'X';
				s[i+1][0] = 'X';
			}
		}
	
		
		rep(i,n)cout<<s[i]<<endl;

		
		
		
	}
		
	
    return 0;
}