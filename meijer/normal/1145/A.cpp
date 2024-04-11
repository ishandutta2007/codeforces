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

const int MX = 16;

int n;
int a[MX];
bool isSorted(int l, int r) {
	REP(i,l,r) if(a[i] > a[i+1]) return 0;
	return 1;
}

void program() {
	cin>>n;
	RE(i,n) cin>>a[i];
	int ans=1;
	RE(i,8) {
		if((1<<i) > n) break;
		for(int j=0; j<n; j+=(1<<i)) {
			if(isSorted(j,j+(1<<i)-1)) {
				ans = max(ans, (1<<i));
			}
		}
	}
	cout<<ans<<endl;
}