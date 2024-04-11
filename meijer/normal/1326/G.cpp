#include <bits/stdc++.h>
using namespace std;

//macros
typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<ll> vll;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define RE(a,c) REP(a,0,c)
#define RE1(a,c) REP(a,1,c+1)
#define REI(a,b,c) REP(a,b,c+1)
#define REV(a,b,c) for(int a=int(c-1); a>=int(b); a--)
#define INF 1e9
#define pb push_back
#define fi first
#define se second
#define sz size()
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//===================//
//  Added libraries  //
//===================//

// mod library
ll MOD=998244353;

inline ll mod(ll x_) {
	return (x_)%MOD;
}
ll modpow(ll x_, ll N_) {
    if(N_ == 0) return 1;
    ll a = modpow(x_,N_/2);
    a = (a*a)%MOD;
    if(N_%2) a = (a*x_)%MOD;
    return a;
}
ll inv(ll x_) {
    return modpow(x_, MOD-2);
}
class mi {
public:
    mi(ll v=0) {value = v;}
    mi  operator+ (ll rs) {return mod(value+rs);}
    mi  operator- (ll rs) {return mod(value-rs+MOD);}
    mi  operator* (ll rs) {return mod(value*rs);}
    mi  operator/ (ll rs) {return mod(value*inv(rs));}
    mi& operator+=(ll rs) {*this = (*this)+rs; return *this;}
    mi& operator-=(ll rs) {*this = (*this)-rs; return *this;}
    mi& operator*=(ll rs) {*this = (*this)*rs; return *this;}
    mi& operator/=(ll rs) {*this = (*this)/rs; return *this;}
    operator ll&() {return value;}

    ll value;
};
typedef vector<mi> vmi;

// points and lines library
typedef long long CT; // Coordinate type

class Point {
public:
	Point() {
		x = 0;
		y = 0;
	}
	Point(CT _x, CT _y) {
		x = _x;
		y = _y;
	}
	Point  operator+ (const Point& rs) const {return Point(x+rs.x, y+rs.y);}
	Point  operator- (const Point& rs) const {return Point(x-rs.x, y-rs.y);}
	CT	   operator* (const Point& rs) const {return x*rs.y - rs.x*y;}
	Point& operator+=(const Point& rs) {*this = (*this)+rs; return *this;}
	Point& operator-=(const Point& rs) {*this = (*this)-rs; return *this;}

	CT x, y;
};

class LineSeg {
public:
	LineSeg() {};
	LineSeg(Point _a, Point _b) : a(_a), b(_b) {};

	Point a, b;
};

typedef vector<Point> vp;

bool isLeft(const LineSeg& l, Point b) {
	return (l.b-l.a)*(b-l.a) >= 0;
}
bool isRight(const LineSeg& l, Point b) {
	return (l.b-l.a)*(b-l.a) <= 0;
}
void sortPointsY(vp& v) {
	sort(v.begin(), v.end(), [](Point& a, Point& b) {
		if(a.y != b.y) return a.y < b.y;
		return a.x < b.x;
	});
}
void sortPointsX(vp& v) {
	sort(v.begin(), v.end(), [](Point& a, Point& b) {
		if(a.x != b.x) return a.x < b.x;
		return a.y < b.y;
	});
}
void sortPointsCW(vp& v, Point bottom) {
	sort(v.begin(), v.end(), [&](Point& a, Point& b) {
		return isLeft({bottom, b}, a);
	});
}
bool interSects(const LineSeg& a, const LineSeg& b) {
	return isLeft(a, b.a) != isLeft(a, b.b) && isLeft(b, a.a) != isLeft(b, a.b);
}
bool isInsidePolygon(Point point, vp& polygon) {
	LineSeg line(point, point+Point(ll(3e9),1));
	int cnt=0;
	for(int i=0; i!=polygon.size(); i++) {
		int j = (i+1)%polygon.size();
		if(interSects(line, {polygon[i], polygon[j]})) cnt++;
	}
	return cnt%2;
}

//===================//
//end added libraries//
//===================//

void program();
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	program();
}


//===================//
//   begin program   //
//===================//

const int MX = 210;
int n, x[MX], y[MX], P[MX], D[MX];
Point POINTS[MX];
vi adj[MX], chl[MX];
mi dp[MX];
vi S;
vi path;
set<int> inPath;
bool good[MX][MX], gd[MX][MX];
mi value[MX][MX];
int edgeI[MX][MX];
int begPath[MX][MX], endPath[MX][MX];

