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

const int N = 505;
const int Q = 6e5 + 5;

int n,m;
char grid[N][N];
int q;
int xl[Q],yl[Q],xh[Q],yh[Q];
vi qq[N];
bool ans[Q];

bitset<N>dp1[N][N], dp2[N][N];

void dnc(int l, int r){
    if(l > r)return;
    int mid = (l+r)/2;

    //printf("dnc %d %d, %d %d\n",l,r,bl,br);

    REP(j,1,m){
        dp1[mid][j] = dp2[mid][j] = 0;
        if(grid[mid][j] == '.')
            dp1[mid][j][j-1] = dp2[mid][j][j-1] = 1;
    }

    REV(j,m-1,1){
        if(grid[mid][j] == '.')
            dp1[mid][j] |= dp1[mid][j+1];
    }
    REV(i,mid-1,l){
        if(grid[i][m] == '.')
            dp1[i][m] = dp1[i+1][m];
        REV(j,m-1,1){
            if(grid[i][j] == '.')
                dp1[i][j] = dp1[i][j+1] | dp1[i+1][j];
        }
    }
    REP(j,2,m){
        if(grid[mid][j] == '.')
            dp2[mid][j] |= dp2[mid][j-1];
    }
    REP(i,mid+1,r){
        if(grid[i][1] == '.')
            dp2[i][1] = dp2[i-1][1];
        REP(j,2,m){
            if(grid[i][j] == '.')
                dp2[i][j] = dp2[i][j-1] | dp2[i-1][j];
        }
    }

    //REP(i,l,r){
    //    REP(j,1,m)cerr << grid[i][j] << ":" << dp2[i][j] << " ";
    //    cerr << endl;
    //}

    REP(i,l,mid){
        FOR(j,qq[i].size()){
            int now = qq[i][j];
            if(xh[now] < mid)continue;
            if(xh[now] > r)continue;
            bitset<N>tmp = dp1[xl[now]][yl[now]] & dp2[xh[now]][yh[now]];
            //cerr << "query " << now << endl;
            //cerr << "bitset " << dp1[xl[now]][yl[now]] << " + " << dp2[xh[now]][yh[now]] << " = " << tmp << endl;
            if(tmp.count() > 0){
                ans[now] = true;
            }
        }
    }

    dnc(l, mid-1);
    dnc(mid+1, r);
}

int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //cout.tie(0);

    //cin>>n>>m;
    n = getnum<int>();
    m = getnum<int>();
    REP(i,1,n)scanf("%s",grid[i]+1);

    q = getnum<int>();
    REP(i,1,q){
        xl[i] = getnum<int>();
        yl[i] = getnum<int>();
        xh[i] = getnum<int>();
        yh[i] = getnum<int>();
        qq[xl[i]].pb(i);
    }

    dnc(1, n);

    REP(i,1,q){
        if(ans[i])printf("Yes\n");
        else printf("No\n");
    }

    return 0;
}