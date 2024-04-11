//be naame khodaa
#include <algorithm>
#include <iostream>
#include <cassert>
#include <iomanip>
#include <cstring>
#include <sstream>
#include <numeric>
#include <string>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <set>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
#define F first
#define S second
#define pb push_back
#define sz(x) ((int)(x).size())

const int N = 12 + 1;
const int M = 2000 + 10; 

int a[M][N]; 
pii b[M]; 

int dp[N][(1<<N)]; 
int sum[(1<<N)];

void solve() { 
	int n, m;
	cin >> n >> m; 

	for(int i = 0; i < n; i++) 
		for(int j = 0; j < m; j++) 
			cin >> a[j][i]; 

	for(int j = 0; j < m; j++) { 
		b[j] = {-1, j}; 
		for(int i = 0; i < n; i++) 
			if( b[j].F < a[j][i] ) 
				b[j].F = a[j][i]; 
	}


	sort(b, b + m); 
	reverse(b, b + m); 

	m = min(n, m); 

	memset(dp, -63, sizeof dp); 
	dp[0][0] = 0; 
	
	for(int jj = 0; jj < m; jj++) { 
		int j = b[jj].S; 

		for(int mask = 1; mask < (1<<n) ; mask++) 
			sum[mask] = sum[mask^(mask & (-mask))] + a[j][__builtin_ctz(mask)]; 

		for(int mask = 0; mask < (1<<n); mask++) { 
			for(int submask = mask; ; submask = (submask - 1) & mask) { 

				int other = mask ^ submask; 

				dp[jj+1][mask] = max(dp[jj+1][mask], dp[jj][submask] + sum[other]);

				if( submask == 0 ) break;
			}

			int x = mask;
			for(int k = 0; k < n; k++) { 
				x = x / 2 + (x % 2) * (1<<(n-1)); 
				dp[jj+1][x] = max(dp[jj+1][x], dp[jj+1][mask]); 
			}
		}
	}

	cout << dp[m][(1<<n)-1] << '\n';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); 

	int t; cin >> t;

	for(int i = 0; i < t; i++) 
		solve(); 
}