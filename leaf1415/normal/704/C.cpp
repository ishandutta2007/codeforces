#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <algorithm>
#include <utility>
#include <complex>
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define per(x, s, t) for(llint (x) = (s); (x) >= (t); (x)--)
#define reps(x, s) for(llint (x) = 0; (x) < (llint)(s).size(); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define sz(x) ((ll)(x).size())
#define ceil(x, y) (((x)+(y)-1) / (y))
#define all(x) (x).begin(),(x).end()
#define outl(...) dump_func(__VA_ARGS__)
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<ll, ll> P;

struct edge{
	ll to, cost, id;
	edge(){}
	edge(ll a, ll b, ll c){ to = a, cost = b, id = c;}
};
const ll dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};

const ll mod = 1000000007;
//const ll mod = 998244353;

struct mint{
	ll x = 0;
	mint(ll y = 0){x = y; if(x < 0 || x >= mod) x = (x%mod+mod)%mod;}
	mint(const mint &ope) {x = ope.x;}
	
	mint operator-(){return mint(-x);}
	mint operator+(const mint &ope){return mint(x) += ope;}
	mint operator-(const mint &ope){return mint(x) -= ope;}
	mint operator*(const mint &ope){return mint(x) *= ope;}
	mint operator/(const mint &ope){return mint(x) /= ope;}
	mint& operator+=(const mint &ope){
		x += ope.x;
		if(x >= mod) x -= mod;
		return *this;
	}
	mint& operator-=(const mint &ope){
		x += mod - ope.x;
		if(x >= mod) x -= mod;
		return *this;
	}
	mint& operator*=(const mint &ope){
		x *= ope.x, x %= mod;
		return *this;
	}
	mint& operator/=(const mint &ope){
		ll n = mod-2; mint mul = ope;
		while(n){
			if(n & 1) *this *= mul;
			mul *= mul;
			n >>= 1;
		}
		return *this;
	}
	mint inverse(){return mint(1) / *this;}
	bool operator ==(const mint &ope){return x == ope.x;}
	bool operator !=(const mint &ope){return x != ope.x;}
};
mint modpow(mint a, ll n){
	if(n == 0) return mint(1);
	if(n % 2) return a * modpow(a, n-1);
	else return modpow(a*a, n/2);
}
istream& operator >>(istream &is, mint &ope){
	ll t; is >> t, ope.x = t;
	return is;
}
ostream& operator <<(ostream &os, mint &ope){return os << ope.x;}
ostream& operator <<(ostream &os, const mint &ope){return os << ope.x;}

bool exceed(ll x, ll y, ll m){return x >= m / y + 1;}
void mark(){ cout << "*" << endl; }
void yes(){ cout << "YES" << endl; }
void no(){ cout << "NO" << endl; }
ll sgn(ll x){ if(x > 0) return 1; if(x < 0) return -1; return 0;}
ll gcd(ll a, ll b){if(b == 0) return a; return gcd(b, a%b);}
ll lcm(ll a, ll b){return a/gcd(a, b)*b;}
ll digitnum(ll x, ll b = 10){ll ret = 0; for(; x; x /= b) ret++; return ret;}
ll digitsum(ll x, ll b = 10){ll ret = 0; for(; x; x /= b) ret += x % b; return ret;}
string lltos(ll x){string ret; for(;x;x/=10) ret += x % 10 + '0'; reverse(ret.begin(), ret.end()); return ret;}
ll stoll(string &s){ll ret = 0; for(auto c : s) ret *= 10, ret += c - '0'; return ret;}
template<typename T>
void uniq(T &vec){ sort(vec.begin(), vec.end()); vec.erase(unique(vec.begin(), vec.end()), vec.end());}

template<typename T>
ostream& operator << (ostream& os, vector<T>& vec) {
	for(int i = 0; i < vec.size(); i++) os << vec[i] << (i + 1 == vec.size() ? "" : " ");
	return os;
}
template<typename T>
ostream& operator << (ostream& os, deque<T>& deq) {
	for(int i = 0; i < deq.size(); i++) os << deq[i] << (i + 1 == deq.size() ? "" : " ");
	return os;
}
template<typename T, typename U>
ostream& operator << (ostream& os, pair<T, U>& pair_var) {
	os << "(" << pair_var.first << ", " << pair_var.second << ")";
	return os;
}
template<typename T, typename U>
ostream& operator << (ostream& os, const pair<T, U>& pair_var) {
	os << "(" << pair_var.first << ", " << pair_var.second << ")";
	return os;
}
template<typename T, typename U>
ostream& operator << (ostream& os, map<T, U>& map_var) {
	for(typename map<T, U>::iterator itr = map_var.begin(); itr != map_var.end(); itr++) {
		os << "(" << itr->first << ", " << itr->second << ")";
		itr++; if(itr != map_var.end()) os << ","; itr--;
	}
	return os;
}
template<typename T>
ostream& operator << (ostream& os, set<T>& set_var) {
	for(typename set<T>::iterator itr = set_var.begin(); itr != set_var.end(); itr++) {
		os << *itr; ++itr; if(itr != set_var.end()) os << " "; itr--;
	}
	return os;
}
template<typename T>
ostream& operator << (ostream& os, multiset<T>& set_var) {
	for(typename multiset<T>::iterator itr = set_var.begin(); itr != set_var.end(); itr++) {
		os << *itr; ++itr; if(itr != set_var.end()) os << " "; itr--;
	}
	return os;
}
template<typename T>
void outa(T a[], ll s, ll t){
	for(ll i = s; i <= t; i++){ cout << a[i]; if(i < t) cout << " ";}
	cout << endl;
}
void dump_func() {cout << endl;}
template <class Head, class... Tail>
void dump_func(Head &&head, Tail &&... tail) {
	cout << head;
	if(sizeof...(Tail) > 0) cout << " ";
	dump_func(std::move(tail)...);
}


