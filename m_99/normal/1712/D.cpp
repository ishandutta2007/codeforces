#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

int main() {
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n,k;
		cin>>n>>k;
		
		vector<long long> a(n);
		rep(i,n)cin>>a[i];
		int ok = 0,ng = Inf;
		while(ng-ok>1){
			int mid = (ok+ng)/2;
			int c = 0;
			for(int i=2;i<n;i++){
				if(a[i]*2 < mid)c++;
			}
			bool f = false;
			rep(i,n-1){
				int ss = 0;
				ss = c;
				if(a[i]<mid)ss++;
				if(a[i+1]<mid)ss++;
				if(ss <= k){
					f = true;
					break;
				}
				if(a[i]*2<mid)c++;
				if(i+2<n&&a[i+2]*2<mid)c--;
			}
			if(f)ok = mid;
			else ng = mid;
		}
		
		cout<<ok<<endl;
	}
	
    return 0;
}