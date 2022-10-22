#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define vec vector
#define deb(x) cerr << #x << " = " << x << '\n';

typedef unsigned long long ull;
typedef long double LD;
typedef long long LL;

const LL inf = 1000000000ll;
const LL inf64 = inf * inf;
const LL base = inf + 7;
const double pi = acos(-1.0);

using namespace std;

bool solve()
{
	int n, m;
	scanf("%d %d", &n, &m);
	
	vec< string > mat(n + 1);
	for(int i = 1;i <= n;i++) {
		cin >> mat[i];
		mat[i] = " " + mat[i];
	}

	vec< vec< vec< LL> > > dp(2, vec< vec< LL > >(n + 1, vec< LL >(n + 1, 0)));

	vec< vec< int > > mas(n + m);

	for(int i = 1;i <= n;i++) 
		for(int j = 1;j <= m;j++)
			mas[i + j - 1].push_back(i);
	
	if(mat[1][1] != mat[n][m]) {
		puts("0");
		return true;
	}

	dp[0][1][n] = 1;
	int z = 0;
	for(int id = 2;id <= (n + m) / 2;id++, z ^= 1) {
		for(int k1 = 1;k1 <= n;k1++) for(int k2 = 1;k2 <= n;k2++) dp[z ^ 1][k1][k2] = 0;
		for(int i = 0;i < (int)mas[id].size();i++) {
			for(int j = 0;j < (int)mas[n + m - id].size();j++) {
				int i1 = mas[id][i], j1 = id + 1 - i1;
				int i2 = mas[n + m - id][j], j2 = n + m + 1 - id - i2;
				if(i1 > i2 || j1 > j2) continue;
				if(mat[i1][j1] != mat[i2][j2]) continue;
				for(int di1 = -1;di1 <= 0;di1++) {
					for(int dj1 = -1;dj1 <= 0;dj1++) {
						for(int di2 = 0;di2 <= 1;di2++) {
							for(int dj2 = 0;dj2 <= 1;dj2++) {
								if(di1 != 0 && dj1 != 0) continue;
								if(di1 == 0 && dj1 == 0) continue;
								if(di2 != 0 && dj2 != 0) continue;
								if(di2 == 0 && dj2 == 0) continue;
								int toi1 = i1 + di1;
								int toj1 = j1 + dj1;
								int toi2 = i2 + di2;
								int toj2 = j2 + dj2;
								if(toi1 < 1 || toi1 > n || toj1 < 1 || toj1 > m) continue;
								if(toi2 < 1 || toi2 > n || toj2 < 1 || toj2 > m) continue;
								dp[z ^ 1][i1][i2] = (dp[z ^ 1][i1][i2] + dp[z][toi1][toi2]) % base;
							}
						}
					}
				}
			}	
		}
	}

	LL ans = 0;

	if((n + m - 1) % 2) {
		for(int i = 1;i <= n;i++) {
			ans = (ans + dp[z][i][i]) % base;
		}
	}else {
		for(int i = 1;i <= n;i++) {
			ans = (ans + dp[z][i][i]) % base;	
			if(i + 1 <= n) ans = (ans + dp[z][i][i + 1]) % base;
		}
	}

	cout << ans << '\n';

    return true;
}   

int main() 
{
    //while(solve());
    solve();

    return 0;
}