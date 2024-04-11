#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		cin>>n;
		
		vector<int> a(n);
		rep(i,n)scanf("%d",&a[i]);
		
		long long ans = 0LL;
		bool f0 = false,f1 = false;
		for(int i=1;i<n-1;i++){
			ans += a[i]/2;
			if(a[i]%2==0)f0 = true;
			else f1 = true;
			ans += a[i]%2;
		}
		if(f1&&!f0){
			if(n>=4){
				for(int i=1;i<n-1;i++){
					if(a[i]>=3)f0 = true;
				}
			}
			if(f0){
				
			}
			else ans = -1;
		}
		
		printf("%lld\n",ans);
		
		
	}
	
	return 0;
}