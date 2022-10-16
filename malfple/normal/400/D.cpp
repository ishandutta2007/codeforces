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
const int K = 505;

int n,m,kk;
int cnt[K];
int type[N];

int p[N];
int cek(int x){
	if(p[p[x]] != p[x])p[x] = cek(p[x]);
	return p[x];
}

int adj[K][K];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #define endl '\n'
    
    cin>>n>>m>>kk;
    
    REP(i,1,n){
    	p[i] = i;
	}
    
    int le = 1;
    REP(i,1,kk){
    	cin>>cnt[i];
    	REP(j,le,le+cnt[i]-1)type[j] = i;
    	le += cnt[i];
	}
	REP(i,1,kk){
		REP(j,1,kk){
			adj[i][j] = OO;
		}
		adj[i][i] = 0;
	}
	REP(i,1,m){
		int a,b,c;
		cin>>a>>b>>c;
		if(type[a] != type[b]){
			adj[type[a]][type[b]] = adj[type[b]][type[a]] = min(adj[type[a]][type[b]], c);
		}
		if(c == 0){
			p[cek(b)] = cek(a);
		}
	}
	bool rekt = false;
	REP(i,2,n){
		if(type[i] == type[i-1]){
			if(cek(i) != cek(i-1)){
				rekt = true;
			}
		}
	}
	
	if(rekt)cout << "No" << endl;
	else{
		cout << "Yes" << endl;
		REP(k,1,kk){
			REP(i,1,kk){
				REP(j,1,kk){
					adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
				}
			}
		}
		REP(i,1,kk){
			REP(j,1,kk){
				cout << (adj[i][j]==OO?-1:adj[i][j]) << " ";
			}
			cout << endl;
		}
	}
    
    return 0;
}