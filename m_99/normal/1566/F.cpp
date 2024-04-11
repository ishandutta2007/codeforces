#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000000000000

void solve(){
	int n,m;
	scanf("%d %d",&n,&m);
	vector<long long> a(n);
	rep(i,n)scanf("%lld",&a[i]);
	
	sort(a.begin(),a.end());
	
	vector<long long> l,r;
	rep(i,m){
		long long x,y;
		scanf("%lld %lld",&x,&y);
		int d = distance(a.begin(),lower_bound(a.begin(),a.end(),x));
		if(d!=a.size() && a[d]<=y)continue;
		l.push_back(x);
		r.push_back(y);
	}
	
	m = l.size();
	
	vector<pair<int,int>> p(m);
	rep(i,m){
		p[i] = make_pair(r[i],l[i]);
	}
	
	sort(p.begin(),p.end());
	
	{
		vector<pair<int,int>> pp;
		rep(i,m){
			if(pp.size()!=0){
				if(pp.back().second == p[i].first){
					pp.back().first = p[i].second;
					continue;
				}
				else if(pp.back().first>=p[i].second)continue;
			}
			pp.emplace_back(p[i].second,p[i].first);
		}
		p = pp;
		m = p.size();
		l.resize(m),r.resize(m);
		rep(i,m){
			l[i] = p[i].first,r[i] = p[i].second;
		}
	}
	
	
	
	vector<pair<int,bool>> f(n+m);
	rep(i,n){
		f[i] = make_pair(i,true);
	}
	rep(i,m){
		f[n+i] = make_pair(i,false);
	}
	
	sort(f.begin(),f.end(),[&](pair<int,int> x,pair<int,int> y){
		int X,Y;
		if(x.second){
			X = a[x.first];
		}
		else{
			X = l[x.first];
		}
		if(y.second){
			Y = a[y.first];
		}
		else{
			Y = l[y.first];
		}
		return X<Y;
	});
	
	vector<long long> dp(5,Inf);
	dp[0] = 0LL;
	
	rep(i,f.size()){
		vector<long long> ndp(5,Inf);
		if(f[i].second){
			long long x = a[f[i].first];
			
			rep(j,5)ndp[j] = min(ndp[j],dp[j]);
			ndp[1] = min(ndp[1],dp[0] - x);
			ndp[1] = min(ndp[1],dp[4] - x + x*2);
			ndp[2] = min(ndp[2],dp[3] + x - x*2);
			ndp[0] = min(ndp[0],dp[3] + x);
			ndp[0] = min(ndp[0],dp[4] + x*2);
		}
		else{
			rep(j,5){
				if(j!=0)ndp[j] = min(ndp[j],dp[j]);
			}
			long long L = l[f[i].first],R = r[f[i].first];
			ndp[0] = min(ndp[0],dp[1] + L);
			ndp[0] = min(ndp[0],dp[2] + L*2);
			ndp[1] = min(ndp[1],dp[1]);
			ndp[2] = min(ndp[2],dp[2]);
			ndp[3] = min(ndp[3],dp[0] - R);
			ndp[4] = min(ndp[4],dp[0] - R*2);
		}
		swap(dp,ndp);
		/*
		rep(j,5){
			cout<<dp[j]<<',';
		}
		cout<<endl;
		*/
	}
	
	printf("%lld\n",dp[0]);
	
}

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		solve();
	}
	
	return 0;
}