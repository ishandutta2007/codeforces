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
#define RE1(a,c) REP(a,1,c+1)
#define REI(a,b,c) REP(a,b,c+1)
#define REV(a,b,c) for(int a=int(c-1); a>=int(b); a--)
#define INF 1e9
#define pb push_back
#define fi first
#define se second

const int MX=2500, MOD=998244353;
ll cntq[MX];
ll dp[MX][MX];
string s;

ll mod(ll x_) {
	return (x_+MOD)%MOD;
}
ll modpow(ll x_, ll N_) {
    if(N_ == 0) return 1;
    ll a = modpow(x_,N_/2);
    a = (a*a)%MOD;
    if(N_%2) a = (a*x_)%MOD;
    return a;
}
ll getQuestions(int i, int j) {
	if(j < i) return 0;
	return cntq[j+1] - cntq[i];
}
ll getAns(int i, int j) {
	if(j <= i) return 0;
	if(dp[i][j] == -1) {
		ll ans = 0;
		if(s[i] != '(') ans = mod(ans + getAns(i+1,j));
		if(s[j] != ')') ans = mod(ans + getAns(i,j-1));
		if(s[i] != '(' && s[j] != ')') ans = mod(ans - getAns(i+1,j-1));
		if(s[i] != ')' && s[j] != '(') {
			ans = mod(ans+modpow(2,getQuestions(i+1,j-1))+getAns(i+1,j-1));
		}
		dp[i][j] = ans;
	}
	return dp[i][j];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>s;
    cntq[0] = 0;
    RE(i,s.size()) cntq[i+1] = cntq[i] + (s[i]=='?'?1:0);
    RE(i,MX) RE(j,MX) dp[i][j] = -1;
    cout<<getAns(0,s.size()-1)<<endl;
}