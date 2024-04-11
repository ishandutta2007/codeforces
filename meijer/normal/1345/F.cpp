#include <bits/stdc++.h>
using namespace std;

//macros
typedef long long ll;
typedef pair<ll, ll> ii;
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

const int MX = 5e5;
ll n, k, a[MX];
ll b[MX];

ii getRange(ll A) {
    ii ans = {0,0};
    RE(i,n) {
        ll lb=0, ub=a[i];
        while(lb != ub) {
            ll mid=(lb+ub+1)/2;
            if(a[i]-1-3*(mid*mid-mid) >= A) lb = mid;
            else ub = mid-1;
        }
        ans.fi += lb;
        ans.se += lb;
        if(a[i]-1-3*(lb*lb-lb) == A) ans.fi--;
    }
    return ans;
}

void program() {
    cin>>n>>k;
    RE(i,n) cin>>a[i];
    ll lb=9e18, ub=-9e18;
    RE(i,n) lb = min(lb, a[i]-1-3*(a[i]*a[i]-a[i]));
    RE(i,n) ub = max(ub, a[i]-1);
    while(lb != ub) {
        ll mid = (lb+ub)/2;
        if(mid == ub) mid = lb;
        ii range = getRange(mid);
        if(range.fi <= k) ub = mid;
        else              lb = mid+1;
    }
    ll A = lb;
    ii range = getRange(A);
    RE(i,n) {
        ll lb=0, ub=a[i];
        while(lb != ub) {
            ll mid=(lb+ub+1)/2;
            if(a[i]-1-3*(mid*mid-mid) > A) lb = mid;
            else ub = mid-1;
        }
        if(a[i]-1-3*((lb+1)*(lb+1)-lb-1) == A && range.fi != k) {
            lb++;
            range.fi++;
        }
        b[i] = lb;
    }
    RE(i,n) cout<<(i==0?"":" ")<<b[i]; cout<<endl;
}