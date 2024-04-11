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

int n, q;

bitset<7001> a[100001];

bitset<7001> t[7001];
bitset<7001> r[7001];
int dc[7001];

int main()
{
	dc[1] = 1;
	for(int i=2; i<=7000; ++i){
		dc[i] = 1;
		int x = i;
		for(int j=2; j*j<=x; ++j) if(x%j == 0){
			int e = 0;
			while(x%j==0) ++e, x/=j;
			if(e > 1) dc[i] = 0;
		}
	}

	for(int i=1; i<=7000; ++i){
		for(int j=1; j*i<=7000; j++){
			t[i][i*j] = dc[j];
			r[j*i].set(i);
		}
	}

	cppio();
	cin >> n >> q;
for(;q--;){
	int cmd; cin >> cmd;
	if(cmd == 1){
		int x, v; cin >> x >> v;
		a[x] = r[v];
	} else if(cmd == 2){
		int x, y, z; cin >> x >> y >> z;
		a[x] = a[y] ^ a[z];
	} else if(cmd == 3){
		int x, y, z; cin >> x >> y >> z;
		a[x] = a[y] & a[z];
	} else if(cmd == 4){
		int x, v; cin >> x >> v;
		cout << (a[x] & t[v]).count()%2;
	}
}
	cout << endl;
	return 0;
}