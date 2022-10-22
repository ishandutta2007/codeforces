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

const int MX = 5e5;
int n, m, a[MX], cnt[MX];

void program() {
	cin>>n>>m;
	RE(j,n) RE(i,m) cin>>a[i+j*m], a[i+j*m]--;
	int ans=0;
	RE(i,m) {
		int tot=0;
		RE(j,n) cnt[j] = 0;
		RE(j,n) {
			int v = a[i+j*m];
			v -= i;
			if(v < 0 || v % m || v >= n*m) {
				ans++;
				continue;
			}
			v /= m;
			cnt[(n-v+j)%n]++;
			tot++;
		}
		int mn = tot;
		RE(j,n) {
			mn = min(mn, j+tot-cnt[j]);
		}
		ans += mn;
	}
	cout<<ans<<endl;
}