#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000000000000

long long get(long long a,long long k){
	if(a<k)return Inf;
	
	long long x = a/k;
	long long y = x+1;
	long long cy = a%k;
	long long cx = (k-cy);
	
	return x*x*cx + y*y*cy;
	
}

int main(){	
	
	int n,k;
	cin>>n>>k;
	
	vector<long long> a(n);
	long long ans = 0LL;
	rep(i,n){
		scanf("%lld",&a[i]);
		
		ans += a[i]*a[i];
	}
	
	priority_queue<pair<long long,pair<int,int>>> Q;
	
	rep(i,n){
		Q.emplace(get(a[i],1)-get(a[i],2),make_pair(a[i],1));
	}
	
	rep(i,k-n){
		auto p = Q.top();
		Q.pop();
		//cout<<p.first<<endl;
		ans -= p.first;
		
		p.second.second ++;
		p.first = get(p.second.first,p.second.second)-get(p.second.first,p.second.second+1);
		Q.push(p);
	}
	
	cout<<ans<<endl;
	
    return 0;
}