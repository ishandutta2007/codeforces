#include <bits/stdc++.h>
#define F first
#define S second
typedef long long ll;
using namespace std;
const int MN = 1e5+100;
vector<pair<ll, ll> > ships;
vector<pair<ll, ll> > bases;
ll ans[MN];
int main() {
	ll s,b;
	cin>>s>>b;
	for(ll i = 0; i < s; ++i) {
		ll a;
		cin>>a;
		ships.push_back({a, i});
	}
	sort(ships.begin(), ships.end());

	for(ll i = 0; i < b; ++i) {
		ll d,g;
		cin>>d>>g;
		bases.push_back({d, g});
	}
	sort(bases.begin(), bases.end());
	ll gold = 0;
	ll base_pos = 0;
	for(int i = 0; i < ships.size(); ++i) {
		while(base_pos < bases.size() && bases[base_pos].F <= ships[i].F){
			gold += bases[base_pos++].S;
		}
		ans[ships[i].S] = gold;
	}
	for(int i = 0; i < s; ++i) {
		cout<<ans[i]<<' ';
	}
	cout<<'\n';

}