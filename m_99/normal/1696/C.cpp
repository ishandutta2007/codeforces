#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

vector<pair<long long,long long>> get(vector<pair<long long,long long>> a,long long m){
	
	vector<pair<long long,long long>> ret;
	rep(i,a.size()){
		long long cv = a[i].first;
		long long cc = a[i].second;
		while(cv%m==0){
			cv /= m;
			cc *= m;
		}
		if(ret.size()>0&&ret.back().first==cv)ret.back().second += cc;
		else ret.emplace_back(cv,cc);
	}
	return ret;
	
}

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		long long n,m;
		cin>>n>>m;
		vector<pair<long long,long long>> a(n);
		rep(i,n){
			scanf("%lld",&a[i].first);
			a[i].second = 1;
		}
		int k;
		cin>>k;
		vector<pair<long long,long long>> b(k);
		rep(i,k){
			scanf("%lld",&b[i].first);
			b[i].second = 1;
		}
		a = get(a,m);
		b = get(b,m);
		if(a==b)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
		
	}
	
    return 0;
}