#include <cstdio>
#include <iostream>
#include <iomanip>
using namespace std;
const int MAXN = 2005;

double f[MAXN][MAXN], p;
int n, t;

inline int min(int a, int b){return a > b ? b : a;}
int main(){
	int i, j; double ans = 0.000;
	cin >> n >> p >> t;
	f[0][0] = 1.000;
	for(i = 0; i <= t; ++ i)
		for(j = 0; j <= min(n, i); ++ j){
			if(j == n){
				f[i + 1][j] += f[i][j];
				continue;
			}
			f[i + 1][j + 1] += f[i][j] * p;
			f[i + 1][j] += f[i][j] * (1.000 - p);
		}
	for(j = 1; j <= n; ++ j)
		ans += f[t][j] * (double)j;
	cout << setprecision(8) << ans << endl;
	return 0;
}