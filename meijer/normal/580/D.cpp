#include <bits/stdc++.h>
using namespace std;

//macros
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> lll;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<ll> vll;
typedef vector<lll> vlll;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define RE(a,c) REP(a,0,c)
#define RE1(a,c) REP(a,1,c+1)
#define REI(a,b,c) REP(a,b,c+1)
#define REV(a,b,c) for(int a=int(c-1); a>=int(b); a--)
#define INF 1e9
#define pb push_back
#define fi first
#define se second
#define sz size()
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//===================//
//  Added libraries  //
//===================//

//===================//
//end added libraries//
//===================//

void program();
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    program();
}


//===================//
//   begin program   //
//===================//

const int MX = 5e5, BM=1<<18;
ll n, m, k, a[MX], N;
ll bon[19][19];
ll dp[19][BM];

ll getAns(ll last, ll bm) {
    if(dp[last][bm] != -1)
        return dp[last][bm];

    ll ans=0;
    if(__builtin_popcount(bm) == m)
        return dp[last][bm] = ans;

    RE(i,n) {
        if(bm & (1<<i)) continue;
        ans = max(ans, bon[last][i]+a[i]+getAns(i,bm|(1<<i)));
    }

    return dp[last][bm] = ans;
}

void program() {
    cin>>n>>m>>k;
    RE(i,n) cin>>a[i];
    RE(i,n+1) RE(j,n+1) bon[i][j] = 0;
    RE(i,k) {
        ll x, y, c; cin>>x>>y>>c; x--; y--;
        bon[x][y] = c;
    }
    N = (1<<n);
    RE(i,n+1) RE(j,N) dp[i][j] = -1;
    cout<<getAns(n,0)<<endl;
}