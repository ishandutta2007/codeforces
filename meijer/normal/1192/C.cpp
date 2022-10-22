#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<ll> vll;
#define REP(a,b,c) for(int a=int(b); a!=int(c); a++)
#define RE(a,c) REP(a,0,c)
#define REV(a,b,c) for(int a=int(c-1); a>=int(b); a--)
#define INF 1e9
#define pb push_back
#define fi first
#define se second

const int MX=62, MOD=998244353;
int n;
string s;
set<string> words;
int cnt[MX][MX][11];
ll ways[MX][MX][MX];
ll fact[5];

int cToI(char c) {
	if(c >= 'a' && c <= 'z') return c-'a';
	if(c >= 'A' && c <= 'Z') return c-'A' + 26;
	return c-'0' + 52;
}
inline ll mod(ll x) {return x%MOD;}
ll calc(ll i, ll j, ll k, ll l) {
	ll d = 24;
	ll ar[] = {i,j,k,l,-1};
	ll b = 0;
	REP(i,1,5) {
		if(ar[i] != ar[i-1]) {
			d /= fact[i-b];
			b = i;
		}
	}
	return d;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    RE(i,n) cin>>s, words.insert(s), reverse(s.begin(), s.end()), words.insert(s);
    for(string t:words)
    	cnt[cToI(t[0])][cToI(t.back())][t.size()]++;
    ll ans = 0;
    fact[0] = 1;
    REP(i,1,5) fact[i] = fact[i-1]*i;
    REP(sz,3,11) {
    	RE(j,MX) RE(k,MX) RE(l,MX) ways[j][k][l] = 0;
	    REP(i,0,MX) {
	    	REP(j,0,MX) {
	    		if(cnt[i][j][sz])
	    		REP(k,j,MX) {
	    			if(cnt[i][k][sz])
	    			REP(l,k,MX) {
	    				ways[j][k][l] = mod(ways[j][k][l] + mod(cnt[i][j][sz]*cnt[i][k][sz])*cnt[i][l][sz]);
	    			}
	    		}
	    	}
	    }
	    REP(i,0,MX) {
	    	REP(j,i,MX) {
	    		REP(k,j,MX) {
	    			if(ways[i][j][k])
	    			REP(l,k,MX) {
	    				if(ways[i][j][l] && ways[j][k][l] && ways[i][k][l]) {
							ll added = mod(ways[j][k][l]*ways[i][k][l]);
							added = mod(added*ways[i][j][l]);
							added = mod(added*ways[i][j][k]);
							ans = ans + added*calc(i,j,k,l);
	    				}
					}
				}
			}
	    }
	    ans = mod(ans);
    }
    cout<<ans<<endl;
}