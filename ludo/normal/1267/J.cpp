#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(auto i=(a); i<(b); ++i)
#define REP(i,n) rep(i,0,n)
#define all(v) (v).begin(), (v).end()
#define rs resize
#define DBG(x) cerr << __LINE__ << ": " << #x << " = " << (x) << endl
#define int ll

const ld PI = acos(-1.0);
template<class T> using min_queue =
		priority_queue<T, vector<T>, greater<T>>;
template<class T> int sz(const T &x) {
	return (int) x.size(); // copy the ampersand(&)!
}

template<class T> ostream& operator<<(ostream &os, vector<T> v) {
	os << "\n[";
	for(T &x : v) os << x << ',';
	return os << "]\n";
}

struct pairhash {
public:
	template<typename T1, typename T2>
	size_t operator()(const pair<T1, T2> &p) const {
		size_t lhs = hash<T1>()(p.x);
		size_t rhs = hash<T2>()(p.y);
		return lhs ^ (rhs+0x9e3779b9+(lhs<<6)+(lhs>>2));
	}
};

int test(int g, int s){
	int k = (g + (s-1))/s;
	if(s*k-g <= k)
		return k;
	return -1;
}

void run() {
	int n;
	scanf("%Ld",&n);
	//cerr << n<< endl;
	vi ctonr(n,-1);
	vi tel;
	rep(i,0,n){
		int c;
		scanf("%Ld",&c);
		c--;
		if(ctonr[c] == -1){
			ctonr[c] = tel.size();
			tel.pb(1);
		}
		else
			tel[ctonr[c]]++;
	}
	int k = tel.size();
	int mi = n+1;
	rep(i,0,k)
		mi = min(mi,tel[i]);
	mi+=2;
	vi stel(mi,0);
	rep(j,0,k)
		rep(i,1,mi){
			if(stel[i] == -1)
				continue;
			int t = test(tel[j],i);
			if(t == -1)
				stel[i] = -1;
			else
				stel[i] += t;
		}
		
	int ans = stel[1];
	rep(i,2,mi){
		if(stel[i] == -1)
			continue;
		ans = min(ans,stel[i]);
	}
	cout << ans << endl;
	
}



signed main() {
	// DON'T MIX "scanf" and "cin"!
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed << setprecision(20);
	int t;
	scanf("%Ld",&t);
	rep(i,0,t)
		run();
	return 0;
}