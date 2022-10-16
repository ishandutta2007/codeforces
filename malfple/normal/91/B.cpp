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

inline void OPTIMIZE(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #define endl '\n'
}

//end of macro

const int N = 1e5 + 5;

int n;
vii vec;
int ans[N];

int tree[2*N];
void update(int x, int v){
	x += n-1;
	tree[x] = v;
	while(x > 1){
		tree[x>>1] = max(tree[x], tree[x^1]);
		x >>= 1;
	}
}

int query(int l, int r){
	l += n-1, r += n;
	int ret = 0;
	for(; l<r; l>>=1, r>>=1){
		if(l&1)ret = max(ret, tree[l++]);
		if(r&1)ret = max(ret, tree[--r]);
	}
	return ret;
}

int main(){
    OPTIMIZE();
    
    cin>>n;
    REP(i,1,n){
    	int x;
    	cin>>x;
    	vec.pb(mp(x,i));
	}
	sort(vec.begin(), vec.end());
	FOR(i,vec.size()){
		int q = query(vec[i].S, n);
		if(q == 0)ans[vec[i].S] = -1;
		else ans[vec[i].S] = q-vec[i].S-1;
		
		update(vec[i].S, vec[i].S);
	}
	REP(i,1,n)cout << ans[i] << " ";
	cout << endl;
    
    return 0;
}