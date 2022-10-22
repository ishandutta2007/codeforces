#include <bits/stdc++.h>
using namespace std;

//macros
typedef long long ll;
typedef pair<ll, ll> ii;
typedef tuple<int, int, int> iii;
typedef vector<ll> vi;
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
	program();
}



//===================//
//   begin program   //
//===================//

const int MX = 2e5, CH=26;
string s;
ll n;
ll cnt[MX][CH];
ll pairs[CH][CH];

void program() {
	cin>>s; n=s.size();
	RE(i,MX) RE(j,CH) cnt[i][j] = 0;
	RE(i,n) cnt[i][s[i]-'a']++;
	REP(i,1,n) RE(j,CH) cnt[i][j] += cnt[i-1][j];

	ll ans=0;
	RE(i,CH) ans = max(ans, cnt[n-1][i]);

	RE(i,CH) RE(j,CH) pairs[i][j]=0;
	REP(i,1,n) RE(j,CH) {
		pairs[j][s[i]-'a'] += cnt[i-1][j];
	}
	RE(i,CH) RE(j,CH) ans=max(ans, pairs[i][j]);

	cout<<ans<<endl;
}