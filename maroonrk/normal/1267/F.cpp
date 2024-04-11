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
#define gnr(i,a,b) for(int i=int(b)-1;i>=a;i--)
#define per(i,b) gnr(i,0,b)
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

void no(){
	cout<<"NO"<<endl;
	exit(0);
}

signed main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(20);
	
	int n,m;cin>>n>>m;
	int x,y;cin>>x>>y;
	vi a(x);rep(i,x){cin>>a[i];a[i]--;}
	vi b(y);rep(i,y){cin>>b[i];b[i]--;}
	
	if(x>=m){
		no();
	}
	while(x<m-1){
		a.pb(a.back());
		x++;
	}
	b.pb(n+m-1);
	y++;
	if(y>n){
		no();
	}
	while(y<n){
		b.pb(b.back());
		y++;
	}
	vi used(n);
	int h=x-1;
	vi c;
	per(i,y){
		c.pb(b[i]);
		if(h>=0)used[a[h]]=1;
		while(h>=0&&used[a[h]]){
			c.pb(a[h--]);
		}
	}
	if(h>=0)no();
	c.erase(c.begin());
	cout<<"Yes"<<endl;
	
	int s=n+m;
	vi app(s);
	app[s-1]=1;
	int last=s-1;
	int top=s-1;
	vc<pi> es;
	for(auto v:c){
		if(app[v]){
			while(app[top])top--;
			es.eb(last,top);
			app[top]=1;
		}else{
			es.eb(last,v);
			app[v]=1;
		}
		last=v;
	}
	while(app[top])top--;
	es.eb(last,top);
	
	for(auto e:es){
		cout<<e.a+1<<" "<<e.b+1<<"\n";
	}
}