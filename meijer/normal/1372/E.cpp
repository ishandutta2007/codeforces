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

const int MX = 120;
int n, m;
int k[MX], L[MX][MX], R[MX][MX];
ll dp[MX][MX]; // dp[l][r] = maximum quality for all segments completely in range [l, r]

ll getAns(ll l, ll r) {
    if(r < l) return 0;
    if(dp[l][r] != -1) {
        return dp[l][r];
    }

    ll ans = 0;

    REI(x,l,r) {
        // completely fill up column x
        ll inCol = 0;
        RE(i,n) RE(j,k[i]) {
            if(L[i][j] <= x && R[i][j] >= x && L[i][j] >= l && R[i][j] <= r) {
                inCol++;
            }
        }
        ans = max(ans, inCol*inCol + getAns(l,x-1) + getAns(x+1, r));
    }
    
    return dp[l][r] = ans;
}

void program() {
    cin>>n>>m;
    RE(i,n) {
        cin>>k[i];
        RE(j,k[i]) cin>>L[i][j]>>R[i][j], L[i][j]--, R[i][j]--;
    }
    RE(i,MX) RE(j,MX) dp[i][j] = -1;
    cout<<getAns(0,m-1)<<endl;
}