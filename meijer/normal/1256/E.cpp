#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define RE(a,c) REP(a,0,c)
#define REV(a,b,c) for(int a=int(c-1); a>=int(b); a--)
#define INF 1e16
#define pb push_back
#define fi first
#define se second

const int MX=3e5, MOD=1e9+7;
ll n, a[MX], dp[MX], dpe[MX], SA[MX], groups=1;
ll group[MX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    RE(i,n) cin>>a[i];
    RE(i,n) SA[i] = i;
    sort(SA, SA+n, [](int i, int j) {
    	return a[i]<a[j];
    });

    dp[n] = INF;
    ll best = a[SA[n-1]], bi=n;
    REP(i,n-2,n) dp[i]=INF;
    REV(i,0,n-2) {
    	dp [i] = best - a[SA[i]];
    	dpe[i] = bi;
    	if(a[SA[i+1]] + dp[i+2] < best)
    		best = a[SA[i+1]] + dp[i+2], bi=i+1;
    }
    ll j=0;
    RE(i,n) {
    	group[SA[i]] = groups;
    	if(dpe[j] == i) groups++, j=i+1;
    }

    cout<<dp[0]<<" "<<groups<<endl;
    RE(i,n) cout<<(i==0?"":" ")<<group[i]; cout<<endl;
}