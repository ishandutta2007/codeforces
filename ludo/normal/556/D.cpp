#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define INF 2147483647
#define MOD 1000000007
#define MAX 200000

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, m;
ll l[MAX], r[MAX]; // left and right
ll ans[MAX];

pair<pll, int> segments[MAX - 1];

ll ba[MAX];

//bool comparebridge(const pll &a, const pll &b)
//{
//	return a < b;
//}

set<pll> bridges;

int main()
{
#ifdef LOCAL
    assert(freopen("input.txt", "r", stdin));
#else
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#endif // LOCAL

	cin >> n >> m;

//	if (m < n - 1) {
//		cout << "No" << endl;
//		return 0;
//	}
//	if (m < n - 1) {
//		cout << "No" << endl;
//		return 0;
//	}

	for (int i = 0; i < n; i++) {
		cin >> l[i] >> r[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> ba[i];
		bridges.insert(make_pair(ba[i], i));
	}
//	sort(a, a + m);

	for (int i = 1; i < n; i++) {
		// pair< max dist, min dist >
		segments[i - 1] = make_pair(make_pair(r[i] - l[i - 1], l[i] - r[i - 1]), i);
	}
	sort(segments, segments + n - 1);

	for (int i = 1; i < n; i++) {
		ll curmax = segments[i - 1].first.first;
		ll curmin = segments[i - 1].first.second;

		set<pll>::iterator firstbridge = bridges.lower_bound(make_pair(curmin, 0LL));

//		cerr << firstbridge->first << " for " << curmin << " " << curmax << endl;

		if (firstbridge == bridges.end() || firstbridge->first > curmax) {
			cout << "No"<< endl;
			return 0;
		}

//		cerr << firstbridge->first << " for " << curmin << " " << curmax << endl;

		ans[segments[i - 1].second] = firstbridge->second;

		bridges.erase(firstbridge);
	}

	cout << "Yes"<< endl;
	for (int i = 1; i < n; i++) {
		cout << (ans[i] + 1) << " ";
	}
	cout << endl;

    return 0;
}