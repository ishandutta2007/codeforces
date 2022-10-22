#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
#define REP(a,b,c) for(ll a=ll(b); a<ll(c); a++)
#define RE(a,c) REP(a,0,c)
#define REV(a,b,c) for(ll a=ll(c-1); a>=ll(b); a--)
#define pb push_back
#define fi first
#define se second

const ll INF=1e4;
const ll MX=1e5;
set<ll> goodNumbers;
ll bs, n;

ll bsTo3(ll b) {
    ll ans=0; ll pow=1;
    RE(i,50) {
        if(b & (1LL<<i))
            ans += pow;
        pow *= 3;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    bs = 0;
    while(1) {
        bs++;
        ll nNumb = bsTo3(bs);
        goodNumbers.insert(nNumb);
        if(nNumb > INF)
            break;
    }
    ll q;
    cin>>q;
    while(q--) {
        cin>>n;
        cout<<*goodNumbers.lower_bound(n)<<endl;
    }
}