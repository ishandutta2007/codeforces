#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n,m;
		cin>>n>>m;
		
		vector a(n,vector<int>(m));
		rep(i,n){
			rep(j,m){
				scanf("%d",&a[i][j]);
			}
		}
		
		vector l(n,vector<int>(m,Inf)),r(n,vector<int>(m,-Inf));
		l[0][0] = a[0][0];
		r[0][0] = a[0][0];
		rep(i,n){
			rep(j,m){
				if(i!=n-1){
					l[i+1][j] = min(l[i+1][j],l[i][j] + a[i+1][j]);
					r[i+1][j] = max(r[i+1][j],r[i][j] + a[i+1][j]);
				}
				if(j!=m-1){
					l[i][j+1] = min(l[i][j+1],l[i][j] + a[i][j+1]);
					r[i][j+1] = max(r[i][j+1],r[i][j] + a[i][j+1]);
				}
			}
		}
		if(l[n-1][m-1]%2==0 && l[n-1][m-1]<=0 && r[n-1][m-1]>=0)printf("YES\n");
		else printf("NO\n");
					
		
	}
	
    return 0;
}