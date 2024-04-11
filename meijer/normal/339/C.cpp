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

const int MX = 1100;
string s;
int n, m;
int dp[12][12][MX];
vi f;

bool getAns(int over, int last, int left) {
    if(dp[over][last][left] != -1)
        return dp[over][last][left];
    
    bool ans=0;
    if(left == 0) {
        ans = 1;
    } else {
        RE1(i,10) {
            if(i == last) continue;
            if(i <= over) continue;
            if(!s[i-1]) continue;
            ans |= getAns(i-over, i, left-1);
        }
    }

    return dp[over][last][left] = ans;
}
void fillAns(int over, int last, int left) {
    if(left == 0) return;

    RE1(i,10) {
        if(i == last) continue;
        if(i <= over) continue;
        if(!s[i-1]) continue;
        if(getAns(i-over, i, left-1)) {
            f.pb(i);
            fillAns(i-over, i, left-1);
            return;
        }
    }
}

void program() {
    cin>>s>>m;
    n = s.sz;
    RE(i,n) s[i]-='0';
    RE(i,11) RE(j,11) RE(k,m+2) dp[i][j][k] = -1;
    
    bool ans = getAns(0,0,m);
    cout<<(ans ? "YES" : "NO")<<endl;
    if(ans) {
        fillAns(0,0,m);
        RE(_pi,m) cout<<(_pi==0?"":" ")<<f[_pi]; cout<<endl;
    }
}