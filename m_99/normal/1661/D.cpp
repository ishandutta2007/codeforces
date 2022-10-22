#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001


int main(){
	
	int _t;
	//cin>>_t;
	_t = 1;
	rep(_,_t){
		int n;
		scanf("%d",&n);
		long long k;
		scanf("%lld",&k);
		vector<long long> b(n);
		rep(i,n)scanf("%lld",&b[i]);
		vector<long long> a(n,0);
		vector<long long> c(n,0);
		long long cc = 0,cs = 0;
		long long ans = 0;
		for(int i=n-1;i>=0;i--){
			cs -= cc;
			cc -= c[i];
			
			a[i] = cs;
			long long need = max(0LL,b[i] - a[i]);
			if(i>=k){
				need = (need+k-1)/k;
				a[i] += need * k;
				cc += need;
				cs += need*k;
				c[i-k] += need;
				ans += need;
			}
			else{
				need = (need+i+1-1)/(i+1);
				a[i] += need * (i+1);
				cc += need;
				cs += need*(i+1);
				ans += need;
			}
		}
		/*
		rep(i,n){
			cout<<a[i]<<endl;
		}*/
		printf("%lld\n",ans);
			
			
		
	}
	
	
	return 0;
}