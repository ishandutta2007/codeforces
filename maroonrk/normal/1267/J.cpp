#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
template <class T> using vc = vector<T>;
template <class T> using vvc = vc<vc<T>>;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
#define rng(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, N) for (int i = 0; i < (int)(N); i++)
#define rep1(i, N) for (int i = 1; i <= (int)(N); i++)
#define fs first
#define sc second
#define a first
#define b second
#define eb emplace_back
#define pb push_back
#define all(x) x.begin(), x.end()
template <class T, class U> void chmin(T& t, const U& u) { if (u < t) t = u; }
template <class T, class U> void chmax(T& t, const U& u) { if (t < u) t = u; }

#ifdef LOCAL
#define show(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl
#else
#define show(x)
#endif

template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
	return os << "P(" << p.first << ", " << p.second << ")";
}

template <class T> ostream& operator<<(ostream& os, const vc<T>& v) {
	os << "[";
	for (auto d : v) os << d << ", ";
	return os << "]";
}

const int inf=INT_MAX/2-100;

using vi=vc<int>;

void slb(){
	int n;cin>>n;
	vi cnt(n);
	rep(i,n){
		int c;cin>>c;c--;
		cnt[c]++;
	}
	int mn=inf;
	for(auto z:cnt){
		if(z){
			chmin(mn,z);
		}
	}
	vi val(mn+2,0);
	val[0]=inf;
	for(auto z:cnt)if(z){
		vi w(z+2,inf);
		rng(i,1,z+1){
			int h=z/i;
			chmin(w[h+1],i);
			if(z%i==0)
				chmin(w[h],i);
		}
		rep(i,mn+2)
			val[i]=min(inf,val[i]+w[i]);
	}
	cout<<*min_element(all(val))<<"\n";
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(20);
	
	int t;cin>>t;
	rep(_,t)slb();
}