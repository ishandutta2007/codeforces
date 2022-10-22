#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf32 1000000001
#define Inf64 4000000000000000001

long long get(vector<long long> &x,vector<long long> &t,long long m){
	long long l = 0,r = Inf32;
	rep(i,x.size()){
		if(t[i] > m)return -1;
		l = max(l,x[i] - (m-t[i]));
		r = min(r,x[i] + (m-t[i]));
	}
	if(l>r)return -1;
	return l;
}

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		cin>>n;
		
		vector<long long> x(n),t(n);
		rep(i,n){
			scanf("%lld",&x[i]);
			x[i]*=2;
		}
		rep(i,n){
			scanf("%lld",&t[i]);
			t[i]*=2;
		}
		long long ok = Inf32,ng = -1;
		while(ok-ng>1LL){
			long long mid = (ok+ng)/2;
			if(get(x,t,mid)==-1)ng = mid;
			else ok = mid;
		}
		double ans = get(x,t,ok);
		ans /= 2.0;
		cout<<fixed<<setprecision(10)<<ans<<endl;
	}
	
	return 0;
}