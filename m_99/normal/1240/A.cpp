#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000

int main(){
	
	int _t;
	cin>>_t;
	
	
	rep(_,_t){
		
		int n;
		scanf("%d",&n);
		vector<long long> p(n);
		rep(i,n)scanf("%lld",&p[i]);
		sort(p.rbegin(),p.rend());
		
		long long x,a,y,b;
		scanf("%lld %lld",&x,&a);
		scanf("%lld %lld",&y,&b);
		if(x<y){
			swap(x,y);
			swap(a,b);
		}
		
		long long k;
		scanf("%lld",&k);
		
		long long ng = 0,ok = n+1;
		while(ok-ng>1){
			long long mid = (ok+ng)/2;
			
			long long XY = mid / lcm(a,b);
			long long X = mid/a - XY;
			long long Y = mid/b - XY;
			
			long long sum = 0LL;
			rep(i,n){
				if(i<XY)sum += p[i]/100 * (x+y);
				else if(i<XY+X)sum += p[i]/100 * x;
				else if(i<XY+X+Y)sum += p[i]/100*y;
			}
			if(sum >= k)ok = mid;
			else ng = mid;
			
		}
		if(ok==n+1)printf("-1\n");
		else printf("%d\n",ok);
		
	}
	
    return 0;
}