#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		string a,b;
		cin>>a>>b;
		int n = a.size(),m = b.size();
		
		int ans = n+m;
		
		rep(i,min(n,m)){
			rep(j,n){
				if(j+i>=n)break;
				rep(k,m){
					if(k+i>=m)break;
					if(a.substr(j,i+1)==b.substr(k,i+1)){
						ans = min(ans,n+m-(i+1)*2);
					}
				}
			}
		}
		
		printf("%d\n",ans);
		
	}

    return 0;
}