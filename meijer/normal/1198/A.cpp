#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define RE(a,c) REP(a,0,c)
#define REV(a,b,c) for(int a=int(c-1); a>=int(b); a--)
#define INF 1e9
#define pb push_back
#define fi first
#define se second

const int MX=5e5, MOD=1e9+7;
ll n, I, a[MX], maxBits, bitsPerNumber, maxDifference;
map<ll, ll> aToI;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>I;
    RE(i,n) cin>>a[i];
    sort(a, a+n);
    RE(i,n)
        if(aToI.find(a[i]) == aToI.end())
            aToI[a[i]] = aToI.size();
    RE(i,n) a[i] = aToI[a[i]];

    maxBits = I*8;
    bitsPerNumber = maxBits/n;
    if(bitsPerNumber > 50) bitsPerNumber = 50;
    maxDifference = (1LL<<bitsPerNumber) - 1;
    ll ans = n;
    ll l=0;
    RE(r,n) {
    	while(a[r] - a[l] > maxDifference) l++;
    	ans = min(ans, n-r-1 + l);
    }
    cout<<ans<<endl;
}