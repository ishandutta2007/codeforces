#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x)+modulo)%modulo)
#define Inf 100000000



int main() {
	
	int t;
	cin>>t;
	
	for(int _=0;_<t;_++){
		int n,x,y;
		cin>>n>>x>>y;
		
		int ok = 0;
		int ng = n;
		while(ng-ok>1){
			int mid = (ok+ng)/2;
			int r = n;
			int l = n+1-mid;
			if(r<=x)r--;
			if(l<=y)l--;
			
			if(r+l<x+y+1){
				ng = mid;
				continue;
			}
			
			r = n;
			l = n+1-mid;
			if(r<=y)r--;
			if(l<=x)l--;
			if(r+l<x+y+1){
				ng = mid;
				continue;
			}
			ok = mid;
		}
		cout<<n-ok<<' ';
		
		ok = 0;
		ng = n;
		while(ng-ok>1){
			int mid = (ok+ng)/2;
			int r = mid;
			int l = 1;
			if(r>=x)r++;
			if(l>=y)l++;
			
			if(r+l>x+y){
				ng = mid;
				continue;
			}
			
			r = mid;
			l = 1;
			if(r>=y)r++;
			if(l>=x)l++;
			if(r+l>x+y){
				ng = mid;
				continue;
			}
			ok = mid;
		}
		cout<<ok+1<<endl;
		
	}
	
    return 0;
}