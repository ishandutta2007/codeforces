#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
typedef pair<ll,ll> pll;
void read(int& x){ scanf("%d",&x); }
void read(ll& x){ scanf("%lld",&x); }
void read(pp& x){ scanf("%d%d",&x.first, &x.second); }
void read(pll& x){ scanf("%lld%lld",&x.first, &x.second); }
template<typename T,typename... Args>
void read(T& a,Args&... b){ read(a); read(b...); }
void cppio(){ ios_base::sync_with_stdio(0); cin.tie(0); }
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define eb emplace_back
#define x first
#define y second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define sz(x) (int)(x).size()

int m;

ll L, R;

vector<pll> pt;
ll gv;
ll rv;

ll ccw(pll a, pll b, pll c){
	b.x -= a.x; b.y -= a.y;
	c.x -= a.x; c.y -= a.y;

	ll gx = __gcd(abs(b.x), abs(c.x));
	if(gx){
		b.x /= gx; c.x /= gx;
	}

	ll gy = __gcd(abs(b.y), abs(c.y));
	if(gy){
		b.y /= gy; c.y /= gy;
	}

	auto v1 = (long double)(c.y)*b.x;
	auto v2 = c.x*(long double)(b.y);
	if(v1 > v2) return 1;
	if(v1 < v2) return -1;
	return 0;
}

inline ll F(pll p, ll x){ return p.y + p.x*x; }

int main()
{
	cppio();

	cin >> R >> m;

	pt.eb(0, 0);

	rep(qi, m){
		int cmd; cin >> cmd;
		if(cmd == 1){
			ll len;
			cin >> len;
			pt.clear();
			L -= len;
			pt.eb(L, 0);
			gv = 0;
			rv = 0;
		} else if(cmd == 2){
			ll y = - gv * R - rv;
			while(true){
				if(pt.size() < 2u){
					pt.eb(R, y);
					break;
				}
				ll v = ccw(pt[pt.size()-2], pt[pt.size()-1], pll(R, y));
				if(v > 0){
					pt.eb(R, y);
					break;
				} else if(v == 0) break;
				pt.pop_back();
			}
			cin >> y;
			R += y;
		} else {
			ll b, s;
			cin >> b >> s;
			gv += s;
			rv += b - L*s;
			while(pt.size() >= 2u && F(pt[pt.size()-2], gv) <= F(pt[pt.size()-1], gv)) pt.pop_back();
		}

		int p = pt.size()-1;
		while(p-1>=0 && F(pt[p-1], gv) <= F(pt[p], gv)) --p;

		cout << (pt[p].x-L+1) << ' ' << (F(pt.back(), gv)+rv) << '\n';
	}

	return 0;
}