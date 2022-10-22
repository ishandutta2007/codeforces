#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define INF 1e9
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)

const int BITS=19;
const int MX=2e5;

ll k, n;
ll a[MX];
ll cnt[MX], cost[MX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    REP(i,0,n) cin>>a[i];
    sort(a,a+n);
    ll ans = INF;
    REP(i,0,BITS) {
        REP(j,0,n) {
            ll aj = a[j];
            while(aj > (1<<i)) aj>>=1;
            cnt[aj]=cost[aj]=0;
        }
        REP(j,0,n) {
            ll aj = a[j]; ll c=0;
            while(aj > (1<<i))
                aj>>=1, c++;
            cnt[aj]++;
            cost[aj]+=c;
            if(cnt[aj] == k)
                ans=min(ans, cost[aj]);
        }
    }
    REP(j,0,n) {
        ll aj = a[j];
        while(aj > 0) aj>>=1;
        cnt[aj]=cost[aj]=0;
    }
    REP(j,0,n) {
        ll aj = a[j]; ll c=0;
        while(aj > 0)
            aj>>=1, c++;
        cnt[aj]++;
        cost[aj]+=c;
        if(cnt[aj] == k)
            ans=min(ans, cost[aj]);
    }
    cout<<ans<<endl;
}