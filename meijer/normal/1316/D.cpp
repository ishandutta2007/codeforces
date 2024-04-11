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

const int MX = 1e3+2;
int n;
int x[MX][MX], y[MX][MX];
char gr[MX][MX];
int dx[]={1,-1,0,0}, dy[]={0,0,1,-1};
char dir[]={'D','U','R','L'};
int ox, oy;

bool inside(int x, int y) {
	return 1 <= x && x <= n && 1 <= y && y <= n;
}
void dfs(int cx, int cy, int px, int py) {
	if(gr[cx][cy] != '.') return;
	if(x[cx][cy] != ox || y[cx][cy] != oy) return;
	RE(i,4) {
		int nx=cx+dx[i];
		int ny=cy+dy[i];
		if(!inside(nx, ny)) continue;
		if(nx == px && ny == py) {
			gr[cx][cy] = dir[i];
			continue;
		}
		dfs(nx, ny, cx, cy);
	}
}
bool isM(int cx, int cy) {
	if(!inside(cx, cy)) return 0;
	return x[cx][cy] == -1 && y[cx][cy] == -1;
}

void program() {
	cin>>n;
	RE1(i,n) RE1(j,n) {
		cin>>x[i][j]>>y[i][j];
	}
	RE1(i,n) RE1(j,n) gr[i][j] = '.';
	RE1(i,n) RE1(j,n) {
		if(x[i][j] == i && y[i][j] == j) {
			ox = i;
			oy = j;
			dfs(i,j,i,j);
			gr[i][j] = 'X';
		}
	}
	RE1(i,n) RE1(j,n) {
		if(x[i][j] == -1 && y[i][j] == -1) {
			if(gr[i][j] != '.') continue;
			RE(d,4) {
				int nx=i+dx[d];
				int ny=j+dy[d];
				if(!isM(nx,ny)) continue;
				gr[i][j] = dir[d];
			}
		}
	}
	bool pos=1;
	RE1(i,n) RE1(j,n) if(gr[i][j] == '.') pos=0;
	cout<<(pos?"VALID":"INVALID")<<endl;
	if(pos) {
		RE1(i,n) {
			RE1(j,n) cout<<gr[i][j];
			cout<<endl;
		}
	}
}