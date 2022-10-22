#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define RE(a,c) REP(a,0,c)
#define REV(a,b,c) for(int a=int(c-1); a>=int(b); a--)
#define INF 1e9
#define pb push_back
#define fi first
#define se second

const int MX=1e5;
ll n, k, a[MX];
map<ll,pair<ll,ll>> minMax;
map<ll,pair<ll,ll>> maxMin;

ll getMinMax(ll op) {
    auto it = --minMax.upper_bound(op);
    return it->se.fi - (op - it->fi)/it->se.se;
}
ll getMaxMin(ll op) {
    auto it = --maxMin.upper_bound(op);
    return it->se.fi + (op - it->fi)/it->se.se;
}
void fillMinMax() {
    ll w=0, mx=a[n-1], op=0;
    REV(i,0,n) {
        if(mx > a[i]) {
            ll change = mx-a[i];
            op += change*w;
            mx = a[i];
        }
        w++;
        minMax[op] = {mx, w};
    }
}
void fillMaxMin() {
    ll w=0, mn=a[0], op=0;
    REP(i,0,n) {
        if(mn < a[i]) {
            ll change = a[i]-mn;
            op += change*w;
            mn = a[i];
        }
        w++;
        maxMin[op] = {mn, w};
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    RE(i,n) cin>>a[i];
    sort(a, a+n);

    fillMinMax();
    fillMaxMin();
    ll ans=a[n-1]-a[0];

    //L
    ll w=0, mn=a[0], op=k;
    REP(i,0,n) {
        if(mn < a[i]) {
            ll change = a[i]-mn;
            op -= change*w;
            mn = a[i];
        }
        if(op > 0)
            ans = min(ans, getMinMax(op) - a[i]);
        w++;
    }
    //R
    w=0, op=k;
    ll mx=a[n-1];
    REV(i,0,n) {
        if(mx > a[i]) {
            ll change = mx-a[i];
            op -= change*w;
            mx = a[i];
        }
        if(op > 0)
            ans = min(ans, a[i] - getMaxMin(op));
        w++;
    }

    cout<<max(0LL,ans)<<endl;
}