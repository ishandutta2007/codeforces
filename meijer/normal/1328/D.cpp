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
int q, n, t[MX];
int ans[MX];

void program() {
	cin>>q;
	while(q--) {
		cin>>n;
		RE(i,n) cin>>t[i];
		bool pos1=1;
		RE(i,n) if(t[i]!=t[0]) pos1=0;
		if(pos1) {
			cout<<1<<endl;
			RE(i,n) cout<<(i==0?"1":" 1");
			cout<<endl;
			continue;
		}
		int mn=2;
		ans[0] = 0;
		REP(i,1,n) {
			if(t[i] != t[i-1]) ans[i] = !ans[i-1];
			else ans[i] = ans[i-1];
		}
		if(t[0] != t[n-1]) {
			if(ans[0] == ans[n-1]) {
				bool changed=0;
				REP(i,1,n) {
					if(t[i] != t[i-1]) ans[i] = !ans[i-1];
					else {
						if(!changed) ans[i] = !ans[i-1], changed=1;
						else ans[i] = ans[i-1];
					}
				}
				if(!changed) {
					mn = 3;
					ans[n-1] = 2;
				}
			}
		}
		RE(i,n) ans[i]++;
		cout<<mn<<endl;
		RE(i,n) cout<<(i==0?"":" ")<<ans[i]; cout<<endl;
	}
}