#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000

long long a,b,c,d;

long long Get(long long a0,long long n,long long d){
	long long ret = a0*n;
	ret += d*(n * (n-1) / 2);
	return ret;
}

long long get(long long x){
	long long ret = a*x;
	ret -= b*c*x;
	ret += Get(c,min(x,c/d+1),-d) * b;
	return ret;
}

int main(){
	
	int t;
	cin>>t;
	
	rep(_,t){
		
		scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
		
		if(a>b*c){
			printf("-1\n");
			continue;
		}
		
	//	cout<<get(1)<<','<<get(2)<<endl;
		
		long long ok = 1,ng = 1000005;
		while(ng-ok>3){
			long long l0 = (ng-ok)/3;
			long long l1 = l0*2;
			l0 += ok;
			l1 += ok;
			
			if(get(l0)<get(l1))ok = l0;
			else ng = l1;
		}
		long long ans = 0LL;
		for(long long i=ok;i<=ng;i++){
			ans = max(ans,get(i));
		}
		
		printf("%lld\n",ans);
	}
	
    return 0;
}