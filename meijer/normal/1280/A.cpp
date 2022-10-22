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

const ll MX=4e5, MOD=1e9+7;
ll t, x;
string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--) {
		cin>>x>>s;
		ll ans=s.size();
		string firstX=s; firstX.reserve(x);
		REP(i,0,x) {
			int rep = firstX[i]-'1';
			ans = (ans+(ans-i-1+MOD)*rep)%MOD;
			if(firstX.size() < x) {
				int l = firstX.size();
				RE(k,rep)
				REP(j,i+1,l) {
					firstX.pb(firstX[j]);
					if(firstX.size() == x)
						break;
				}
			}
		}
		cout<<ans<<endl;
	}
}