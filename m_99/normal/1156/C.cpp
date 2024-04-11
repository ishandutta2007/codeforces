#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000001

int main(){
	
	int n,z;
	scanf("%d %d",&n,&z);
	vector<int> x(n);
	rep(i,n){
		scanf("%d",&x[i]);
		
	}
	
	sort(x.begin(),x.end());
	
	int ok = 0,ng = n/2+1;
	
	while(ng-ok>1){
		int mid = (ok+ng)/2;
		
		bool f = true;
		rep(i,mid){
			if(x[n-mid+i] - x[i] < z)f=false;
		}
		if(f)ok = mid;
		else ng = mid;
	}
	
	cout<<ok<<endl;
	
	return 0;
}