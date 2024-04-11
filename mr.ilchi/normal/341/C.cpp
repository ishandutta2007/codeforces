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

const int MAXN= 2000+10;
const int mod = 1000000007;

bool mark[MAXN];
int n;
int a[MAXN],fact[MAXN];
int C[MAXN][MAXN];

int main(){
	cin >> n;
	for (int i=0; i<n; i++){
		cin >> a[i];
		if (a[i] != -1)
			mark[--a[i]] = true;
	}
	for (int i=0; i<=n; i++){
		C[i][0] = 1;
		for (int j=1; j<=i; j++)
			C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;
	}
	fact[0] = 1;
	for (int i=1; i<=n; i++)
		fact[i] = (LL)fact[i-1] * i % mod;
	int f0 = 0, f1 = 0;
	for (int i=0; i<n; i++) if (!mark[i])
		(a[i]==-1) ? (f0++) : (f1++);
	int ret = 0;
	for (int i=0; i<=f0; i++)
		ret = (ret + (LL)C[f0][i] * fact[f0+f1-i] * (i%2 ? -1 : 1)) % mod;
	cout << (ret + mod) % mod << endl;
	return 0;
}