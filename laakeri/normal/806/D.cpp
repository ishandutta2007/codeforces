#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

ll mc[2020];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	vector<pair<ll, pair<int, int> > > es;
	for (int i=1;i<=n;i++){
		for (int j=i+1;j<=n;j++){
			ll x;
			cin>>x;
			es.push_back({x, {i, j}});
		}
		mc[i]=1e18;
	}
	sort(es.begin(), es.end());
	ll mi=es[0].F;
	for (auto e:es){
		ll c=e.F;
		int a=e.S.F;
		int b=e.S.S;
		ll bc=c*2+mi*(ll)(n-3);
		ll c1=mc[b]-mi+c;
		ll c2=mc[a]-mi+c;
		c1=min(c1, bc);
		c2=min(c2, bc);
		mc[a]=min(mc[a], c1);
		mc[b]=min(mc[b], c2);
	}
	for (int i=1;i<=n;i++){
		cout<<mc[i]<<'\n';
	}
}