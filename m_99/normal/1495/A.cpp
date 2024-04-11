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
		
		vector<long long> x,y;
		rep(i,2*n){
			int a,b;
			scanf("%d %d",&a,&b);
			if(a==0)x.push_back(abs(b));
			else y.push_back(abs(a));
		}
		
		sort(x.begin(),x.end());
		sort(y.begin(),y.end());
		
		double ans = 0.0;
		rep(i,n){
			double d = hypot(x[i],y[i]);
			ans += d;
		}
		
		cout<<fixed<<setprecision(12)<<ans<<endl;
		
		
		
	}
	
	
    return 0;
}