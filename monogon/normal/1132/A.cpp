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

LL a[4];

int main() {
	std::ios_base::sync_with_stdio(false);
	FOR(i, 4)
		cin >> a[i];
	cout << (a[0] == a[3] && (a[2] == 0 || a[0] > 0)) << endl;
}