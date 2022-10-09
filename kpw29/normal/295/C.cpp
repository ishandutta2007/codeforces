#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define scanf(...) scanf(__VA_ARGS__)?:0
#define FOR(i, a, b) for(int i=(a); i<=(b); ++i)
typedef long long ll;
typedef unsigned int ull;
typedef pair <int, int> PII;
typedef pair <PII, int> PPI;
typedef pair <ll, int> PLI;
typedef pair <ll, ll> PLL;
typedef pair <PII, PII> PP;
typedef unsigned int ui;
const int inf = 1e9+9;
const int mod = 1e9+7;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 51

int path[155][maxn][maxn][2], ways[155][maxn][maxn][maxn];
//path[numberOfSteps][numberOfPeople50OnLeftSide][numberofPeople100OnLeftSide][BoatPosition]
int cnt[2], cap, n, a;
ll binom[155][155];

int main() {
	cin >> n >> cap;
	FOR(i, 1, n) {
		cin >> a;
		if (a == 50) cnt[0]++;
		else cnt[1]++;
	}
	
	FOR(i, 0, 150)
	  FOR(j, 0, 50)
	    FOR(k, 0, 50)
	      FOR(bit, 0, 1) ways[i][j][k][bit] = 0, path[i][j][k][bit] = inf;
	      
	path[0][cnt[0]][cnt[1]][0] = 0, ways[0][cnt[0]][cnt[1]][0] = 1;
	
	FOR(i, 0, 150) binom[i][0] = 1, binom[i][i] = 1;
	FOR(i, 1, 150)
	  FOR(j, 1, i-1) {
		  binom[i][j] = binom[i-1][j-1] + binom[i-1][j];
		  while (binom[i][j] >= mod) binom[i][j] -= mod;
	  }
	
	int zer = cnt[0], jed = cnt[1];
	FOR(step, 0, 3*n)
	  FOR(pos, 0, 1)
	  {
		  if (step == 0 && pos == 0) continue;
		  FOR(i, 0, zer)
		    FOR(j, 0, jed) {
				int akt0 = i, akt1 = j;
				if (pos) akt0 = zer - i, akt1 = jed - j;
				for (int ILE0 = 0; ILE0 <= akt0; ++ILE0)
				  for (int ILE1 = 0; ILE1 <= akt1; ++ILE1) {
					  if (ILE0 == 0 && ILE1 == 0) continue;
					  if (ILE0 * 50 + ILE1 * 100 > cap) break;
					  if (pos == 0) {
						  int pp = path[step - 1][i - ILE0][j - ILE1][1] + 1;
						  if (pp < path[step][i][j][0]) {
							  path[step][i][j][0] = pp;
							  int value = (ll)ways[step - 1][i - ILE0][j - ILE1][1] * binom[zer-i+ILE0][ILE0] % mod * binom[jed-j+ILE1][ILE1] % mod;
							  ways[step][i][j][0] = value;
						  }
						  else if (pp == path[step][i][j][0]) {
							 int value = (ll)ways[step - 1][i - ILE0][j - ILE1][1] * binom[zer-i+ILE0][ILE0] % mod * binom[jed-j+ILE1][ILE1] % mod;
							 ways[step][i][j][0] += value;
							 while (ways[step][i][j][0] >= mod) ways[step][i][j][0] -= mod;
						  }
				  }
				  else {
					  int pp = path[step][i + ILE0][j + ILE1][0] + 1;
					  if (pp < path[step][i][j][1]) {
						  path[step][i][j][1] = pp;
						  int value = (ll)ways[step][i+ILE0][j+ILE1][0] * binom[i+ILE0][ILE0] % mod * binom[j+ILE1][ILE1] % mod;
						  ways[step][i][j][1] = value;
					  }
					  else if (pp == path[step][i][j][1]) {
						  int value = (ll)ways[step][i+ILE0][j+ILE1][0] * binom[i+ILE0][ILE0] % mod * binom[j+ILE1][ILE1] % mod;
						  ways[step][i][j][1] += value;
						  while (ways[step][i][j][1] >= mod) ways[step][i][j][1] -= mod;
					  }
				  }
			
			}
			//cout << "Position: " << step << ' ' << i << ' ' << j << ' ' << pos << " result : " << path[step][i][j][pos] << ' ' << ways[step][i][j][pos] << endl;
		}
		
	 }
	  
	  int ww = 0;
	  while (ww <= 3*n && path[ww][0][0][1] == inf) ww++;
	  if (ww == 3*n + 1 || path[ww][0][0][1] == inf) OUT("-1\n0");
	  
	  cout << path[ww][0][0][1] << endl << ways[ww][0][0][1];
}