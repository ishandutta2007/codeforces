#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001


int main(){
	
	
	int _t;
	cin>>_t;
	rep(_,_t){
		int n,m;
		scanf("%d %d",&m,&n);
		vector p(m,vector<int>(n));
		rep(i,m){
			rep(j,n){
				scanf("%d",&p[i][j]);
			}
		}
		
		int ok = 1,ng = Inf;
		while(ng-ok>1){
			int mid = (ok+ng)/2;
			vector<bool> f(n,false);
			rep(i,m){
				rep(j,n){
					if(p[i][j]>=mid)f[j] = true;
				}
			}
			if(f!=vector<bool>(n,true)){
				ng = mid;
				continue;
			}
			bool F = false;
			rep(i,m){
				int c = 0;
				rep(j,n){
					if(p[i][j]>=mid)c++;
				}
				if(c>=2){
					F = true;
					break;
				}
			}
			if(F)ok = mid;
			else ng = mid;
		}
		printf("%d\n",ok);
	}
	return 0;
}