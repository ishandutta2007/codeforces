#include <bits/stdc++.h>
using namespace std;

//macros
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
#define sz size()

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
ll t, n[3], w[3][MX];

void program() {
    cin>>t;
    while(t--) {
        RE(i,3) cin>>n[i];
        RE(i,3) RE(j,n[i]) cin>>w[i][j];
        RE(i,3) sort(w[i], w[i]+n[i]);
        ll ans=4e18;
        RE(i,3) {
            // color i is the middle
            RE(small,3) {
                if(small == i) continue;
                RE(big,3) {
                    if(big == i) continue;
                    if(big == small) continue;
                    RE(j,n[i]) {
                        ll y = w[i][j];
                        if(y > w[big][n[big]-1]) continue;
                        if(y < w[small][0]) continue;
                        ll x = *lower_bound(w[big], w[big]+n[big], y);
                        ll z = *prev(upper_bound(w[small], w[small]+n[small], y));
                        ans = min(ans, (x-y)*(x-y)+(x-z)*(x-z)+(y-z)*(y-z));
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
}