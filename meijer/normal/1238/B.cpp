#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;

#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define RE(a,b) REP(a,0,b)
#define INF 1e18

const int MX = 2e5;

ll q, n, r, x[MX];

int main() {
    cin>>q;
    while(q--) {
        cin>>n>>r;
        RE(i,n) cin>>x[i];
        sort(x, x+n, greater<ll>());
        ll ans=0, i=0;
        while(i < n && x[i] > ans*r) {
            ll p=x[i++];
            while(i < n && x[i] == p) i++;
            ans++;
        }
        cout<<ans<<endl;
    }
}