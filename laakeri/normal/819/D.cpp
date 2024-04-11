#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

ll v[202020];

ll ee(ll a, ll b, ll ca, ll cb, ll xa, ll xb, ll&x, ll&y) {
	if (cb==0) {
		x=xa;
		if (b==0) y=0;
		else y=(ca-a*xa)/b;
		return ca;
	}
	else return ee(a, b, cb, ca%cb, xb, xa-(ca/cb)*xb, x, y);
}
pair<int, pair<ll, ll> > solved(ll a, ll b, ll c) {
	if (c==0) return {1, {0, 0}};
	if (a==0&&b==0) return {0, {0, 0}};
	ll x,y;
	ll g=ee(a, b, a, b, 1, 0, x, y);
	if (abs(c)%g>0) return {0, {0, 0}};
	return {1, {x*(c/g), y*(c/g)}};
}

void solve(vector<pair<ll, int> > a, ll S, ll T){
	for (auto& x:a){
		auto sol=solved(S, T, x.F);
		assert(sol.F==1);
		ll id=sol.S.F%T;
		if (id<0) id+=T;
		x.F=id;
	}
	sort(a.begin(), a.end());
	for (int i=0;i<(int)a.size();i++){
		if (i+1<(int)a.size()){
			assert(a[i].F<a[i+1].F);
			v[a[i].S]=a[i+1].F-a[i].F;
		}
		else{
			v[a[i].S]=T-a[i].F+a[0].F;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll T;
	int n;
	cin>>T>>n;
	ll S=0;
	vector<pair<ll, int> > a;
	set<ll> u;
	ll lol;
	cin>>lol;
	for (int i=0;i<n;i++){
		if (u.count(S)==0){
			a.push_back({S, i});
			u.insert(S);
		}
		if (i+1<n){
			int x;
			cin>>x;
			S+=(ll)x;
			S%=T;
		}
	}
	S+=lol;
	S%=T;
	if (S==0){
		for (auto t:a){
			v[t.S]=1;
		}
	}
	else{
		ll g=__gcd(S, T);
		map<ll, vector<pair<ll, int> > > sb;
		for (auto x:a){
			sb[x.F%g].push_back({x.F/g, x.S});
		}
		for (auto t:sb){
			solve(t.S, S/g, T/g);
		}
	}
	for (int i=0;i<n;i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
}