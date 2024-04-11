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

const int MX = 3e5;

int n, a[MX];
map<int, vi> mp;

ll power(ll x, ll pow) {
    ll ans = 1;
    RE(i,pow) ans *= x;
    return ans;
}
void handle(int x) {
    for(int i=2; i*i<=x; i++) {
        if(x%i == 0) {
            int cnt = 0;
            while(x%i == 0) {
                cnt++;
                x /= i;
            }
            mp[i].pb(cnt);
        }
    }
    if(x != 1) mp[x].pb(1);
}


void program() {
    cin>>n;
    RE(i,n) cin>>a[i];
    RE(i,n) handle(a[i]);
    ll ans = 1;
    for(auto& it : mp) {
        if(it.second.size() < n-1) continue;
        sort(it.second.begin(), it.second.end());
        ans *= power(it.first, it.second[it.second.size()-n+1]);
    }
    cout<<ans<<endl;
}