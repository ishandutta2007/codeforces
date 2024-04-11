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

const int M = 300;
int sieve[M+5];
vi primes;
vi mul;
ll decomp(int x){
    ll ret = 0;
    for(ll i=0, mm=1; i<primes.size(); i++, mm<<=1){
        if(x % primes[i] == 0)ret |= mm;
    }
    return ret;
}

const ll MOD = 1e9 + 7;
inline ll addmod(ll a, ll b){
    if(a+b<MOD)return a+b;
    return a+b-MOD;
}
inline ll mulmod(ll a, ll b){
    return (a*b)%MOD;
}
inline ll expmod(ll a, ll e){
    ll ret = 1;
    while(e){
        if(e&1)ret = mulmod(ret, a);
        a = mulmod(a, a);
        e >>= 1;
    }
    return ret;
}
inline ll divmod(ll a, ll b){
    return mulmod(a, expmod(b, MOD-2));
}

const int N = 4e5 + 5;

int n,q;
int arr[N];

ll hasp[4*N];
ll pendh[4*N];
inline void applyHasp(int idx, ll v){
    hasp[idx] |= v;
    pendh[idx] |= v;
}
inline void pushHasp(int idx){
    if(pendh[idx]){
        applyHasp(idx<<1, pendh[idx]);
        applyHasp(idx<<1|1, pendh[idx]);
        pendh[idx] = 0;
    }
}
void buildHasp(int idx, int left, int right){
    if(left == right)hasp[idx] = decomp(arr[left]);
    else{
        int mid = (left+right)/2;
        buildHasp(idx<<1, left, mid);
        buildHasp(idx<<1|1, mid+1, right);
        hasp[idx] = hasp[idx<<1] | hasp[idx<<1|1];
    }
}
void actHasp(int idx, int left, int right, int l, int r, ll v){
    if(left >= l && right <= r){
        applyHasp(idx, v);
    }else if(right < l || left > r){
    }else{
        int mid = (left+right)/2;
        pushHasp(idx);
        actHasp(idx<<1, left, mid, l, r, v);
        actHasp(idx<<1|1, mid+1, right, l, r, v);
        hasp[idx] = hasp[idx<<1] | hasp[idx<<1|1];
    }
}
ll qHasp(int idx, int left, int right, int l, int r){
    if(left >= l && right <= r){
        return hasp[idx];
    }else if(right < l || left > r){
        return 0;
    }else{
        int mid = (left+right)/2;
        pushHasp(idx);
        return qHasp(idx<<1, left, mid, l, r) | qHasp(idx<<1|1, mid+1, right, l, r);
    }
}

int tree[4*N];
int pendt[4*N];
inline void applyTree(int idx, int v, int s){
    tree[idx] = mulmod(tree[idx], expmod(v, s));
    if(pendt[idx] == -1)pendt[idx] = v;
    else pendt[idx] = mulmod(pendt[idx], v);
}
inline void pushTree(int idx, int left, int mid, int right){
    if(pendt[idx] != -1){
        applyTree(idx<<1, pendt[idx], mid-left+1);
        applyTree(idx<<1|1, pendt[idx], right-mid);
        pendt[idx] = -1;
    }
}
void buildTree(int idx, int left, int right){
    if(left == right)tree[idx] = arr[left];
    else{
        int mid = (left+right)/2;
        buildTree(idx<<1, left, mid);
        buildTree(idx<<1|1, mid+1, right);
        tree[idx] = mulmod(tree[idx<<1], tree[idx<<1|1]);
    }
}
void updateTree(int idx, int left, int right, int l, int r, int v){
    if(left >= l && right <= r){
        applyTree(idx, v, right-left+1);
    }else if(right < l || left > r){
    }else{
        int mid = (left+right)/2;
        pushTree(idx, left, mid, right);
        updateTree(idx<<1, left, mid, l, r, v);
        updateTree(idx<<1|1, mid+1, right, l, r, v);
        tree[idx] = mulmod(tree[idx<<1], tree[idx<<1|1]);
    }
}
int qTree(int idx, int left, int right, int l, int r){
    if(left >= l && right <= r){
        return tree[idx];
    }else if(right < l || left > r){
        return 1;
    }else{
        int mid = (left+right)/2;
        pushTree(idx, left, mid, right);
        return mulmod(qTree(idx<<1, left, mid, l, r),
            qTree(idx<<1|1, mid+1, right, l, r));
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
    
    sieve[1] = 1;
    REP(i,2,M){
        if(sieve[i])continue;
        REPP(j,i,M,i)sieve[j] = i;
        primes.pb(i);
    }
    FOR(i,primes.size()){
        mul.pb(divmod(primes[i]-1, primes[i]));
    }
    
    memset(pendt, -1, sizeof pendt);
    
    cin>>n>>q;
    REP(i,1,n)cin>>arr[i];
    
    buildHasp(1, 1, n);
    buildTree(1, 1, n);
    
    while(q--){
        string str;
        int a,b,c;
        cin>>str>>a>>b;
        if(str[0] == 'M'){
            cin>>c;
            actHasp(1, 1, n, a, b, decomp(c));
            updateTree(1, 1, n, a, b, c);
        }else{
            ll mask = qHasp(1, 1, n, a, b);
            int tot = qTree(1, 1, n, a, b);
            //cout << "mask, tot " << mask << " " << tot << endl;
            for(ll i=0, mm=1; i<primes.size(); i++, mm<<=1){
                if(mask&mm){
                    tot = mulmod(tot, mul[i]);
                }
            }
            cout << tot << endl;
        }
    }
    
    return 0;
}