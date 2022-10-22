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

const int MX = 302;
int testCases;
int n, k;
bool gr[MX][MX];
int ans;

void program() {
    cin>>testCases;
    while(testCases--) {
        cin>>n>>k;
        RE(i,n) RE(j,n) gr[i][j] = 0;
        int x=0, y=0;
        RE(i,k) {
            gr[x][y] = 1;
            x = (x+1)%n;
            y = (y+1)%n;
            if(i%n == n-1) x = (x+1)%n;
        }
        int mxR = 0, mnR = INF, mnC = INF, mxC = 0;
        RE(i,n) {
            int r = 0;
            RE(j,n) r += gr[i][j];
            mxR = max(mxR, r);
            mnR = min(mnR, r);
        }
        RE(j,n) {
            int c = 0;
            RE(i,n) c += gr[i][j];
            mxC = max(mxC, c);
            mnC = min(mnC, c);
        }
        ans = mxR - mnR + mxC - mnC;
        cout<<ans<<endl;
        RE(i,n) {
            RE(j,n) cout<<gr[i][j];
            cout<<endl;
        }
    }
}