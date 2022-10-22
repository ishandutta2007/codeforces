#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf32 1000000001
#define Inf64 4000000000000000001



int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		int n;
		cin>>n;
		vector<long long> x(n),y(n);
		rep(i,n)scanf("%lld",&x[i]);
		rep(i,n)scanf("%lld",&y[i]);
		vector<long long> v(n);
		rep(i,n){
			v[i] = y[i]-x[i];
		}
		sort(v.rbegin(),v.rend());
		int ok = 0,ng = n/2 + 1;
		while(ng-ok>1){
			int mid = (ok+ng)/2;
			bool f = true;
			rep(i,mid){
				if(v[i] + v[2*mid-1-i] < 0){
					f = false;
					break;
				}
			}
			if(f)ok = mid;
			else ng = mid;
		}
		cout<<ok<<endl;
	}
	
	return 0;
}