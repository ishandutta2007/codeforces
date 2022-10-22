#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001



int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n,m,k;
		cin>>n>>m>>k;
		
		vector<string> s(n);
		rep(i,n)cin>>s[i];
		
		
		vector<string> cur(n,string(m,'.'));
		
		rep(i,n){
			rep(j,m){
				bool f = false;
				rep(x,100){
					int y = i - x,x0 = j-x,x1 = j+x;
					if(y<0||x0<0||x1>=m)break;
					if(s[y][x0]=='.'||s[y][x1]=='.')break;
					if(x >= k){
						f = true;
						break;
					}
					
				}
				if(f){
					rep(x,100){
						int y = i - x,x0 = j-x,x1 = j+x;
						if(y<0||x0<0||x1>=m)break;
						if(s[y][x0]=='.'||s[y][x1]=='.')break;
						cur[y][x0] = '*';
						cur[y][x1] = '*';
						
					}
				}
			}
		}
		if(s==cur)printf("YES\n");
		else printf("NO\n");
		
	}
	
	return 0;
}