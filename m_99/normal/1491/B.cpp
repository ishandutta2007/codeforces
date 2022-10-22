#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		long long n,u,v;
		scanf("%lld %lld %lld",&n,&u,&v);
		
		vector<int> a(n);
		rep(i,n){
			scanf("%d",&a[i]);
		}
		int t = 0;
		rep(i,n-1){
			t = max(t,abs(a[i]-a[i+1]));
		}
		int ans;
		if(t>=2)ans = 0;
		else if(t==1)ans = min(u,v);
		else{
			ans = v + min(u,v);
		}
		printf("%d\n",ans);
	}
		
	
    return 0;
}