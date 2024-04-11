#include <bits/stdc++.h>
using namespace std;

//macros
typedef long long ll;
typedef pair<int, int> ii;
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

const int MX = 14, BIT=1<<MX, BIT2=(1<<(MX-1));
int n;
string s[MX];
bitset<MX> knows[MX];
int x;
vll dp[BIT][MX];
int pp[BIT];

void program() {
	cin>>n;
	RE(i,n) cin>>s[i];
	RE(i,n) knows[i].reset();
	RE(i,n) RE(j,n) if(s[i][j] == '1') knows[i][j] = 1;
	int bit=(1<<n);
	RE(i,BIT) pp[i]=0;
	RE(i,MX) pp[1<<i]=i;
	RE(used,bit) {
		int cnt=0;
		RE(i,n) if(used&(1<<i)) cnt++;
		if(cnt == 0) continue;
		int mxX = (1<<(cnt-1));
		RE(i,n) dp[used][i].assign(mxX+1, 0);
		RE(i,n) if(used == (1<<i)) dp[used][i][0] = 1;
	}
	RE(used,bit) {
		int cnt=0;
		RE(i,n) if(used&(1<<i)) cnt++;
		if(cnt == 0) continue;
		int mxX = (1<<(cnt-1));
		RE(x,mxX) {
			int u=used;
			while(u) {
				int i=pp[u&-u];
				u-=u&-u;
				if(!dp[used][i][x]) continue;
				int v=(bit-1)^used;
				while(v) {
					int j=pp[v&-v];
					v-=v&-v;
					int nx=x;
					if(knows[i][j]) nx|=(1<<(cnt-1));
					dp[used|(1<<j)][j][nx] += dp[used][i][x];
				}
			}
		}
	}
	RE(x,(1<<(n-1))) {
		ll ans=0;
		RE(i,n) ans+=dp[bit-1][i][x];
		cout<<(x==0?"":" ")<<ans;
	}
	cout<<endl;
}