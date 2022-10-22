#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000000000000


vector<vector<int>> E;
vector<long long> a;
vector<long long> asum,cnt;
void dfs(int now){
	
	if(E[now].size()==0){
		cnt[now] = 1;
	}
	else{
		rep(i,E[now].size()){
			int to = E[now][i];
			dfs(to);
			asum[now] += asum[to];
			cnt[now] += cnt[to];
		}
	}
	asum[now] += a[now];
}
	


int main(){	
	
	int n;
	cin>>n;
	
	E.resize(n,vector<int>());
	
	rep(i,n-1){
		int p;
		scanf("%d",&p);
		p--;
		E[p].push_back(i+1);
	}
	a.resize(n);
	rep(i,n){
		scanf("%lld",&a[i]);
	}
	
	asum.resize(n,0);
	cnt.resize(n,0);
	
	dfs(0);
	
	long long ans = 0LL;
	
	rep(i,n){
		ans = max(ans,(asum[i]+cnt[i]-1)/cnt[i]);
	}
	
	cout<<ans<<endl;
	
    return 0;
}