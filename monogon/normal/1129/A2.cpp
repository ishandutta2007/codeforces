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

using namespace std;

int n, m, a, b;

int main() {
	std::ios_base::sync_with_stdio(false);
	cin >> n >> m;
	vector<int> v(n);
	vector<int> count(n);
	fill(all(v), -1);
	fill(all(count), 0);
	FOR(i, m) {
		cin >> a >> b;
		if(v[a - 1] == -1 || (b - a + n) % n < v[a - 1]) {
			v[a - 1] = (b - a + n) % n;
		}
		count[a - 1]++;
	}
	FOR(i, n) {
		if(count[i] == 0) {
			v[i] = 0;
		}else {
			v[i] = n * (count[i] - 1) + v[i];
		}
	}
	FOR(i, n) {
		int M = v[i];
		FORK(j, 1, n) {
			if(count[(i + j) % n] == 0) continue;
			if(v[(i + j) % n] + j > M) {
				M = v[(i + j) % n] + j;
			}
		}
		cout << M << " ";
	}
}