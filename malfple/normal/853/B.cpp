#include <iostream>
#include <iomanip>
#include <cstdio>

#include <cstring>
#include <string>
#include <sstream>

#include <cmath>
#include <algorithm>
#include <ctime>
#include <cassert>

#include <queue>
#include <utility>
#include <set>
#include <stack>
#include <vector>
#include <map>

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
#define ff first
#define ss second

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

int n,m,k;

vector<pair<int,pii> >work, home;
int cost[N];
int curr;
ll currcost;
stack<pair<ll, int> >stk;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>k;
    REP(i,1,m){
        int d,f,t,c;
        cin>>d>>f>>t>>c;
        if(t == 0){
            work.pb(mp(d, mp(f, c)));
        }else{
            home.pb(mp(d, mp(t, c)));
        }
    }
    sort(work.begin(), work.end());
    sort(home.begin(), home.end());

    FOR(i,work.size()){
        int d = work[i].ff;
        int now = work[i].ss.ff;
        int c = work[i].ss.ss;

        if(cost[now] == 0){
            curr++;
            currcost += c;
            cost[now] = c;
        }else if(c < cost[now]){
            currcost += c-cost[now];
            cost[now] = c;
        }

        if(curr == n){
            if(stk.empty() || currcost < stk.top().ff){
                stk.push(mp(currcost, d));
                //printf("%lld %d\n",currcost, d);
            }
        }
    }

    memset(cost, 0, sizeof cost);
    currcost = 0;
    curr = 0;

    ll ans = INF;
    FORD(i, home.size()){
        int d = home[i].ff;
        int now = home[i].ss.ff;
        int c = home[i].ss.ss;

        if(cost[now] == 0){
            curr++;
            currcost += c;
            cost[now] = c;
        }else if(c < cost[now]){
            currcost += c-cost[now];
            cost[now] = c;
        }

        if(curr == n){
            //printf("%lld %d\n",currcost,d);
            while(!stk.empty() && d-stk.top().ss-1 < k)stk.pop();
            if(!stk.empty()){
                ans = min(ans, currcost + stk.top().ff);
            }
        }
    }

    if(ans == INF)cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}