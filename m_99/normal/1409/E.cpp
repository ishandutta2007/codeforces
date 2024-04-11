#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000300



int main(){
	
	int t;
	cin>>t;
	
	rep(_,t){
		int n,k;
		scanf("%d %d",&n,&k);
		vector<int> x(n);
		rep(i,n){
			scanf("%d",&x[i]);
		}
		
		rep(i,n){
			int t;
			scanf("%d",&t);
		}
		
		sort(x.begin(),x.end());
		
		vector<int> cnt1(n,0);
		rep(i,n){
			cnt1[i] = 1+distance(lower_bound(x.begin(),x.end(),x[i]-k),x.begin()+i);
		}
		vector<int> cnt2(n,0);
		rep(i,n){
			cnt2[i] = distance(x.begin()+i,upper_bound(x.begin(),x.end(),x[i]+k));
		}
		
		for(int i=1;i<n;i++){
			cnt1[i] = max(cnt1[i],cnt1[i-1]);
			cnt2[n-1-i] = max(cnt2[n-1-i],cnt2[n-1-i+1]);
		}
		
		int ans = 1;
		rep(i,n-1){
			ans = max(ans,cnt1[i]+cnt2[i+1]);
		}
		
		printf("%d\n",ans);
		
	}
	
    return 0;
}