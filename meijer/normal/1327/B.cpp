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
int t, n;
vi adj[MX];

void program() {
	cin>>t;
	while(t--) {
		cin>>n;
		RE(i,n) {
			adj[i].clear();
			int k; cin>>k;
			adj[i].resize(k);
			RE(j,k) cin>>adj[i][j];
		}
		set<int> found;
		bool improve=1;
		int improveI=-1;
		RE(i,n) {
			improve = 1;
			for(int j:adj[i]) {
				if(!found.count(j)) {
					found.insert(j);
					improve = 0;
					break;
				}
			}
			if(improve) {
				improveI = i;
			}
		}
		if(improveI == -1) cout<<"OPTIMAL"<<endl;
		else {
			RE1(j,n) {
				if(!found.count(j)) {
					cout<<"IMPROVE"<<endl;
					cout<<improveI+1<<" "<<j<<endl;
					break;
				}
			}
		}
	}
}