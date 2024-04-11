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

#define mp make_pair

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

const int N = 3e5 + 5;
const int M = 4e6 + 5;

int n,r;
int x[N], y[N];
vii vec;

int tree[4*M];
int pend[4*M];
void apply(int idx, int v){
    tree[idx] += v;
    pend[idx] += v;
}
void pushdown(int idx){
    if(pend[idx]){
        apply(idx<<1, pend[idx]);
        apply(idx<<1|1, pend[idx]);
        pend[idx] = 0;
    }
}
void update(int idx, int left, int right, int l, int r, int v){
    if(left >= l && right <= r){
        apply(idx, v);
    }else if(right < l || left > r){
        // do nothing
    }else{
        int mid = left+right;
        if(mid < 0)mid--;
        mid /= 2;
        pushdown(idx);
        update(idx<<1, left, mid, l, r, v);
        update(idx<<1|1, mid+1, right, l, r, v);
        tree[idx] = max(tree[idx<<1], tree[idx<<1|1]);
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
    
    cin>>n>>r;
    r *= 2;
    REP(i,1,n){
        cin>>x[i]>>y[i];
        vec.pb(mp(x[i]+y[i], i));
    }
    sort(vec.begin(), vec.end());
    int p = 0;
    int ans = 0;
    FOR(i,vec.size()){
        int id = vec[i].S;
//        printf("cek %d\n",id);
//        printf("+1 %d - %d\n",x[id]-y[id], min(x[id]-y[id]+r, (int)2e6));
        update(1, -2e6, 2e6, x[id]-y[id], min(x[id]-y[id]+r, (int)2e6), 1);
        while(p <= i && vec[i].F - vec[p].F > r){
            int id = vec[p++].S;
//            printf("pop %d\n",id);
//            printf("-1 %d - %d\n",x[id]-y[id], min(x[id]-y[id]+r, (int)2e6));
            update(1, -2e6, 2e6, x[id]-y[id], min(x[id]-y[id]+r, (int)2e6), -1);
        }
        ans = max(ans, tree[1]);
    }
    cout << ans << endl;
    
    return 0;
}