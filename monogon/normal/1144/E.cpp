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

int n;
string s, t;
int res[200001];

int main() {
	std::ios_base::sync_with_stdio(false);
	cin >> n >> s >> t;
	int c = 0;
	FORr(i, n) {
		int a = s[i] - 'a', b = t[i] - 'a';
		res[i + 1] = ((a + b + c) % 26);
		c = (a + b + c) / 26;
	}
	res[0] = c;
	FORr(i, n + 1) {
		res[i] = (res[i] / 2) + (i == 0 || res[i - 1] % 2 == 0 ? 0 : 13);
	}
	FOR(i, n + 1) {
		if(i > 0 || res[i] > 0)
			cout << (char) (res[i] + 'a');
	}
	cout << endl;
}