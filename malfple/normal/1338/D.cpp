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

const int N = 1e5 + 5;

int n;
vi lst[N];

pii dp[N];
int ccnt[N];

void dfs(int now, int par){
    pii maxx = {0, 0};
    int valmax = 0;
    int childcount = 0;
    FOR(i,lst[now].size()){
        int to = lst[now][i];
        if(to == par)continue;
        dfs(to, now);
        pii tmp = dp[to];
        maxx.F = max(maxx.F, tmp.F);
        maxx.S = max(maxx.S, tmp.S);
        valmax = max(valmax, max(tmp.F, tmp.S));
        childcount++;
    }
    ccnt[now] = childcount;
    if(childcount == 0){
        dp[now] = {1, 0};
        return;
    }

    pii ret = {0, 0};
    ret.F = maxx.S + 1;
    ret.S = valmax + childcount - 1;
    // printf("at %d -> %d %d\n",now,ret.F,ret.S);
    dp[now] = ret;
}

int ans = 0;
void solve(int now, int par, pii vpar){
    if(par == -1){
        ans = max(ans, max(dp[now].F, dp[now].S));
    }else{
        pii res = dp[now];
        res.F = max(res.F, vpar.S + 1);
        res.S = max(res.S + 1, max(vpar.F, vpar.S) + ccnt[now]);
        // printf("at %d, %d %d\n",now,res.F,res.S);
        ans = max(ans, max(res.F, res.S));
    }

    vi SmaxL, SmaxR;
    vi VmaxL, VmaxR;
    FOR(i,lst[now].size()){
        int to = lst[now][i];
        if(to == par){
            SmaxL.pb(0); SmaxR.pb(0);
            VmaxL.pb(0); VmaxR.pb(0);
            continue;
        }
        pii tmp = dp[to];
        SmaxL.pb(tmp.S); SmaxR.pb(tmp.S);
        int tv = max(tmp.F, tmp.S);
        VmaxL.pb(tv); VmaxR.pb(tv);
    }

    REP(i,1,(int)SmaxL.size()-1){
        SmaxL[i] = max(SmaxL[i], SmaxL[i-1]);
        VmaxL[i] = max(VmaxL[i], VmaxL[i-1]);
    }
    REV(i,(int)SmaxL.size()-2,0){
        SmaxR[i] = max(SmaxR[i], SmaxR[i+1]);
        VmaxR[i] = max(VmaxR[i], VmaxR[i+1]);
    }

    int ccnt_down = ccnt[now];
    if(par == -1)ccnt_down--;

    FOR(i,lst[now].size()){
        int to = lst[now][i];
        if(to == par)continue;

        pii nvpar = {0, 0};
        nvpar.F = vpar.S + 1;
        if(i > 0)nvpar.F = max(nvpar.F, SmaxL[i-1] + 1);
        if(i+1 < SmaxR.size()) nvpar.F = max(nvpar.F, SmaxR[i+1] + 1);
        nvpar.S = max(vpar.F, vpar.S) + ccnt_down - 1;
        if(i > 0)nvpar.S = max(nvpar.S, VmaxL[i-1] + ccnt_down - 1);
        if(i+1 < VmaxR.size()) nvpar.S = max(nvpar.S, VmaxR[i+1] + ccnt_down - 1);

        solve(to, now, nvpar);
    }
    // what
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
    REP(i,2,n){
        int a,b;
        cin>>a>>b;
        lst[a].pb(b);
        lst[b].pb(a);
    }

    dfs(1, -1);
    ans = 0;
    solve(1, -1, {0, 0});

    cout << ans << endl;

    return 0;
}