typedef pair<mint, mint> MP;

ll n, m;
vector<edge> G[100005];
ll cnt[100005][2];
bool used[100005];
mint dp[100005][2][2], dp2[100005][2];
vector<MP> vec;

vector<ll> vvec, evec;
void dfs(int v, int eid)
{
	used[v] = true;
	vvec.push_back(v);
	for(auto e : G[v]){
		ll u = e.to, c = e.cost, id = e.id;
		if(id == eid) continue;
		if(!used[u]){
			evec.push_back(c);
			dfs(u, id);
			return;
		}
	}
	for(auto e : G[v]){
		ll u = e.to, c = e.cost, id = e.id;
		if(id == eid) continue;
		vvec.push_back(u);
		evec.push_back(c);
		return;
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	ll k, u, v;
	rep(i, 1, n){
		cin >> k;
		if(k == 1){
			cin >> v;
			if(v > 0) cnt[abs(v)][0] ^= 1;
			else cnt[abs(v)][1] ^= 1;
		}
		else{
			cin >> u >> v;
			if(u == v){
				if(u > 0) cnt[abs(v)][0] ^= 1;
				else cnt[abs(v)][1] ^= 1;
				continue;
			}
			if(u == -v){
				cnt[abs(v)][0] ^= 1, cnt[abs(v)][1] ^= 1;
				continue;
			}
			
			ll a = 0, b = 0;
			if(u < 0) a = 1; if(v < 0) b = 1;
			u = abs(u), v = abs(v);
			G[u].push_back(edge(v, b*2+a, i));
			G[v].push_back(edge(u, a*2+b, i));
		}
	}
	
	rep(i, 1, m){
		if(used[i] || sz(G[i]) >= 2) continue;
		if(sz(G[i]) == 0){
			used[i] = true;
			MP p = MP(mint(0), mint(0));
			rep(b, 0, 1){
				if(cnt[i][b]) p.second += mint(1);
				else p.first += mint(1);
			}
			vec.push_back(p);
			continue;
		}
		vvec.clear(), evec.clear();
		dfs(i, -1);
		
		ll N = sz(evec);
		rep(j, 0, N) rep(k, 0, 1) rep(l, 0, 1) dp[j][k][l] = mint(0);
		dp[0][cnt[vvec[0]][0]][0] += mint(1), dp[0][cnt[vvec[0]][1]][1] += mint(1);
		
		//outl(vvec), outl(evec);
		rep(j, 0, N-1){
			ll v = vvec[j+1], e = evec[j];
			rep(k, 0, 1){
				rep(l, 0, 1){
					rep(m, 0, 1){
						ll nk = k^cnt[v][m];
						if(l == (e&1) || m == (e>>1)) dp[j+1][nk^1][m] += dp[j][k][l];
						else dp[j+1][nk][m] += dp[j][k][l];
					}
				}
			}
		}
		vec.push_back(MP(dp[N][0][0]+dp[N][0][1], dp[N][1][0]+dp[N][1][1]));
	}
	
	rep(i, 1, m){
		if(used[i]) continue;
		vvec.clear(), evec.clear();
		dfs(i, -1);
		
		ll N = sz(evec); MP p = MP(mint(0), mint(0));
		rep(b, 0, 1){
			rep(j, 0, N) rep(k, 0, 1) rep(l, 0, 1) dp[j][k][l] = mint(0);
			dp[0][cnt[vvec[0]][b]][b] = mint(1);
			
			rep(j, 0, N-1){
				ll v = vvec[j+1], e = evec[j];
				rep(k, 0, 1){
					rep(l, 0, 1){
						rep(m, 0, 1){
							if(j == N-1 && m != b) continue;
							ll nk = k^cnt[v][m];
							if(j == N-1) nk = k;
							if(l == (e&1) || m == (e>>1)) dp[j+1][nk^1][m] += dp[j][k][l];
							else dp[j+1][nk][m] += dp[j][k][l];
						}
					}
				}
			}
			p.first += dp[N][0][0]+dp[N][0][1];
			p.second += dp[N][1][0]+dp[N][1][1];
		}
		vec.push_back(p);
	}
	
	//outl(vec);
	
	ll N = sz(vec);
	rep(i, 0, N) rep(j, 0, 1) dp2[i][j] = mint(0);
	dp2[0][0] = mint(1);
	rep(i, 0, N-1) rep(j, 0, 1){
		dp2[i+1][j] += dp2[i][j] * vec[i].first;
		dp2[i+1][j^1] += dp2[i][j] * vec[i].second;
	}
	outl(dp2[N][1]);
	
	return 0;
}