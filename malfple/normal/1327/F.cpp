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

const ll MOD = 998244353;
inline ll addmod(ll a, ll b){
    if(a+b<MOD)return a+b;
    return a+b-MOD;
}
inline ll submod(ll a, ll b){
    return addmod(a, MOD-b);
}
inline ll mulmod(ll a, ll b){
    return (a*b)%MOD;
}

const int N = 5e5 + 5;

int n,k,m;
int l[N], r[N], x[N];

int pf[N];
int mxjump[N];
vii vec;

int dp[N];

int solve(int mask){
    memset(pf, 0, sizeof pf);
    vec.clear();

    REP(i,1,m){
        // printf("%d, %d %d\n",x[i],mask,x[i]&mask);
        if(x[i] & mask){ // 1 field
            // printf("1 field %d %d\n",l[i],r[i]);
            pf[l[i]]++;
            pf[r[i]+1]--;
        }else{ // 0 field
            vec.pb({l[i], r[i]});
        }
    }

    REP(i,2,n+1){
        pf[i] += pf[i-1];
    } // if pf[i] > 0, then it should be 1

    // precompute mxjump
    sort(vec.begin(), vec.end());
    int p = (int)vec.size()-1;
    int mxx = n+1;
    REV(i,n,0){
        while(p >= 0 && vec[p].F > i){
            mxx = min(mxx, vec[p].S);
            p--;
        }
        mxjump[i] = mxx;
    }

    // now do dp
    dp[n+1] = 1;
    mxx = n+1;
    int sum = 1;
    REV(i,n,0){
        while(mxx > mxjump[i]){
            if(pf[mxx] == 0){
                sum = submod(sum, dp[mxx]);
            }
            mxx--;
        }
        // printf("at %d, jump to %d, sum %d\n",i,mxx,sum);

        dp[i] = sum;

        if(pf[i] == 0){ // can jump to here
            // printf("added %d\n",i);
            sum = addmod(sum, dp[i]);
        }
    }

    // printf("dp\n");
    // REP(i,0,n+1)printf("%d ",dp[i]);printf("\n");

    return dp[0];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #define endl '\n'
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(10);

    cin>>n>>k>>m;
    REP(i,1,m)cin>>l[i]>>r[i]>>x[i];

    int ans = 1;
    FOR(i,k){
        ans = mulmod(ans, solve(1<<i));
    }
    cout << ans << endl;

    return 0;
}