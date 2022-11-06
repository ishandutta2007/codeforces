#include <bits/stdc++.h>
#include <complex>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define MOD 1000000007LL
#define PB push_back
#define MP make_pair
#define INF 9223372036854775807LL
#define UNDEF -1
typedef pair<ll,ll> pt;
struct cmpa {
	bool operator() (pt p, pt q) {
	return (p.second > q.second) || (p.second == q.second && p.first < q.first);
	}
};
struct cmpb {
	bool operator() (pt p, pt q) {
	return (p.second > q.second) || (p.second == q.second && p.first > q.first);
	}
};
struct cmpc {
	bool operator() (pt p, pt q) {
	return (p.first > q.first) || (p.first == q.first && p.second > q.second);
	}
};
struct cmpd {
	bool operator() (pt p, pt q) {
	return (p.first > q.first) || (p.first == q.first && p.second < q.second);
	}
};
struct cmpe {
	bool operator() (pt p, pt q) {
	return (p.second < q.second) || (p.second == q.second && p.first > q.first);
	}
};
struct cmpf {
	bool operator() (pt p, pt q) {
	return (p.second < q.second) || (p.second == q.second && p.first < q.first);
	}
};
struct cmpg {
	bool operator() (pt p, pt q) {
	return (p.first < q.first) || (p.first == q.first && p.second < q.second);
	}
};
struct cmph {
	bool operator() (pt p, pt q) {
	return (p.first < q.first) || (p.first == q.first && p.second > q.second);
	}
};
multiset<pt, cmpa> sa;
multiset<pt, cmpb> sb;
multiset<pt, cmpc> sc;
multiset<pt, cmpd> sd;
multiset<pt, cmpe> se;
multiset<pt, cmpf> sf;
multiset<pt, cmpg> sg;
multiset<pt, cmph> sh;
pt va[10];
pt vb[10];
pt vc[10];
pt vd[10];
pt ve[10];
pt vf[10];
pt vg[10];
pt vh[10];
void remove(pt p) {
{auto it = sa.find(p); sa.erase(it);}
{auto it = sb.find(p); sb.erase(it);}
{auto it = sc.find(p); sc.erase(it);}
{auto it = sd.find(p); sd.erase(it);}
{auto it = se.find(p); se.erase(it);}
{auto it = sf.find(p); sf.erase(it);}
{auto it = sg.find(p); sg.erase(it);}
{auto it = sh.find(p); sh.erase(it);}

}
void addback(pt p) {
sa.insert(p);
sb.insert(p);
sc.insert(p);
sd.insert(p);
se.insert(p);
sf.insert(p);
sg.insert(p);
sh.insert(p);
}
int main() {
	ios_base::sync_with_stdio(false);
	ll n,k; cin >> n; cin >> k;
	for (ll i = 0; i < n; i++) {
		ll x1,x2,y1,y2;
		cin >> x1; cin >> y1; cin >> x2; cin >> y2;
		ll x = x1+x2;
		ll y = y1+y2;
		pt p = MP(x,y);
		sa.insert(p);
		sb.insert(p);
		sc.insert(p);
		sd.insert(p);
		se.insert(p);
		sf.insert(p);
		sg.insert(p);
		sh.insert(p);
	}
ll ans = INF;





for (ll a = 0; a <= k; a++) {
for (ll i = 0; i < a; i++) {
va[i] = *(sa.begin());
remove(va[i]);
}
ll ca = a;
for (ll b = 0; b <= k-ca; b++) {
for (ll i = 0; i < b; i++) {
vb[i] = *(sb.begin());
remove(vb[i]);
}
ll cb = ca + b;
for (ll c = 0; c <= k-cb; c++) {
for (ll i = 0; i < c; i++) {
vc[i] = *(sc.begin());
remove(vc[i]);
}
ll cc = cb + c;
for (ll d = 0; d <= k-cc; d++) {
for (ll i = 0; i < d; i++) {
vd[i] = *(sd.begin());
remove(vd[i]);
}
ll cd = cc + d;
for (ll e = 0; e <= k-cd; e++) {
for (ll i = 0; i < e; i++) {
ve[i] = *(se.begin());
remove(ve[i]);
}
ll ce = cd + e;
for (ll f = 0; f <= k-ce; f++) {
for (ll i = 0; i < f; i++) {
vf[i] = *(sf.begin());
remove(vf[i]);
}
ll cf = ce + f;
for (ll g = 0; g <= k-cf; g++) {
for (ll i = 0; i < g; i++) {
vg[i] = *(sg.begin());
remove(vg[i]);
}
ll cg = cf + g;
for (ll h = 0; h <= k-cg; h++) {
for (ll i = 0; i < h; i++) {
vh[i] = *(sh.begin());
remove(vh[i]);
}
ll ch = cg + h;

ll maxx = sc.begin()->first;
ll minx = sc.rbegin()->first;
ll maxy = sa.begin()->second;
ll miny = sa.rbegin()->second;
ll dx = max((maxx-minx+1)/2, 1LL);
ll dy = max((maxy-miny+1)/2, 1LL);
ll cand = dx * dy;
ans = min(ans, cand);

for (ll i = 0; i < h; i++) {
addback(vh[i]);
}
}
for (ll i = 0; i < g; i++) {
addback(vg[i]);
}
}
for (ll i = 0; i < f; i++) {
addback(vf[i]);
}
}
for (ll i = 0; i < e; i++) {
addback(ve[i]);
}
}
for (ll i = 0; i < d; i++) {
addback(vd[i]);
}
}
for (ll i = 0; i < c; i++) {
addback(vc[i]);
}
}
for (ll i = 0; i < b; i++) {
addback(vb[i]);
}
}
for (ll i = 0; i < a; i++) {
addback(va[i]);
}
}






cout << ans << endl;

}