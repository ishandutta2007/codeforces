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
		
		vector<int> a(n),b(n);
		rep(i,n){
			scanf("%d",&a[i]);
		}
		rep(i,n){
			scanf("%d",&b[i]);
		}
		
		sort(a.rbegin(),a.rend());
		sort(b.rbegin(),b.rend());
		
		int ok = 5*n,ng = n-1;
		while(ok-ng>1){
			
			int mid = (ok+ng)/2;
			int k = mid - (mid/4);
			
			int Sa = 0,Sb = 0;
			int tt = min(k,mid-n);
			Sa += tt*100;
			rep(i,k-tt){
				Sa += a[i];
			}
			rep(i,min(n,k))Sb += b[i];
			if(Sa>=Sb)ok = mid;
			else ng = mid;
		}
		
		printf("%d\n",ok-n);
		
		
	}	
	
	return 0;
}