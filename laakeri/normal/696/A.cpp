#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

map<ll, ll> c;

void add(ll u, ll v, ll w) {
	while (u!=v){
		if (u>v) {
			c[u]+=w;
			u/=2ll;
		}
		else {
			c[v]+=w;
			v/=2ll;
		}
	}
}

ll get(ll u, ll v) {
	ll r=0;
	while (u!=v){
		if (u>v) {
			r+=c[u];
			u/=2ll;
		}
		else {
			r+=c[v];
			v/=2ll;
		}
	}
	return r;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int q;
	cin>>q;
	for (int qq=0;qq<q;qq++){
		int t;
		cin>>t;
		if (t==1){
			ll v,u,w;
			cin>>v>>u>>w;
			add(v, u, w);
		}
		else{
			ll u,v;
			cin>>u>>v;
			cout<<get(u, v)<<'\n';
		}
	}
}