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
		scanf("%d",&n);
		
		int l = -100000,r = 100000,t = 100000,b = -100000;
		rep(i,n){
			int x,y;
			vector<int> f(4);
			scanf("%d %d",&x,&y);
			rep(j,4){
				scanf("%d",&f[j]);
				
				if(f[j]==0){
					if(j==0)l = max(l,x);
					if(j==1)t = min(t,y);
					if(j==2)r = min(r,x);
					if(j==3)b = max(b,y);
				}
			}
		}
		if(l>r||t<b){
			printf("0\n");
		}
		else{
			printf("1 %d %d\n",l,t);
		}
		
		
	}
	
	return 0;
}