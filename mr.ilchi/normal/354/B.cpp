/*
 * in the name of god
 *
 *
 *
 *
 *
 *
 *
 *
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <complex>
#include <bitset>
#include <iomanip>
#include <utility>

using namespace std;

typedef long long LL;
typedef complex<double> point;
typedef long double ldb;
typedef pair<int,int> pii;

const int inf = 1000000000;

char mat[100][100];
int n,val[26];
int dp[40][1<<20];
int func[100];

int getVal (char x) { if (x=='a') return 1; if (x=='b') return -1; return 0; }

int main(){
	cin >> n;
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			cin >> mat[i][j];
	func[0] = 1;
	func[1] = -1;
	dp[2*n-2][(1<<(n-1))] = getVal(mat[n-1][n-1]);
	for (int d=2*n-3; d>=0; d--){
		int sub = 0;
		for (int i=0; i<n; i++) if (d-i>=0 && d-i<n)
			sub|=(1<<i);
		for (int mask = 1; mask < (1<<n); mask++) if ((mask & sub) == mask){
			memset(val, 0, sizeof val);
			for (int i=0; i<n; i++) if (mask & (1<<i)){
				int j = d-i;
				if (i+1 < n) val[mat[i][j]-'a']|= (1<<(i+1));
				if (j+1 < n) val[mat[i][j]-'a']|= (1<<i);
			}
			if (d%2 == 0){
				dp[d][mask] = -inf;
				for (int i=0; i<26; i++) if (val[i])
					dp[d][mask] = max(dp[d][mask], dp[d+1][val[i]] + func[i]);
			}else{
				dp[d][mask] = inf;
				for (int i=0; i<26; i++) if (val[i])
					dp[d][mask] = min(dp[d][mask], dp[d+1][val[i]] + func[i]);
			}
		}
	}
	if (dp[0][1] > 0)
		cout << "FIRST" << endl;
	else if (dp[0][1] < 0)
		cout << "SECOND" << endl;
	else
		cout << "DRAW" << endl;
	return 0;
}