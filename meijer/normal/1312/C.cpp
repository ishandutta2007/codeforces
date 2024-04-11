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

const int MX = 5e5;
ll t, n, k, a[MX];

void program() {
	cin>>t;
	while(t--) {
		cin>>n>>k;
		RE(i,n) cin>>a[i];
		ll cur = 1;
		bool pos = 1;
		while(1) {
			int used = 0;
			RE(i,n) {
				if((a[i] % (cur*k)) == cur) {
					a[i] -= cur;
					used++;
				}
				if((a[i] % (cur*k)) != 0) {
					pos = 0;
				}
			}
			if(used > 1) pos = 0;
			cur *= k;
			if(cur > 1e16) break;
		}
		cout<<(pos?"YES":"NO")<<endl;
	}
}