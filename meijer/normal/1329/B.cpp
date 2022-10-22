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
ll t, d, m;

void program() {
    cin>>t;
    while(t--) {
        cin>>d>>m;
        ll dp[32];
        RE(i,32) {
           dp[i] = (1LL<<(i));
           RE(j,i) dp[i] += ((1LL<<i)*dp[j])%m;
           dp[i] %= m;
        }
        ll ans=0;
        ll msb=0;
        RE(i,32) if(d&(1<<i)) msb=i;
        RE(i,msb) ans += dp[i];
        ans %= m;
        ll ways=d-(1<<msb)+1;
        ans += ways;
        RE(i,msb) ans += (dp[i]*ways)%m;
        ans %= m;
        cout<<ans<<endl;
    }
}