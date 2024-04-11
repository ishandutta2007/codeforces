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

int n,q;
string str;

struct node{
    int v0, v1; // 0 real, 1 when flipped
    bool fl, fr;
    vi vec;
}tree[4*N], nnull;
bool pend[4*N];

inline int vback(const vi& v){
    if(v.size() == 1)return v[0];
    return v[v.size()-1] + v[v.size()-2];
}
inline int vfront(const vi& v){
    if(v.size() == 1)return v[0];
    return v[0] + v[1];
}

inline void reduce(vi& v){
    if(v.size() <= 4)return;
    int b = v.back(); v.pop_back();
    int a = v.back(); v.pop_back();
    while(v.size() > 2)v.pop_back();
    v.pb(a); v.pb(b);
}

inline char cat(int x, bool flip){
    char ret = str[x];
    if(flip){
        if(ret == '<')ret = '>';
        else ret = '<';
    }
    return ret;
}

inline node combine(const node& a, const node& b, int mid){
    if(a.v0 == -1)return b;
    if(b.v0 == -1)return a;

    node ret;
    ret.v0 = max(a.v0, b.v0);
    ret.v1 = max(a.v1, b.v1);
    ret.fl = a.fl;
    ret.fr = b.fr;

    bool pa = a.fr, pb = b.fl;

    if(cat(mid, pa) == '<' && cat(mid+1, pb) == '<'){
        ret.v0 = max(ret.v0, vback(a.vec) + b.vec[0]);
        ret.v1 = max(ret.v1, a.vec.back() + vfront(b.vec));
    }else if(cat(mid, pa) == '>' && cat(mid+1, pb) == '>'){
        ret.v1 = max(ret.v1, vback(a.vec) + b.vec[0]);
        ret.v0 = max(ret.v0, a.vec.back() + vfront(b.vec));
    }else if(cat(mid, pa) == '>' && cat(mid+1, pb) == '<'){
        ret.v0 = max(ret.v0, a.vec.back() + b.vec[0]);
    }else if(cat(mid, pa) == '<' && cat(mid+1, pb) == '>'){
        ret.v1 = max(ret.v1, a.vec.back() + b.vec[0]);
    }

    ret.vec = a.vec;
    if(cat(mid, pa) == cat(mid+1, pb)){
        ret.vec.back() += b.vec[0];
    }else{
        ret.vec.pb(b.vec[0]);
    }
    for(int i=1; i<b.vec.size(); i++){
        ret.vec.pb(b.vec[i]);
    }

    reduce(ret.vec);

    return ret;
}

void build(int idx, int left, int right){
    if(left == right){
        tree[idx].v0 = 1;
        tree[idx].v1 = 1;
        tree[idx].fl = tree[idx].fr = 0;
        tree[idx].vec.pb(1);
    }else{
        int mid = (left+right)/2;
        build(idx<<1, left, mid);
        build(idx<<1|1, mid+1, right);
        tree[idx] = combine(tree[idx<<1], tree[idx<<1|1], mid);
    }
}

inline void apply(int idx){
    swap(tree[idx].v0, tree[idx].v1);
    tree[idx].fl ^= 1;
    tree[idx].fr ^= 1;
    pend[idx] ^= 1;
}

inline void prop(int idx){
    if(pend[idx]){
        apply(idx<<1);
        apply(idx<<1|1);
        pend[idx] = 0;
    }
}

void uflip(int idx, int left, int right, int l, int r){
    if(left >= l && right <= r){
        apply(idx);
    }else if(right < l || left > r){
        // do nothing
    }else{
        prop(idx);
        int mid = (left+right)/2;
        uflip(idx<<1, left, mid, l, r);
        uflip(idx<<1|1, mid+1, right, l, r);
        tree[idx] = combine(tree[idx<<1], tree[idx<<1|1], mid);
    }
}

node query(int idx, int left, int right, int l, int r){
    if(left >= l && right <= r){
        return tree[idx];
    }else if(right < l || left > r){
        return nnull;
    }else{
        prop(idx);
        int mid = (left+right)/2;
        const node& nl = query(idx<<1, left, mid, l, r);
        const node& nr = query(idx<<1|1, mid+1, right, l, r);
        return combine(nl, nr, mid);
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

    nnull.v0 = -1;
    nnull.v1 = -1;

    cin>>n>>q;
    cin>>str;

    build(1, 0, n-1);

    while(q--){
        int l, r;
        cin>>l>>r;
        l--, r--;
        uflip(1, 0, n-1, l, r);
        node res = query(1, 0, n-1, l, r);
        cout << res.v0 << endl;
        // printf("query %d %d\n",res.v0, res.v1);
        // for(auto x : res.vec)printf("%d ",x);printf("\n");
        // printf("%c %c\n",cat(l, res.fl), cat(r, res.fr));
    }

    return 0;
}