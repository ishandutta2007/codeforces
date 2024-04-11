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

const int MX = 2e5;
int n, q, r, c;
bitset<MX> lava[2];
bitset<MX> blocked;
int blockCount = 0;

void updatePassable(int c) {
	if(c <  0) return;
	if(c >= n) return;
	blockCount -= blocked[c];

	blocked[c] = 0;
	if(lava[0][c] && lava[1][c]) blocked[c] = 1;
	if(c  >0 && lava[0][c-1] && lava[1][c]) blocked[c] = 1;
	if(c  >0 && lava[1][c-1] && lava[0][c]) blocked[c] = 1;
	if(c+1<n && lava[0][c+1] && lava[1][c]) blocked[c] = 1;
	if(c+1<n && lava[1][c+1] && lava[0][c]) blocked[c] = 1;

	blockCount += blocked[c];
}

void program() {
	cin>>n>>q;
	blocked.reset();
	lava[0].reset();
	lava[1].reset();
	RE(i,q) {
		cin>>r>>c; r--; c--;
		lava[r][c] = !lava[r][c];
		updatePassable(c-1);
		updatePassable(c);
		updatePassable(c+1);
		bool pos = 1;
		if(lava[0][0] || lava[1][n-1] || blockCount) pos = 0;
		cout<<(pos?"Yes":"No")<<endl;
	}
}