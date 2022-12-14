#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <complex>
#include <stack>
using namespace std;
#define PB push_back
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define FORE(i,x) for(__typeof((x).begin()) i=(x).begin();i != (x).end();++i)
#define ALL(x) (x).begin(),(x).end()
#define CLR(x) memset((x),0,sizeof (x))
#define X first
#define Y second
typedef long long int lli;
typedef long long unsigned llu;
typedef long double ld;
typedef pair<int, int> P;
typedef vector<int> VI;
typedef vector<string> VS;
template<class C> inline void mini(C& a, C b) {a=min(a,b);}
template<class C> inline void maxi(C& a, C b) {a=max(a,b);}
#define INF ((lli)1E9)
#define MAXN 1007

int n,m,k,x,y,xx,yy;
string s[MAXN], path;
int px[MAXN], py[MAXN], t[MAXN][MAXN];
bool kon;

int sgn(int q){return q>0 ? 1 : -1;}

void go(int cx, int cy) {
	while((cx != x || cy != y) && k >= t[x][y]) {
		k -= t[x][y];
		if(x != cx && y != cy) exit(-1);
		if(x == cx) y += sgn(cy - y);
		else x += sgn(cx - x);
	}
	if((x != cx || y != cy) && !kon) {
		kon = true;
		cout << x << " " << y << endl;
	}
}

int main(){ 
	std::ios_base::sync_with_stdio(0);
	//in
	cin >> n >> m >> k;
	FOR(i,1,n) {cin >> s[i]; s[i] = "!" + s[i];}
	cin >> x >> y >> path >> xx >> yy;
	//sol
	FOR(i,1,n) FOR(j,1,m) if('a' <= s[i][j] && s[i][j] <= 'z'){
		px[s[i][j] - 'a'] = i;
		py[s[i][j] - 'a'] = j;
		t[i][j] = 1;
	} else t[i][j] = s[i][j]-'0';
	FORE(i,path) go(px[*i-'a'], py[*i-'a']);
	go(xx, yy);
	//out
	if(!kon) cout << x << " " << y << endl;
  return 0;
}