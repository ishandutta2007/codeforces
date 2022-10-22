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
ll t, a, b, q, l, r;
ll A[MX];

void program() {
    cin>>t;
    while(t--) {
        cin>>a>>b>>q;
        if(b < a) swap(a, b);
        ll period = 1;
        ll cnt = 0;
        while(1) {
            A[period-1] = cnt;
            ll left     = (period%b)%a;
            ll right    = period%a;
            if(left != right) cnt++;
            if((period % b) == 0 && (period%a) == 0) break;
            period++;
        }
        A[period] = cnt;
        RE(i,q) {
            cin>>l>>r;
            ll ans=0;
            ll rem = (r-l)/period;
            r -= rem*period;
            ans = rem*cnt;
            int bg = (l-1)%period;
            int ed = r%period;
            if(bg < ed) {
                ans += A[ed];
                ans -= A[bg];
            } else {
                ans += A[period]-A[bg];
                ans += A[ed];
            }
            cout<<(i==0?"":" ")<<ans;
        }
        cout<<endl;
    }
}