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
int n, a[MX];
bitset<MX> b;

void program() {
    cin>>testCases;
    while(testCases--) {
        cin>>n;
        RE(i,n) cin>>a[i];
        int cnt=0;
        RE(i,n) if(a[i] == i+1) cnt++;
        b.reset();
        RE(i,n) if(a[i] == i+1) b[i] = 1;
        int ans=0;
        if(cnt == 0) ans=1;
        else if(cnt == n) ans=0;
        else ans=2;
        if(ans == 2) {
            bool con=1;
            bool start = !b[0];
            REP(i,1,n) {
                if(start) {
                    if(!b[i] && b[i-1]) con = 0;
                } else start = b[i];
            }
            if(con) ans = 1;
        }
        cout<<ans<<endl;
    }
}