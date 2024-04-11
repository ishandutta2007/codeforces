#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001


int main(){
	
	int n,k;
	cin>>n>>k;
	
	vector<int> a(n);
	rep(i,n)scanf("%d",&a[i]);
	
	vector<vector<int>> cnt(200005);
	
	rep(i,n){
		int x = 0;
		while(true){
			cnt[a[i]].push_back(x);
			if(a[i]==0)break;
			a[i]/=2;
			x++;
		}
	}
	int ans = Inf;
	rep(i,cnt.size()){
		if(cnt[i].size()>=k){
			sort(cnt[i].begin(),cnt[i].end());
			int t = 0;
			rep(j,k)t += cnt[i][j];
			ans = min(ans,t);
		}
	}
	
	cout<<ans<<endl;
	
	return 0;
}