#include <bits/stdc++.h>
using namespace std;

//macros
typedef long long ll;
typedef pair<ll, ll> ii;
typedef tuple<ll, ll, ll> iii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<ll> vll;
#define REP(a,b,c) for(ll a=ll(b); a<ll(c); a++)
#define RE(a,c) REP(a,0,c)
#define RE1(a,c) REP(a,1,c+1)
#define REI(a,b,c) REP(a,b,c+1)
#define REV(a,b,c) for(ll a=ll(c-1); a>=ll(b); a--)
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

const ll MX = 5e5;
ll testCases;
ll n, a[MX];

void program() {
    cin>>testCases;
    while(testCases--) {
        cin>>n;
        RE(i,n) cin>>a[i];
        set<ll> dif;
        RE(i,n) {
            dif.insert((i+a[i%n]+ll(1e10))%n);
        }
        cout<<(dif.sz == n ? "YES" : "NO")<<endl;
    }
}