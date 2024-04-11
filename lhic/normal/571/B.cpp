#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>


typedef long long ll;
typedef long double ld;

using namespace std;
const int MAXN =400000; 

int arr[MAXN];

ll dp[5100][5100];
int n, k;

const ll INF = 2000000000;

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i)
		scanf("%d", &arr[i]);
	sort(arr, arr + n);
	int x = n / k;
	int b = n % k;
	int a = k - b;
	for (int i = 0; i <= a; ++i)
		for (int j = 0; j <= b; ++j)
			dp[i][j] = INF;
	dp[0][0] = 0;
	for (int i = 0; i <= a; ++i)
		for (int j = 0; j <= b; ++j) {
			int xx = i * x + j * (x + 1);
			if (i != a) {
				dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + arr[xx + x - 1] - arr[xx]);
			}
			if (j != b) {
				dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + arr[xx + x] - arr[xx]);
			}
		}
	cout << dp[a][b] << "\n";
	return 0;
}