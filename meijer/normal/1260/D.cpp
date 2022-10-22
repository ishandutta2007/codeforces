#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<ll> vll;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define RE(a,c) REP(a,0,c)
#define RE1(a,c) REP(a,1,c+1)
#define REI(a,b,c) REP(a,b,c+1)
#define REV(a,b,c) for(int a=int(c-1); a>=int(b); a--)
#define INF 1e9
#define pb push_back
#define fi first
#define se second

const int MX=3e5, MOD=1e9+7;
int m, n, k, t, a[MX];
int trap[MX];
viii traps;
int dp[MX];

bool possible(int x) {
	if(x == 0) return 1;
	int mnA = a[x-1];

	RE(i,n+2) trap[i] = 0;
	for(iii p:traps) {
		int l, r, d;
		tie(l,r,d) = p;
		if(d > mnA) {
			trap[l-1] += 1;
			trap[r] += -1;
		}
	}
	REP(i,1,n+2) trap[i] += trap[i-1];
	int total=0;
	RE(i,n+1) {
		if(trap[i]) total += 3;
		else total++;
	}
	return total <= t;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>m>>n>>k>>t;
    RE(i,m) cin>>a[i];
    sort(a,a+m,greater<int>());
    RE(i,k) {
    	int l, r, d;
    	cin>>l>>r>>d;
    	traps.pb({l,r,d});
    }

    int lb=0, ub=m;
    while(lb != ub) {
    	int mid=(lb+ub+1)/2;
    	if(possible(mid)) lb=mid;
    	else ub = mid-1;
    }
    cout<<lb<<endl;
}