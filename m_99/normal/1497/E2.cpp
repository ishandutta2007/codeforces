#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001
const int sz = 10000001;
int minp[sz];

long long get_hash(long long p){
	p <<= 15;
	p *= 107;
	p -= 33;
	return p;
}

int main(){
	
	for(int i=2;i<sz;i++){
		if(minp[i]!=0)continue;
		for(int j=i;j<sz;j+=i){
			minp[j] = i;
		}
	}
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n,k;
		scanf("%d %d",&n,&k);
		
		vector<int> a(n);
		rep(i,n){
			scanf("%d",&a[i]);
		}
		
		vector<long long> hash(n);

		rep(i,n){
			long long cur = 0LL;
			while(a[i]!=1){
				int p = minp[a[i]];
				cur ^= get_hash(p);
				a[i] /= p;
			}
			hash[i] = cur;
		}
		
		vector pre(n,vector<int>(k+1,-1));
		{
			map<long long,int> mp;
			rep(i,n){
				if(mp.count(hash[i])){
					pre[i][0] = mp[hash[i]];
				}
				mp[hash[i]] = i;
			}
		}
		
		rep(i,n){
			if(i==0)continue;
			int t = pre[i][0];
			pre[i] = pre[i-1];
			if(t!=-1){
				rep(j,k+1){
					if(pre[i][j]<t){
						pre[i].insert(pre[i].begin()+j,t);
						break;
					}
				}
				if(pre[i].size()>k+1)pre[i].pop_back();
			}
		}
		/*
		rep(i,n){
			rep(j,k+1){
				cout<<pre[i][j]<<',';
			}
			cout<<endl;
		}
		*/
		
		vector<vector<int>> dp(n,vector<int>(k+1,Inf));
		rep(i,n){
			if(i==0){
				rep(j,k+1)dp[i][j] = 1;
			}
			else{
				rep(j,k+1){
					rep(x,j+1){
						int t = pre[i][x];
						int v = 1;
						if(t!=-1){
							v = dp[t][j-x] + 1;
						}
						dp[i][j] = min(dp[i][j],v);
					}
				}
				
			}
		}
		
		int ans = Inf;
		rep(i,k+1)ans  =min(ans,dp.back()[i]);
		
		printf("%d\n",ans);
	}
	
    return 0;
}