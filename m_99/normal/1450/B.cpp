#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000



int main(){
	
	int _t;
	cin>>_t;
	rep(_,_t){
		
		int n,k;
		scanf("%d %d",&n,&k);
		
		vector<int> x(n),y(n);
		
		rep(i,n){
			scanf("%d %d",&x[i],&y[i]);
		}
		
		bool f = false;
		
		rep(i,n){
			bool F = true;
			rep(j,n){
				if(abs(x[i]-x[j])+abs(y[i]-y[j])>k){
					F=false;
					break;
				}
			}
			if(F){
				f=true;
				break;
			}
		}
		
		if(f)printf("1\n");
		else printf("-1\n");
		
		
		
	}
	
    return 0;
}