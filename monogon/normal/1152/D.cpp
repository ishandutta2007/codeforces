#include <iostream>
#include <iterator>
#include <numeric>
#include <algorithm>
#include <vector>
#include <set>

#define FOR(i, n) for(int i = 0; i < n; i++)
#define FORK(i, k, n) for(int i = k; i < n; i++)
#define FORr(i, n) for(int i = n - 1; i >= 0; i--)
#define FORKr(i, k, n) for(int i = n - 1; i >= k; i--)
#define PRINT(a, b) copy((a), (b), ostream_iterator<int>(cout, " "))
#define all(a) a.begin(), a.end()
#define in(a, b) ((b).find(a) != (b).end())
#define sz(a) ((int) (a).size())
#define Mp make_pair
#define PII pair<int, int>
#define LL long long
#define M 1000000007

using namespace std;

int n;

LL dp[2001][2001];

int main() {
	std::ios_base::sync_with_stdio(false);
	cin >> n;
	n *= 2;
	FOR(i, n + 1) {
		FOR(j, i + 1) {
			if(i == 0) dp[i][j] = 0;
			else if(i == 2) dp[i][j] = 1;
			else {
				LL count = 0;
				bool b1 = false, b2 = false;
				// ()
				if(j <= i - 2) {
					count += dp[i - 2][j];
					count %= M;
					b1 = true;
				}
				// ((
				if(j + 2 <= i - 2) {
					count += dp[i - 2][j + 2];
					count %= M;
					b1 = true;
				}
				// ))
				if(j >= 2 && j - 2 <= i - 2) {
					count += dp[i - 2][j - 2];
					count %= M;
					b2 = true;
				}
				// )(
				if(j > 0 && j <= i - 2) {
					count += dp[i - 2][j];
					count %= M;
					b2 = true;
				}
				count += b1;
				count += b2;
				dp[i][j] = count % M;
			}
		}
	}
	cout << dp[n][0] << endl;
}