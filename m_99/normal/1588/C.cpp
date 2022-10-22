#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

vector<long long> a,b;
int n;
long long ans = 0LL;

void dfs(int l,int r){
	if(r-l==0)return;
	if(r-l==1){
		if(a[l]==0)ans++;
		return;
	}
	//if(r-l<=1)return;
	int m = (l+r)/2;
	
	vector<long long> cur(2,0);
	vector<long long> mini(2,0);
	map<vector<long long>,int> mp;
	for(int i=m;i>=l;i--){
		
		auto temp = cur;
		temp[i%2] -= b[i];
		temp[i%2] += a[i];
		auto mm = mini;
		mm[i%2] = min(a[i],mm[i%2]+a[i]);
		if(mm[0]>=0&&mm[1]>=0){
			mp[temp]++;
		}
		if(i!=m){
			mini[i%2] = min({0LL,mini[i%2]+b[i],b[i]});
		}
		if(i!=l){
			cur[(i-1)%2] += b[i-1];
		}
	}
	
	cur.assign(2,0);
	mini.assign(2,0);
	for(int i=m;i<r;i++){
		cur[i%2] += b[i];
		auto temp = cur;
		temp[(i+1)%2] -= a[i];
		
		if(temp[0]<=0&&temp[1]<=0){
			if(mini[0]>=temp[0]&&mini[1]>=temp[1]){
				rep(j,2)temp[j] *= -1;
				if(mp.count(temp)){
					//cout<<l<<','<<r<<','<<mp[temp]<<endl;
					ans += mp[temp];
				}
			}
		}
		rep(j,2){
			mini[j] = min(mini[j],cur[j]);
		}
	}
	dfs(l,m);
	dfs(m+1,r);
}

int main(){

	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		scanf("%d",&n);
		a.resize(n);
		rep(i,n)scanf("%lld",&a[i]);
		a.insert(a.begin(),0LL);
		b.assign(n+1,0LL);
		for(int i=1;i<=n;i++){
			b[i] = a[i] - a[i-1];
		}
		
		ans = 0;
		dfs(1,n+1);
		/*
		map<vector<long long>,int> mp;
		
		
		for(int i=1;i<=n;i++){
			auto tt = sum;
			sum[i%2] += b[i];
			auto temp = sum;
			temp[(i%2)^1] -= a[i];
			
			if(mp.count(temp))ans += mp[temp];
			
			tt[i%2] += b[i];
			tt[i%2] -= a[i];
			mp[tt]++;
		}
		*/
		printf("%lld\n",ans);
	}
	
	return 0;
}