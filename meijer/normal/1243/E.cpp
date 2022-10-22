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
#define fi first
#define se second

const ll MX=6000, MXN=6000*15, MOD=1e9+7, BS=1<<15;
ll k, n[20], a[20][MX], m, tot[20];
ll iToA[MXN], suc[MXN], box[MXN];
bitset<MXN> visited, used;
map<ll, ll> aToI;
vi loop;
ll loopBoxes;
ll dp[BS], dpi[BS];
bitset<BS> baseCase;
ll ans[20], ansBox[20];

ll countBS(ll x) {
	ll cnt=0;
	RE(j,20)
		if(x & (1<<j))
			cnt++;
	return cnt;
}
void addLoop(ll i, ll e) {
	loop.pb(i);
	loopBoxes |= 1<<box[i];
	if(suc[i] != e)
		addLoop(suc[i], e);
}
void dfs(ll i) {
	if(i == -1) return;
	if(used[i]) addLoop(i, i);
	if(visited[i]) return;
	visited[i] = 1;
	used[i] = 1;
	dfs(suc[i]);
	used[i] = 0;
}
bool possible(ll bs) {
	if(dp[bs] == -1) {
		dp[bs] = 0;
		for(ll nbs=bs; nbs; nbs=(nbs-1)&bs) {
			if(possible(nbs) && possible(bs^nbs)) {
				dp[bs] = 1, dpi[bs] = nbs;
				break;
			}
		}
	}
	return dp[bs];
}
void fillAnsLoop(ll i, ll e) {
	ans[box[suc[i]]] = iToA[suc[i]];
	ansBox[box[suc[i]]] = box[i]+1;
	if(suc[i] != e)
		fillAnsLoop(suc[i], e);
}
void fillAns(ll bs) {
	if(baseCase[bs]) {
		fillAnsLoop(dpi[bs], dpi[bs]);
	} else {
		fillAns(dpi[bs]);
		fillAns(bs^dpi[bs]);
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>k;
    ll sum = 0;
    RE(i,k) {
    	cin>>n[i];
    	RE(j,n[i]) cin>>a[i][j], sum+=a[i][j];
    }

    if(sum % k == 1) {
    	cout<<"No"<<endl;
    	return 0;
    }
    ll average = sum/k;

    RE(i,k) tot[i] = 0;
    RE(i,k)
    	RE(j,n[i])
    		aToI[a[i][j]] = m, iToA[m++] = a[i][j], tot[i] += a[i][j];
    RE(i,k) RE(j,n[i]) {
    	ll x = aToI[a[i][j]];
    	ll y = average - tot[i] + a[i][j];
    	suc[x] = -1;
    	if(aToI.find(y) == aToI.end()) continue;
    	y = aToI[y];
    	suc[x] = y;
    	box[x] = i;
    }

    visited.reset();
    used.reset();
    baseCase.reset();
    RE(i,BS) dp[i] = -1;
    RE(i,m) {
    	if(!visited[i]) {
    		loop.clear();
    		loopBoxes = 0;
    		dfs(i);
    		if(loop.size() == 0 || countBS(loopBoxes) != loop.size())
    			continue;
    		dp[loopBoxes] = 1;
    		dpi[loopBoxes] = loop[0];
    		baseCase[loopBoxes] = 1;
    	}
    }
    dp[0] = 1;

    if(possible((1<<k)-1)) {
    	cout<<"Yes"<<endl;
    	fillAns((1<<k)-1);
    	RE(i,k)
    		cout<<ans[i]<<" "<<ansBox[i]<<endl;
    } else {
    	cout<<"No"<<endl;
    }
}