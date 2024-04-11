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
		scanf("%d",&n);
		vector a(n,vector<int> (n));
		
		rep(i,n){
			rep(j,n){
				scanf("%d",&a[i][j]);
			}
		}
		
		
		vector b(n,vector<int> (n,0));
			
		rep(i,n-1){
			rep(j,n){
				b[i+1][j] = a[i][j];
				if(i!=0)b[i+1][j] ^= b[i-1][j];
				if(j!=0)b[i+1][j] ^= b[i][j-1];
				if(j!=n-1)b[i+1][j] ^= b[i][j+1];
				
			}
		}
		int ans = 0;
		rep(i,n){
			rep(j,n)ans ^= b[i][j];
		}
		printf("%d\n",ans);
		
	}
	
	return 0;
}