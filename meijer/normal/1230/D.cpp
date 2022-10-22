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

const int MX=8000;
ll n;
ll a[MX], b[MX];
map<ll, ll> cnt;
set<ll> used;

bool canAdd(ll ca) {
    for(ll i : used)
        if((i|ca) == i)
            return 1;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    RE(i,n) cin>>a[i];
    RE(i,n) cin>>b[i];
    RE(i,n) cnt[a[i]]++;
    for(auto it:cnt)
        if(it.second != 1)
            used.insert(it.first);
    ll ans=0;
    RE(i,n)
        if(canAdd(a[i]))
            ans+=b[i];
    cout<<ans<<endl;
}