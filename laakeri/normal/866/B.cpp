#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

ll get(vector<pair<ll, ll> > ap, vector<pair<ll, ll> > bp, ll sa, ll sb){
	sort(ap.rbegin(), ap.rend());
	sort(bp.rbegin(), bp.rend());
	ll v=0;
	for (auto t:ap){
		ll e=min(sa, t.S);
		v+=e*t.F;
		sa-=e;
	}
	for (auto t:bp){
		ll e=min(sb, t.S);
		v+=e*t.F;
		sb-=e;
	}
	return v;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll v=0;
	int n;
	ll s;
	cin>>n>>s;
	ll ta=0;
	ll tb=0;
	vector<pair<ll, ll> > ap,bp;
	for (int i=0;i<n;i++){
		ll ss,aa,bb;
		cin>>ss>>aa>>bb;
		v+=min(aa, bb)*ss;
		if (aa>bb) {
			ta+=ss;
			ap.push_back({aa-bb, ss});
		}
		else {
			tb+=ss;
			bp.push_back({bb-aa, ss});
		}
	}
	ll pz=(ta+tb)/s+((ta+tb)%s>0);
	ll pza=ta/s;
	ll be=0;
	for (ll i=pza-3;i<=pza+3;i++){
		if (i<0||i>pz) continue;
		be=max(be, get(ap, bp, i*s, (pz-i)*s));
	}
	cout<<v+be<<endl;
}