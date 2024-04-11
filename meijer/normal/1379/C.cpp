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
ll testCases;
ll n, m;
ll ans=0;
ll a[MX], b[MX];
ll sm[MX];
ll SA[MX];

void program() {
    cin>>testCases;
    while(testCases--) {
        cin>>n>>m;
        RE(i,m) cin>>a[i]>>b[i];
        ans = 0;

        RE(i,m) SA[i]=i;
        sort(SA,SA+m, [](int i, int j) {
            return a[i]>a[j];
        });
        sm[0] = 0;
        RE(i,m) sm[i+1] = sm[i]+a[SA[i]];

        RE(i,m) {
            ll cAns = a[SA[i]];
            ll x = n-1;
            ll lb=0, ub=m-1;
            while(lb != ub) {
                ll mid=(lb+ub+1)/2;
                if(a[SA[mid]] >= b[SA[i]]) lb=mid;
                else ub=mid-1;
            }
            if(a[SA[lb]] >= b[SA[i]]) {
                ll y = min(lb, x-1);
                if(i <= y) {
                    x++, cAns -= a[SA[i]];
                }
                y = min(lb, x-1);
                cAns += sm[y+1];
                x -= y+1;
                cAns += x*b[SA[i]];
            } else {
                cAns += x*b[SA[i]];
            }
            ans = max(ans, cAns);
        }
        cout<<ans<<endl;
    }
}