#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <int, int> PLL;
typedef pair <PLL, int> PLLI;
typedef pair <PLL, PLL> PP;
typedef pair <PII, int> PPI;
typedef pair <ll, int> PLI;
typedef vector <int> vi;
typedef unsigned int ui;
const int inf = 1e9+9;

int n, m, a, b, c;
#define maxn 350

int fire[maxn][maxn][8], tab[40];
bool met[maxn][maxn];
PII dir[10];
int nowe[maxn][maxn][8];
void recursion(int step) {
	
	int ln = tab[step];
	FOR(i, 0, maxn-1)
	  FOR(j, 0, maxn-1)
	    FOR(k, 0, 7)
	    if (fire[i][j][k] > 0) {
			//cout << step << ' ' << i << ' ' << j << ' ' << k << endl;
			PII help = dir[k];
			//cout << help.e1 << ' ' << help.e2 << endl;
			for (int licz=1; licz<=ln; ++licz) met[i + help.e1 * licz][j + help.e2 * licz] = 1;
			nowe[i + help.e1 * ln][j + help.e2 * ln][(k + 1)%8] = 1;
			nowe[i + help.e1 * ln][j + help.e2 * ln][(k + 7)%8] = 1;
		}
		
	FOR(i, 0, maxn-1)
	  FOR(j, 0, maxn-1)
	    FOR(k, 0, 7) fire[i][j][k] = nowe[i][j][k], nowe[i][j][k] = 0;
}

int main() {
	
	dir[0] = {1, 0}; dir[1] = {1, 1};
	dir[2] = {0, 1}; dir[3] = {-1, 1};
	dir[4] = {-1, 0}; dir[5] = {-1, -1};
	dir[6] = {0, -1}; dir[7] = {1, -1};
	
	cin >> n;
	FOR(i, 1, n) cin >> tab[i];
	fire[150][150][0] = 1;
	FOR(i, 1, n) {
		recursion(i);
	}
	
	int wyn = 0;
	FOR(i, 0, maxn-1)
	  FOR(j, 0, maxn-1) {
		  wyn += met[i][j];
	  }
	cout << wyn;
}