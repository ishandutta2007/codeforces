#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		scanf("%d",&n);
		vector<int> x(n);
		rep(i,n)scanf("%d",&x[i]);
		vector<int> y;
		int cur = 0;
		
		rep(i,n){
			int ans = x[i];
			rep(j,30){
				int b = (ans>>j)&1;
				if((cur>>j)&1){
					ans ^= 1<<j;
				}
				else{
					if(b){
						ans ^= 1<<j;
					}
				}
			}
			y.push_back(ans);
			cur = ans ^ x[i];
		}
		
		rep(i,n){
			if(i!=0)printf(" ");
			printf("%d",y[i]);
		}
		printf("\n");
						
		
	}
	
	return 0;
}