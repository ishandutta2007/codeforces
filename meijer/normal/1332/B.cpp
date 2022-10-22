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
int t, n, a[MX];
bool isPrime(int x) {
	for(int i=2; i*i<=x; i++) {
		if((x % i) == 0) {
			return 0;
		}
	}
	return 1;
}
vi primes;
int ans[MX];

void program() {
	cin>>t;
	REP(i,2,32) {
		if(isPrime(i)) primes.pb(i);
	}
	while(t--) {
		cin>>n; RE(i,n) cin>>a[i];
		RE(i,n) {
			for(int j:primes) {
				if(a[i] % j == 0) {
					ans[i] = j;
				}
			}
		}
		map<int, int> colors; int m=0;
		RE(i,n) {
			if(colors.find(ans[i]) == colors.end()) {
				colors[ans[i]] = ++m;
			}
		}
		cout<<m<<endl;
		RE(i,n) cout<<(i==0?"":" ")<<colors[ans[i]]; cout<<endl;
	}
}