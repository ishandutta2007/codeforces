#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001

long long sum(long long n){
	long long ret = n;
	ret *= n+1;
	ret /= 2;
	return ret;
}

long long sum(long long l,long long r){
	return sum(r) - sum(l-1);
}

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		cin>>n;
		vector<long long> k(n),h(n);
		rep(i,n)scanf("%lld",&k[i]);
		rep(i,n)scanf("%lld",&h[i]);
		
		vector<pair<long long,long long>> p;
		rep(i,n){
			p.emplace_back(k[i]-h[i],k[i]);
		}
		sort(p.begin(),p.end());
		
		{
			vector<pair<long long,long long>> q;
			rep(i,p.size()){
				if(q.size()==0 || q.back().second <= p[i].first){
					q.push_back(p[i]);
				}
				else{
					q.back().second = max(q.back().second,p[i].second);
				}
			}
			swap(p,q);
		}
		
		long long cur = 0LL;
		long long ans = 0LL;
		
		rep(i,p.size()){
			ans += sum(p[i].second - p[i].first);
		}
		printf("%lld\n",ans);
	}
	
	return 0;
}