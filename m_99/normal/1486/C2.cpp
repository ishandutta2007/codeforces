#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000001

int query(int l,int r){
	if(l>=r)return -1;
	cout<<"? "<<l<<' '<<r<<endl;
	int ret;
	cin>>ret;
	return ret;
}

int answer(int ans){
	cout<<"! "<<ans<<endl;
	exit(0);
}

int main(){
	
	int n;
	cin>>n;
	
	int S = query(1,n);
	
	int x1 = query(1,S),x2 = query(S,n);
	int ans = -1;
	if(x1==S){
		int ok = S,ng = 1;
		while(ok-ng>1){
			int mid = (ok+ng)/2;
			int ret = query(mid,S);
			if(ret==S){
				ng = mid;
			}
			else{
				ok = mid;
			}
		}
		ans = ok-1;
		
	}
	else{
		int ok = S,ng = n;
		while(ng-ok>1){
			int mid = (ok+ng)/2;
			int ret = query(S,mid);
			if(ret==S){
				ng = mid;
			}
			else{
				ok = mid;
			}
		}
		ans = ok+1;
	}
	
	answer(ans);
	
	
	
	
    return 0;
}