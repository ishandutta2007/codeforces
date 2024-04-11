#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

int main(){
	
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		long long x,y,a,b;
		cin>>x>>y>>a>>b;
		
		if(a==b){
			cout<<min(x/a,y/a)<<endl;
		}
		else{
			long long ok = 0LL,ng = Inf;
			while(ng-ok>1LL){
				long long mid = (ok+ng)/2;
				
				long long xx = x,yy = y;
				xx -= min(a,b)*mid,yy -= min(a,b)*mid;
				if(xx<0||yy<0){
					ng = mid;
					continue;
				}
				long long d = max(a,b)-min(a,b);
				if((xx/d) + (yy/d) >= mid)ok = mid;
				else ng = mid;
				
			}
			cout<<ok<<endl;
		}
		
		
	}
	return 0;
}