#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000000000


int main(){
	
	int _t;
	cin>>_t;
	
	
	rep(_,_t){
		
		int n;
		scanf("%d",&n);
		
		vector<int> a(n);
		rep(i,n){
			scanf("%d",&a[i]);
		}
		
		int PS = 0;
		int ans = n;
		rep(i,n){
			PS += a[i];
			int cur = 0;
			for(int j=i+1;j<n;j++){
				cur += a[j];
				if(cur==PS)cur = 0;
			}
			if(cur==0){
				int S = 0;
				rep(j,n)S += a[j];
				ans = min(ans,n-S/PS);
				break;
			}
		}
		cout<<ans<<endl;
	}
	
	
    return 0;
}