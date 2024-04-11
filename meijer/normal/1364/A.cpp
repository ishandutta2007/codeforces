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
int n, x, a[MX];

void program() {
    cin>>testCases;
    while(testCases--) {
        cin>>n>>x;
        RE(i,n) cin>>a[i];
        int ans = -1;
        int sm = 0;
        vector<ii> first;
        first.push_back({0,0});
        RE(i,n) {
            sm += a[i];
            int rem = sm%x;
            RE(j,min(2,(int)first.sz)) {
                if(rem != first[j].fi) {
                    ans = max(ans, i-first[j].se+1);
                    break;
                }
            }
            if(rem != 0) first.push_back({rem, i+1});
        }
        cout<<ans<<endl;
    }
}