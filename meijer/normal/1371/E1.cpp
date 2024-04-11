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
int n, p, a[MX];
vi ans;

void program() {
    cin>>n>>p;
    RE(i,n) cin>>a[i];
    sort(a, a+n);
    REP(bx,a[0],a[n-1]+1) {
        int tot=0, x = bx, j=0;
        bool pos = 1;
        while(j < n && a[j] < x) {
            tot++;
            j++;
        }
        RE(i,n) {
            while(j < n && a[j] == x) {
                tot++;
                j++;
            }
            if(tot % p == 0) pos = 0;
            tot--;
            x++;
        }
        if(pos) ans.pb(bx);
    }
    cout<<ans.sz<<endl;
    RE(_pi,ans.sz) cout<<(_pi==0?"":" ")<<ans[_pi]; cout<<endl;
}