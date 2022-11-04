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

const int MAXN = 50 + 10;

int n,len;
int a[MAXN];
LL dp[MAXN][MAXN];

ldb calc (LL A, LL B, LL C){
	ldb cur = A;
	for (int i=1; i<=C-B; i++)
		cur*=i;
	for (int i=C; i>B; i--)
		cur/=i;
	return cur;
}

int main(){
	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	cin >> len;
	dp[0][0] = 1;
	for (int i=0; i<n; i++){
		for (int j=len-a[i]; j>=0; j--){
			for (int k=i; k>=0; k--)
				dp[k+1][j + a[i]]+= dp[k][j];
		}
	}
	ldb ans = 0;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=len; j++)
			ans+= calc(dp[i][j], i, n);
	cout << fixed << setprecision(10) << ans << endl;
	return 0;
}