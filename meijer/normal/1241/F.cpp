#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
#define REP(a,b,c) for(ll a=ll(b); a<ll(c); a++)
#define RE(a,c) REP(a,0,c)
#define REV(a,b,c) for(ll a=ll(c-1); a>=ll(b); a--)
#define INF 1e9
#define pb push_back

const ll MX=4e5;
ll q, n, a[MX];
ll nxt[MX];
map<ll, ll> nxtX[MX];
ll mem[MX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>q;
    while(q--) {
        cin>>n;
        RE(i,n) cin>>a[i];
        RE(i,n+10) nxt[i]=-1, nxtX[i].clear(), mem[i]=0;
        REV(i,0,n) {
            if(nxtX[i+1].count(a[i])) {
                nxt[i] = nxtX[i+1][a[i]];
                swap(nxtX[i], nxtX[nxt[i]+1]);
                if(nxt[i]+1 < n)
                    nxtX[i][a[nxt[i]+1]] = nxt[i]+1;
            }
            nxtX[i][a[i]] = i;
        }
        ll ans=0;
        REV(i,0,n) {
            if(nxt[i] == -1) continue;
            mem[i] = mem[nxt[i]+1] + 1;
            ans += mem[i];
        }
        cout<<ans<<endl;
    }
}