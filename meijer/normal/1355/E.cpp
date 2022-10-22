#include <bits/stdc++.h>
using namespace std;

//macros
typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<ll, ll> lll;
typedef tuple<ll, ll, ll> iii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<ll> vll;
typedef vector<lll> vlll;
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
ll n, h[MX], A, R, M;
ll sm[MX];

ll getAns(ll H) {
    ll lb=0, ub=n-1;
    while(lb != ub) {
        ll mid=(lb+ub)/2;
        if(h[mid] < H) lb = mid+1;
        else ub = mid;
    }
    ll c = lb;
    ll low = H*c-sm[c];
    ll high = sm[n]-sm[c]-H*(n-c);
    ll mn = min(low, high);
    low -= mn;
    high -= mn;
    ll cur = M*mn;
    cur += low*A;
    cur += high*R;
    return cur;
}

void program() {
    cin>>n>>A>>R>>M;
    M = min(M, A+R);
    RE(i,n) cin>>h[i];
    sort(h, h+n);
    sm[0]=0;
    RE(i,n) sm[i+1] = sm[i]+h[i];

    ll lb=h[0], ub=h[n-1];
    while(lb != ub) {
        ll mid=(lb+ub)/2;
        if(getAns(mid)-getAns(mid+1) <= 0) ub = mid;
        else lb = mid+1;
    }
    cout<<getAns(lb)<<endl;
}