#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

ll dp[202020];

int u[202020];

ll pg[202020];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll d,n,m;
	cin>>d>>n>>m;
	vector<pair<ll, ll> > gs(m);
	for (int i=0;i<m;i++){
		cin>>gs[i].F>>gs[i].S;
	}
	gs.push_back({d, 1e9});
	sort(gs.begin(), gs.end());
	multiset<pair<ll, ll> > has;
	has.insert({0, n});
	ll hassu=n;
	ll x=0;
	ll v=0;
	for (int i=0;i<=m;i++){
		ll di=gs[i].F-x;
		hassu-=di;
		while (di>0){
			if ((int)has.size()==0){
				cout<<"-1"<<endl;
				return 0;
			}
			auto asd=has.begin();
			ll t=min(di, (*asd).S);
			if (t==(*asd).S){
				has.erase(has.find(*asd));
			}
			else{
				has.insert({(*asd).F, (*asd).S-di});
				has.erase(has.find(*asd));
			}
			di-=t;
		}
		x=gs[i].F;
		while ((int)has.size()>0){
			auto asd=has.rbegin();
			if ((*asd).F>=gs[i].S){
				v-=(*asd).F*(*asd).S;
				hassu-=(*asd).S;
				has.erase(has.find(*asd));
			}
			else{
				break;
			}
		}
		has.insert({gs[i].S, n-hassu});
		v+=gs[i].S*(n-hassu);
		hassu=n;
	}
	while ((int)has.size()>0){
		auto asd=has.rbegin();
		v-=(*asd).F*(*asd).S;
		has.erase(has.find(*asd));
	}
	cout<<v<<endl;
}