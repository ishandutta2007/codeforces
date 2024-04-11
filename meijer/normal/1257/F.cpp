#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<ll> vll;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define RE(a,c) REP(a,0,c)
#define REV(a,b,c) for(int a=int(c-1); a>=int(b); a--)
#define INF 1e9
#define pb push_back
#define fi first
#define se second

const int MX=100, BITS=15, BS=1<<BITS, MOD=1e9+7;

int n, a[MX], cnt[2][MX][BS];
map<vi, int> mp;

int countBits(int x) {
	int cnt=0;
	RE(i,BITS) if(x & (1<<i)) cnt++;
	return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    RE(i,n) cin>>a[i];
    RE(i,n) RE(j,BS)
    	cnt[0][i][j] = countBits(a[i]^j);
    RE(i,n) a[i] >>= BITS;
    RE(i,n) RE(j,BS)
    	cnt[1][i][j] = countBits(a[i]^j);

    RE(j,BS) {
    	vi v; v.reserve(n);
    	REP(i,1,n) v.pb(cnt[0][0][j] - cnt[0][i][j]);
    	mp[v] = j;
	}
	RE(j,BS) {
    	vi v; v.reserve(n);
    	REP(i,1,n) v.pb(cnt[1][i][j] - cnt[1][0][j]);
		auto it = mp.find(v);
		if(it != mp.end()) {
			int ans = j<<BITS;
			ans += it->se;
			cout<<ans<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
}