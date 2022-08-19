#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;

#define int ll

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

const int inf=LLONG_MAX/3;

using vi=vc<int>;
using pi=pair<int,int>;

signed main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(20);
	
	int n;cin>>n;
	
	vc<tuple<int,int,int>> rs;
	rep(_,n){
		int a,b,t;cin>>a>>b>>t;
		rs.eb(a,b,t);
	}
	rs.eb(inf,inf,inf);
	
	priority_queue<pi,vc<pi>,greater<pi>> pq;
	sort(all(rs));
	int cur=0,ans=0;
	for(auto z:rs){
		show(ans);
		int l,r,c;tie(l,r,c)=z;
		while(pq.size()){
			show(cur);
			show(ans);
			int x,lim;tie(x,lim)=pq.top();
			if(lim<=cur){
				pq.pop();
			}else if(lim<=l){
				int w=(lim-cur)/x;
				ans+=w;
				cur+=x*w;
				pq.pop();
			}else{
				int w=(l-cur)/x;
				ans+=w;
				cur+=x*w;
				int u=(l-cur)%x;
				if(l+x-u<=lim){
					pq.emplace(x-u,l+x-u);
					cur=l;
					break;
				}else
					pq.pop();
			}
		}
		cur=l;
		pq.emplace(c,r);
	}
	cout<<ans<<endl;
}