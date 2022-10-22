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

const int MX = 5e5;
ll k, n, a[MX];
map<ll, ll> cnt;
map<ll, ll> prevCost;
map<ll, ll> prevCnt;

void program() {
	cin>>n>>k;
	RE(i,n) cin>>a[i];
	sort(a,a+n);
	RE(i,n) cnt[a[i]]++;
	ll ans=1e18;
	RE(j,2) {
		ll tot=0;
		RE(i,n) {
			if((i==0 || a[i] != a[i-1])) {
				if(cnt[a[i]]+i >= k) {
					ll curAns = 0;
					ll extra = k-cnt[a[i]];
					if(extra <= 0) {
						ans = 0;
						break;
					}
					if(j) {
						curAns += tot;
						curAns -= (a[i]+1)*ll(i);
					} else {
						curAns += (a[i]-1)*ll(i);
						curAns -= tot;
					}
					curAns += extra;
					ans = min(ans, curAns);
				} else {
					if(prevCnt.find(a[i]) != prevCnt.end()) {
						ll curAns = prevCost[a[i]];
						ll extra = k-cnt[a[i]]-prevCnt[a[i]];
						curAns += tot;
						curAns -= (a[i]+1)*ll(i);
						curAns += extra;
						ans = min(ans, curAns);
					} else {
						ll curCost = 0;
						curCost += a[i]*ll(i);
						curCost -= tot;
						prevCost[a[i]] = curCost;
						prevCnt[a[i]] = i;
					}
				}
			}
			tot += a[i];
		}
		reverse(a,a+n);
	}
	cout<<ans<<endl;
}