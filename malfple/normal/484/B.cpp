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

const int N = 1e6;

int n;
int tree[2*N+5];

int query(int l, int r){
	l += N-1, r += N;
	int ret = 0;
	for(; l<r; l>>=1, r>>=1){
		if(l&1)ret = max(ret, tree[l++]);
		if(r&1)ret = max(ret, tree[--r]);
	}
	return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #define endl '\n'
    
    cin>>n;
    REP(i,1,n){
    	int x;
    	cin>>x;
    	tree[N+x-1] = x;
	}
	REV(i,N-1,1)tree[i] = max(tree[i<<1], tree[i<<1|1]);
	
	int ans = 0;
	REP(i,2,N){
		if(tree[N+i-1] == 0)continue;
		//printf("i %d\n",i);
		REPP(j,i,N,i){
			int k = min(j+i-1, N);
			int q = query(j, k);
			if(q > 0){
				ans = max(ans, q%i);
				//printf("q %d %d = %d\n",j,k,q);
			}
		}
	}
    
    cout << ans << endl;
    
    return 0;
}