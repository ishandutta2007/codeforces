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
int t, n, p[MX], c[MX];
bitset<MX> visited;
int loop[MX], m;
int ans;

void findLoop(int start) {
	int u=p[start];
	m=0;
	visited[start] = 1;
	loop[m++] = start;
	while(u != start) {
		visited[u]=1;
		loop[m++] = u;
		u=p[u];
	}
	RE1(i,m) {
		if(i>ans) break;
		if((m%i) != 0) continue;
		RE(j,i) {
			bool found=1;
			u = j;
			while(1) {
				u += i;
				if(u >= m) break;
				if(c[loop[u-i]] != c[loop[u]]) {
					found=0;
					break;
				}
			}
			if(found) {
				ans = i;
				break;
			}
		}
	}
}

void program() {
	cin>>t;
	while(t--) {
		cin>>n;
		RE(i,n) cin>>p[i], p[i]--;
		RE(i,n) cin>>c[i];
		RE(i,n) visited[i]=0;
		ans = n;
		RE(i,n) {
			if(visited[i]) continue;
			findLoop(i);
		}
		cout<<ans<<endl;
	}
}