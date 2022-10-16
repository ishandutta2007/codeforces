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

const int N = 1e5 + 5;

int n;
ll arr[N];
int dif[N];
int q;

struct node{
    ll mx, mn, sum, pend;
    node(ll mx=0, ll mn=0, ll sum=0): mx(mx), mn(mn), sum(sum){
        pend = 0;
    }
}tree[4*N];
node operator+(const node& a, const node& b){
    return node(max(a.mx, b.mx), min(a.mn, b.mn), a.sum+b.sum);
}

void apply(int idx, int s, ll v){
    tree[idx].sum = s*v;
    tree[idx].mx = tree[idx].mn = v;
    tree[idx].pend = v;
}
void pushdown(int idx, int left, int mid, int right){
    if(tree[idx].pend){
        apply(idx<<1, mid-left+1, tree[idx].pend);
        apply(idx<<1|1, right-mid, tree[idx].pend);
        tree[idx].pend = 0;
    }
}

void build(int idx, int left, int right){
    if(left == right){
        tree[idx] = node(dif[left], dif[left], dif[left]);
    }else{
        int mid = (left+right)/2;
        build(idx<<1, left, mid);
        build(idx<<1|1, mid+1, right);
        tree[idx] = tree[idx<<1] + tree[idx<<1|1];
    }
}
ll qSum(int idx, int left, int right, int l, int r){
    if(left >= l && right <= r){
        return tree[idx].sum;
    }else if(right < l || left > r){
        return 0;
    }else{
        int mid = (left+right)/2;
        pushdown(idx, left, mid, right);
        return qSum(idx<<1, left, mid, l, r) + qSum(idx<<1|1, mid+1, right, l, r);
    }
}
void update(int idx, int left, int right, int l, int r, ll v){
    if(left >= l && right <= r && tree[idx].mx <= v){
        apply(idx, right-left+1, v);
    }else if(right < l || left > r || tree[idx].mn >= v){
        // do nothing
    }else{
        int mid = (left+right)/2;
        pushdown(idx, left, mid, right);
        update(idx<<1, left, mid, l, r, v);
        update(idx<<1|1, mid+1, right, l, r, v);
        tree[idx] = tree[idx<<1] + tree[idx<<1|1];
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
    REP(i,1,n){
        cin>>arr[i];
    }
    REP(i,2,n){
        cin>>dif[i];
    }
    REP(i,2,n){
        int exc = arr[i] - (arr[i-1]+dif[i]);
        dif[i] = exc;
        arr[i] -= dif[i];
    }
    
    build(1,1,n);
    REP(i,2,n)arr[i] += arr[i-1];
    
    cin>>q;
    while(q--){
        char op;
        int a,b;
        cin>>op>>a>>b;
        if(op == '+'){
            ll curr = qSum(1,1,n, a, a);
            curr += b;
            update(1,1,n, a, n, curr);
        }else{
            cout << arr[b]-arr[a-1] + qSum(1,1,n, a, b) << endl;
        }
    }
    
    return 0;
}