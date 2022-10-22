#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000300


int main(){	
	
	int n,m;
	cin>>n>>m;
	
	vector<int> a(n),b(n);
	vector<int> c(m),d(m);
	
	rep(i,n){
		scanf("%d %d",&a[i],&b[i]);
	}
	
	rep(i,m){
		scanf("%d %d",&c[i],&d[i]);
	}
	
	vector<int> maxi(1000006,0);
	
	rep(i,n){
		rep(j,m){
			if(a[i]<=c[j]){
				maxi[c[j]-a[i]] = max(maxi[c[j]-a[i]],d[j]+1 - b[i]);
			}
		}
	}
	
	for(int i=1000004;i>=0;i--){
		maxi[i] = max(maxi[i],maxi[i+1]);
	}
	
	int ans = Inf;
	rep(i,maxi.size()){
		ans = min(ans,maxi[i] + i);
	}
	
	cout<<ans<<endl;
	
    return 0;
}