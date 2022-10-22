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

const int MX = 5e5;
int testCases;
ll n;
ll a[MX];
ll dp[200][200][2][2];

ll getDP(int i, int j, int k, int l) {
    if(i < 0) return 1;
    if(j < 0) return 1;
    if(dp[i][j][k][l] != -1)
        return dp[i][j][k][l];


    ll ans = 0;
    if(getDP(i-1,j,l,k^1) == 0) ans = 1;
    if(getDP(i,j-1,l,k) == 0) ans = 1;

    return dp[i][j][k][l] = ans;
}

void program() {
    RE(i,100) RE(j,100) RE(k,2) RE(l,2) {
        dp[i][j][k][l] = -1;
    }
    dp[0][0][1][0] = 1;
    dp[0][0][0][1] = 0;

    cin>>testCases;
    while(testCases--) {
        cin>>n;
        RE(i,n) cin>>a[i];
        ll tot=0;
        RE(i,n) tot ^= a[i];
        if(tot == 0) {
            cout<<"DRAW"<<endl;
            continue;
        }
        bool win = 0;
        ll ms = 0;
        RE(i,32) if(tot & (1ll<<i)) ms = i;
        ll cntMS = 0;
        RE(i,n) if(a[i] & (1ll<<ms)) cntMS++;
        if(((cntMS-1)/2)%2) {
            win = (n-cntMS)%2;
        } else {
            win = 1;
        }
        cout<<(win ? "WIN" : "LOSE")<<endl;
    }
}