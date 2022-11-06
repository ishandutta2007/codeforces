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
const int maxn = int(1e5) + 10;
int a[maxn];
pp t[maxn];

const int M = 131072;
int lz[M<<1][2];

void acq(int p, int a[2]){
	lz[p][0] = a[lz[p][0]];
	lz[p][1] = a[lz[p][1]];
}

inline void clear(int a[2]){ a[0]=0; a[1]=1; }

void init(int p=1, int ml=1, int mr=n){
	clear(lz[p]);
	if(ml != mr){
		int mid=(ml+mr)/2;
		init(p*2, ml, mid); init(p*2+1, mid+1, mr);
	}
}

void pd(int p){
	if(!lz[p]) return;
	acq(p*2, lz[p]);
	acq(p*2+1, lz[p]);
	clear(lz[p]);
}

void upd(int l, int r, int v[2], int p=1, int ml=1, int mr=n){
	if(ml != mr) pd(p);
	if(r<ml || mr<l) return;
	if(l<=ml && mr<=r){
		acq(p, v); return;
	}
	int mid=(ml+mr)/2;
	upd(l, r, v, p*2, ml, mid);
	upd(l, r, v, p*2+1, mid+1, mr);
}

int* get(int i, int p=1, int ml=1, int mr=n){
	if(ml==mr) return lz[p];
	pd(p);
	int mid=(ml+mr)/2;
	if(i <= mid) return get(i, p*2, ml, mid);
	else return get(i, p*2+1, mid+1, mr);
}

int main()
{
	cppio();
	cin >> n >> q;
	rrep(i, n) cin >> a[i];
	rrep(i, n){ t[i] = {abs(a[i]), i}; }
	sort(t+1, t+n+1);

	init();

	int TO_PLUS[2] = {0, 0};
	int TO_MINUS[2] = {1, 1};
	int FLIP[2] = {1, 0};

	for(;q--;){
		char sgn[10]; int val; cin >> sgn >> val;
		int av = abs(val);
		auto lb = [&](int x){ return lower_bound(t+1, t+n+1, pp(x, -n)) - t; };
		if(sgn[0] == '<'){
			if(val < 0){
				upd(lb(av+1), n, TO_PLUS);
			} else {
				int p = lb(av);
				upd(p, n, TO_PLUS);
				upd(1, p-1, FLIP);
			}
		} else {
			if(val < 0){
				int p = lb(av);
				upd(p, n, TO_MINUS);
				upd(1, p-1, FLIP);
			} else {
				upd(lb(av+1), n, TO_MINUS);
			}
		}
	}

	static int ans[maxn];
	rrep(i, n){
		int* x = get(i);
		int j = t[i].y;
		if(a[j] == 0) ans[j] = 0;
		else if(a[j] > 0){
			ans[j] = (x[0] == 0 ? a[j] : -a[j]);
		} else {
			ans[j] = (x[1] == 1 ? a[j] : -a[j]);
		}
	}
	rrep(i, n) cout << ans[i] << ' ';

	cout << endl;

	return 0;
}