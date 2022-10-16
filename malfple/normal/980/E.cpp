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

const int N = 1e6 + 5;

int n,k;
vi lst[N];

int depth[N];
int sparset[22][N];

void dfs(int now, int par){
    sparset[0][now] = par;

    FOR(i,lst[now].size()){
        int to = lst[now][i];
        if(to == par)continue;
        depth[to] = depth[now]+1;
        dfs(to, now);
    }
}
bool taken[N];

int getCost(int x){
    int t = x;
    REV(i,20,0){
        if(sparset[i][t] == -1)continue;
        if(taken[sparset[i][t]])continue;
        t = sparset[i][t];
    }
    return depth[x] - depth[t] + 1;
}


int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //cout.tie(0);

    n = getnum<int>();
    k = getnum<int>();
    REP(i,1,n-1){
        int a,b;
        a = getnum<int>();
        b = getnum<int>();
        lst[a].pb(b);
        lst[b].pb(a);
    }

    depth[n] = 1;
    dfs(n, -1);

    REP(i,0,19){
        REP(j,1,n){
            if(sparset[i][j] == -1)sparset[i+1][j] = -1;
            else sparset[i+1][j] = sparset[i][sparset[i][j]];
        }
    }

    int totaltaken = 0;
    REV(i,n,1){
        int cost = getCost(i);
        if(totaltaken + cost <= n-k){
            int t = i;
            while(!taken[t]){
                taken[t] = true;
                totaltaken++;
                t = sparset[0][t];
                if(t == -1)break;
            }
        }
    }
    REP(i,1,n)if(!taken[i])printf("%d ",i);
    printf("\n");

    return 0;
}