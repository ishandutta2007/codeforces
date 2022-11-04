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

const int mod = 1000000007;

int n,k,code;
int vis[10],mark[10],p[10],C[10][10];

int go (int past, int rem){
	if (rem==0)
		return 1;
	int ret = 0;
	for (int i=1; i<=rem; i++){
		int temp = C[rem][i];
		for (int j=1; j<=i; j++)
			temp = ((LL)temp * past) % mod;
		ret = ((LL)ret + (LL)temp * go(i, rem-i)) % mod;
	}
	return ret;
}

int main(){
	for (int i=0; i<10; i++){
		C[i][0] = 1;
		for (int j=1; j<=i; j++)
			C[i][j] = (C[i-1][j] + C[i-1][j-1]);
	}
	cin >> n >> k;
	int ret = k;
	for (int i=k+1; i<=n; i++)
		ret = ((LL)ret * (n-k))%mod;
	ret = ((LL)ret * go(1, k-1)) % mod;
	cout << ret << endl;
	return 0;
}