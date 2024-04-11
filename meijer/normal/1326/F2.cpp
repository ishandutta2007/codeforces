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

const int MX = 19, BIT=1<<MX;
int n, bit, sbit;
string s[MX];
bitset<MX> knows[MX];
ll dp[BIT][MX];
ll g[MX][BIT];
vi v;
map<vi, vi> mp;
ll ans[BIT];
ll d[BIT];
ll savedD[BIT][MX];

void fillAns(int tot=0, int last=1) {
	if(tot == n) {
		ll add=0;
		int x=bit-1;
		RE(i,bit) {
			if(__builtin_popcount(i)%2) add-=d[i^x];
			else 						add+=d[i^x]; 
		}
		vi& f=mp[v];
		for(int i:f)
			ans[i] = add;
		return;
	}
	if(tot+last > n) return;
	RE(i,bit) savedD[i][tot]=d[i];
	REP(i,last,n-tot+1) {
		if(tot+i != n && tot+i+i>n) continue;
		v.pb(i);
		RE(j,bit) d[j]*=g[i][j];
		fillAns(tot+i,i);
		RE(j,bit) d[j]=savedD[j][tot];
		v.pop_back();
	}
}

void program() {
	cin>>n;
	RE(i,n) cin>>s[i];
	RE(i,n) knows[i].reset();
	RE(i,n) RE(j,n) if(s[i][j]=='1') knows[i][j]=1;
	RE(i,BIT) RE(j,MX) dp[i][j]=0;
	RE(i,n) dp[1<<i][i]=1;
	bit=(1<<n);
	sbit=(1<<(n-1));
	RE(i,bit) RE(j,n) {
		RE(k,n) if(!((i>>k)&1)) if(knows[j][k]) {
			dp[i|(1<<k)][k] += dp[i][j];
		}
	}
	RE(j,bit) {
		int i=__builtin_popcount(j);
		RE(k,n) g[i][j] += dp[j][k];
	}
	RE(i,n+1) {
		RE(j,n) RE(mask,bit)
			if((mask>>j)&1)
				g[i][mask] += g[i][mask^(1<<j)];
	}
	RE(i,sbit) {
		int cnt=1;
		v.clear();
		RE(j,n-1) {
			if((i>>j)&1) {
				cnt++;
			} else {
				v.pb(cnt);
				cnt=1;
			}
		}
		v.pb(cnt);
		sort(v.begin(), v.end());
		mp[v].pb(i);
		ans[i] = 0;
	}
	RE(i,bit) d[i]=1;
	v.clear();
	fillAns();
	RE(i,n-1)
		RE(mask,sbit)
			if(!((mask>>i)&1))
        		ans[mask] -= ans[mask|(1<<i)];
	RE(i,sbit) cout<<(i==0?"":" ")<<ans[i];
	cout<<endl;
}