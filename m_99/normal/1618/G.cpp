#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001


int main(){
	
	int n,m,q;
	cin>>n>>m>>q;
	
	vector<pair<long long,int>> a(n+m);
	long long cur = 0;
	rep(i,n+m){
		long long t;
		scanf("%lld",&t);
		a[i] = make_pair(t,i);
		if(i<n)cur += t;
	}
	
	sort(a.begin(),a.end());
	
	vector<int> s(n+m+1,0);
	rep(i,n+m){
		if(a[i].second<n){
			s[i+1] = 1;
		}
		s[i+1] += s[i];
	}
	vector<long long> sum(n+m+1,0);
	rep(i,n+m){
		sum[i+1] = a[i].first;
		sum[i+1] += sum[i];
	}
	
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> Q;
	rep(i,n+m-1){
		Q.emplace(a[i+1].first-a[i].first,i+1);
	}
	
	vector<pair<int,int>> k(q);
	rep(i,q){
		scanf("%d",&k[i].first);
		k[i].second = i;
	}
	sort(k.begin(),k.end());
	vector<long long> ans(q);
	set<int> S;
	rep(i,n+m+1){
		S.emplace_hint(S.end(),i);
	}
	rep(i,q){
		int K = k[i].first,ind = k[i].second;
		while(Q.size()!=0 && Q.top().first <= K){
			int ii = Q.top().second;
			Q.pop();
			auto it = S.lower_bound(ii);
			int m1 = *it;
			it++;
			int m2 = *it;
			it--;
			it--;
			int m0 = *it;
			it++;
			S.erase(it);
			
			int c1 = s[m2] - s[m1];
			int c0 = s[m1] - s[m0];
			cur -= sum[m1] - sum[m1-c0];
			cur -= sum[m2] - sum[m2-c1];
			cur += sum[m2] - sum[m2-(c0+c1)];
		}
		ans[ind] = cur;
		
	}
	rep(i,q){
		printf("%lld\n",ans[i]);
	}
	
	return 0;
}