void dfsChl(int u, int p=-1, int d=0) {
	P[u] = p;
	D[u] = d;
	for(int v:adj[u]) if(v!=p) dfsChl(v,u,d+1), chl[u].pb(v);
}
void addPointS(int u) {
	S.pb(u);
}
void findPoints(int u) {
	addPointS(u);
	for(int v:chl[u]) findPoints(v);
}
bool isConnected(int u, int v) {
	if(D[v] > D[u]) swap(u,v);
	if(u == v) return 1;
	if(P[u] == v) return 1;
	if(P[v] == u) return 1;
	return 0;
}
mi possible(int u, int l, int v) {
	if(D[v] < D[u]) swap(u,v);
	if(D[u] < D[l] && D[v] > D[l]) {
		while(D[v] > D[l]) v = P[v];
		if(v == l) return 0;
	}
	if(D[u] > D[l] && D[v] > D[l]) {
		while(D[v]-1 > D[l]) v = P[v];
		while(D[u]-1 > D[l]) u = P[u];
		if(u == v) return 0;
	}
	return 1;
}
void findPath(int u, int v) {
	S.clear();
	path.clear();
	inPath.clear();
	bool swp = 0;
	if(D[v] > D[u]) swap(u,v), swp=1;
	vi pathEnd;
	while(D[u] != D[v]) {
		pathEnd.pb(u); inPath.insert(u);
		u = P[u];
		if(u != v) addPointS(u);
	}
	while(u != v) {
		pathEnd.pb(u); inPath.insert(u);
		path   .pb(v); inPath.insert(v);
		u = P[u];
		v = P[v];
		addPointS(u);
		if(u != v) addPointS(v);
	}
	path.pb(u); inPath.insert(u);
	reverse(pathEnd.begin(), pathEnd.end());
	for(int p:pathEnd) path.pb(p);
	if(swp) reverse(path.begin(), path.end());
}
void fillGood() {
	RE(i,n) RE(j,n) {
		good[i][j] = 1;
		if(isConnected(i,j)) {
			good[i][j] = 0;
			continue;
		}
		findPath(i,j);
		for(int p:S)
			if(!isLeft({POINTS[i],POINTS[j]}, POINTS[p]))
				good[i][j] = 0;
	}
}
mi getAns(int u);
mi getValue(int u, int v) {
	if(!gd[u][v]) return 0;
	if(value[u][v] != -1) return value[u][v];
	mi ans=1;
	findPath(u,v);
	vp pointsPath; pointsPath.resize(path.sz);
	RE(i,path.sz) pointsPath[i] = POINTS[path[i]];
	RE(i,path.sz) {
		Point cent, left, right;
		cent = POINTS[path[i]];
		if(i != 0) right = POINTS[path[i-1]];
		if(i != path.sz-1) left = POINTS[path[i+1]];
		for(int j:chl[path[i]]) {
			if(inPath.count(j)) continue;
			Point p = POINTS[j];
			if(i == path.sz-1) {
				if(!isLeft({right,cent}, p)) continue;
			} else if(i == 0) {
				if(!isLeft({cent,left}, p)) continue;
			} else {
				if(isLeft({cent,left}, right)) {
					// small
					if(!(!isLeft({cent,right}, p) && isLeft({cent,left}, p))) {
						continue;
					}
				} else {
					// big
					if(isLeft({cent,right}, p) && !isLeft({cent,left}, p)) {
						continue;
					}
				}
			}
			ans *= getAns(j);
		}
	}
	return value[u][v] = ans;
}
mi countConvex() {
	mi f[MX];
	int edges=0;
	set<int> SC;
	for(int i:S) SC.insert(i);
	for(int i:SC) {
		for(int j:adj[i]) {
			if(!SC.count(j)) continue;
			edgeI[i][j] = edges++;
		}
	}
	vii T;
	for(int i:SC) for(int j:SC) {
		if(!gd[i][j]) continue;
		T.pb({i,j});
		findPath(i,j);
		begPath[i][j] = edgeI[path[path.sz-1]][path[path.sz-2]];
		endPath[i][j] = edgeI[path[0]][path[1]];
	}
	sort(T.begin(), T.end(), [](ii i, ii j) {
		Point a = POINTS[i.se]-POINTS[i.fi];
		Point b = POINTS[j.se]-POINTS[j.fi];
		bool upA = !(a.y > 0 || (a.y==0 && a.x >= 0));
		bool upB = !(b.y > 0 || (b.y==0 && b.x >= 0));
		if(upA != upB) return upA<upB;
		ll mul = a.x*b.y - a.y*b.x;
		if(mul != 0)
			return mul > 0;
		if(a.x != b.x) return a.x<b.x;
		return a.y < b.y;
	});
	mi an=0;
	RE(i,edges) {
		RE(j,edges) f[j] = 0;
		f[i] = 1;
		for(ii p : T) {
			f[endPath[p.fi][p.se]] += f[begPath[p.fi][p.se]]*getValue(p.fi,p.se);
		}
		f[i] -= mi(1);
		an += f[i];
	}
	return an;
}
mi getAns(int u) {
	if(dp[u] != -1) return dp[u];
	mi ans=0;

	// case 1:
	mi case1=1;
	for(int v:chl[u]) case1 *= getAns(v);
	ans += case1;

	// case 2:
	for(int v:chl[u]) {
		mi case2=1;
		for(int w:chl[v]) case2 *= getAns(w);
		for(int w:chl[u]) if(w != v) case2 *= getAns(w);
		ans += case2;
	}

	// case 3:
	// all good pairs
	RE(i,n) RE(j,n) {
		gd[i][j] = good[i][j];
		if(!isLeft({POINTS[i],POINTS[j]},POINTS[u])) gd[i][j]=0;
	}
	S.clear(); findPoints(u);
	mi added = countConvex();
	ans += added;

	// good pairs which don't contain vertex u in its path
	RE(i,n) RE(j,n) {
		if(!gd[i][j]) continue;
		findPath(i,j);
		if(inPath.count(u)) gd[i][j] = 0;
	}
	S.clear(); findPoints(u);
	mi removed = countConvex();
	ans -= removed;

	return dp[u]=ans;
}

void program() {
	cin>>n;
	RE(i,n) cin>>x[i]>>y[i];
	RE(i,n) POINTS[i] = {x[i], y[i]};
	RE(i,n-1) {
		int u, v; cin>>u>>v; u--; v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfsChl(0);
	fillGood();
	RE(i,n) dp[i] = -1;
	RE(i,n) RE(j,n) value[i][j] = -1;
	cout<<getAns(0)<<endl;
}