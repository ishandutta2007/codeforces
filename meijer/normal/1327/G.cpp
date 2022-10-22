#include <bits/stdc++.h>
using namespace std;

//macros
typedef long long ll;
typedef pair<ll, ll> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<ll> vll;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define RE(a,c) REP(a,0,c)
#define RE1(a,c) REP(a,1,c+1)
#define REI(a,b,c) REP(a,b,c+1)
#define REV(a,b,c) for(int a=int(c-1); a>=int(b); a--)
#define INF 1e9
#define pb push_back
#define fi first
#define se second
#define sz size()
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//===================//
//  Added libraries  //
//===================//

//===================//
//end added libraries//
//===================//

void program();
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL);
	program();
}


//===================//
//   begin program   //
//===================//

const int MX = 2000, MXS=4e5+2;
int k, c[MX], qPos[MX], q=0;
string t[MX];
int go[MX][14], fail[MX], out[MX], m=1;
string s;
ll dp[1<<14][MX];
map<int, ii> res[MXS];

void createAutomation() {
	RE(i,MX) RE(j,14) go[i][j]=-1;
	RE(i,MX) fail[i]=out[i]=0;
	RE(i,k) {
		int cur=0;
		RE(j,t[i].sz) {
			if(go[cur][t[i][j]] == -1) go[cur][t[i][j]]=m++;
			cur = go[cur][t[i][j]];
		}
		out[cur] += c[i];
	}
	RE(i,14) if(go[0][i]==-1) go[0][i]=0;
	queue<int> q;
	RE(i,14) if(go[0][i] != 0)
		fail[go[0][i]]=0, q.push(go[0][i]);
	while(!q.empty()) {
		int u = q.front(); q.pop();
		RE(i,14) {
			if(go[u][i] == -1) continue;
			int f = fail[u];
			while(go[f][i] == -1) f = fail[f];
			f = go[f][i];
			fail[go[u][i]] = f;
			out[go[u][i]] += out[f];
			q.push(go[u][i]);
		}
	}
}
int getNextState(int u, char nxt) {
	int ans = u;
	while(go[ans][nxt] == -1) ans = fail[ans];
	return go[ans][nxt];
}
ii getRes(int i, int u) {
	if(res[i].find(u) == res[i].end()) {
		ii ans;
		if(i == s.sz || s[i] == '?') ans = {u,0};
		else {
			int nxt=getNextState(u, s[i]);
			ans = getRes(i+1, nxt);
			ans.se += out[nxt];
		}
		res[i][u] = ans;
	}
	return res[i][u];
}
ll getAns(int bm, int u) {
	if(dp[bm][u] == -1e18-1) {
		int curQ = __builtin_popcount(bm);
		if(curQ == q) return dp[bm][u] = 0;
		ll ans = -1e18;
		RE(i,14) {
			if(bm&(1<<i)) continue;
			int nxt = getNextState(u,i);
			ii res = getRes(qPos[curQ]+1, nxt);
			res.se += out[nxt];
			ans = max(ans, getAns(bm|(1<<i), res.fi)+res.se);
		}
		dp[bm][u] = ans;
	}
	return dp[bm][u];
}

void program() {
	cin>>k;
	RE(i,k) cin>>t[i]>>c[i];
	cin>>s;
	RE(i,k) RE(j,t[i].sz) t[i][j]-='a';
	RE(i,s.sz) if(s[i]!='?') s[i]-='a';

	createAutomation();

	RE(i,s.sz) if(s[i]=='?') qPos[q++]=i;

	RE(i,(1<<14)) RE(j,m) dp[i][j] = -1e18-1;
	ii res = getRes(0,0);
	ll ans = getAns(0,res.fi)+res.se;
	cout<<ans<<endl;
}