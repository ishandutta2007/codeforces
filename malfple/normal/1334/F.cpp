//pragma
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

#define YOU using
#define DONT namespace
#define SAY std

YOU DONT SAY;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<pll> vll;

#define REPP(i,a,b,d) for(int i=a;i<=b;i+=d)
#define REP(i,a,b) REPP(i,a,b,1)
#define REVV(i,a,b,d) for(int i=a;i>=b;i-=d)
#define REV(i,a,b) REVV(i,a,b,1)

#define FOR(i,a) for(int i=0; i<a; i++)
#define FORD(i,a) for(int i=(int)a-1; i>=0; i--)

#define pb push_back
#define F first
#define S second

const int OO = 1e9;
const ll INF = 1e18;

const int irand(int lo,int hi){
	return ((double)rand()/(RAND_MAX + 1.0)) * (hi-lo+1) + lo;
}

const ll lrand(ll lo,ll hi){
	return ((double)rand()/(RAND_MAX + 1.0)) * (hi-lo+1) + lo;
}

#define getc getchar
template<typename T>
T getnum(){
	int sign = 1;
	T ret = 0;
	char c;

	do{
		c = getc();
	}while(c == ' ' || c == '\n');
	if(c == '-')sign = -1;
	else ret = c-'0';
	while(1){
		c = getc();
		if(c < '0' || c > '9')break;
		ret = 10*ret + c-'0';
	}
	return sign * ret;
}

inline void ini(int& x){
	x = getnum<int>();
}

inline void scani(int& x){
	scanf("%d",&x);
}

//end of macro

const int N = 5e5 + 5;

int n,m;
int a[N], p[N], b[N];

int ib[N];
int nextb[N];
bool ok[N];

ll tree[4*N];
void updateA(int idx, int left, int right, int l, int r, ll v){
    if(left >= l && right <= r){
        tree[idx] += v;
    }else if(right < l || left > r){
    }else{
        int mid = (left+right)/2;
        updateA(idx<<1, left, mid, l, r, v);
        updateA(idx<<1|1, mid+1, right, l, r, v);
    }
}
void updateB(int idx, int left, int right, int x, ll v){
    if(left == right){
        tree[idx] = min(tree[idx], v);
    }else{
        int mid = (left+right)/2;
        tree[idx<<1] += tree[idx];
        tree[idx<<1|1] += tree[idx];
        tree[idx] = 0;
        if(x <= mid)updateB(idx<<1, left, mid, x, v);
        else updateB(idx<<1|1, mid+1, right, x, v);
    }
}
ll query(int idx, int left, int right, int x){
    if(left == right){
        return tree[idx];
    }else{
        int mid = (left+right)/2;
        if(x <= mid)return tree[idx] + query(idx<<1, left, mid, x);
        else return tree[idx] + query(idx<<1|1, mid+1, right, x);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #define endl '\n'
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(10);

    cin>>n;
    REP(i,1,n)cin>>a[i];
    REP(i,1,n)cin>>p[i];
    cin>>m;
    REP(i,1,m){
        cin>>b[i];
        ib[b[i]] = i;
        nextb[b[i]] = b[i];
    }
    nextb[n+1] = n+1;
    REV(i,n+1,1){
        if(nextb[i] == 0)nextb[i] = nextb[i+1];
    }

    updateA(1, 1, n+1, 1, n, 2 * INF);

    REV(i,n,1){
        ll val;
        if(ib[a[i]] != 0){
            int next = ib[a[i]];
            if(next == m)next = n+1;
            else next = b[next+1];

            val = query(1, 1, n+1, next);
        }

        if(p[i] > 0){
            // printf("update all %d-%d %d\n",1,nextb[a[i]], p[i]);
            updateA(1, 1, n+1, 1, nextb[a[i]], p[i]);
        }else{
            updateA(1, 1, n+1, 1, n+1, p[i]);
        }

        if(ib[a[i]] != 0){
            updateB(1, 1, n+1, a[i], val);
        }

        // printf("at %d\n",i);
        // REP(j,1,n+1)printf("%lld ",query(1, 1, n+1, j)); printf("\n");
    }

    ll ans = query(1, 1, n+1, b[1]);
    // printf("%lld\n",ans);
    if(ans >= INF){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
        cout << ans << endl;
    }

    return 0;
}