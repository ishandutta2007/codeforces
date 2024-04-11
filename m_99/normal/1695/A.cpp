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
		int M = -Inf;
		rep(i,n){
			rep(j,m){
				cin>>a[i][j];
				M = max(M,a[i][j]);
			}
		}
		rep(i,n){
			rep(j,m){
				if(M==a[i][j]){
					int h = max(i+1,n-i);
					int w = max(j+1,m-j);
					cout<<h*w<<endl;
					
				}
			}
		}
		
		
		
	}
	
    return 0;
}