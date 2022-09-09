#pragma comment (linker, "/STACK:128000000")
#include <cstdio>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
//#include <unordered_map>
//#include <unordered_set>
#include <ctime>
#include <stack>
#include <queue>
using namespace std;
//#define FILENAME ""
#define mp make_pair
#define all(a) a.begin(), a.end()
typedef long long li;
typedef long double ld;
void solve();
//void precalc();
clock_t start;
//int timer = 1;
int main() {
#ifdef room111
    freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#else
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    //freopen(FILENAME".in", "r", stdin);
    //freopen(FILENAME ".out", "w", stdout);
#endif
    int t = 1;
	//cout.sync_with_stdio(0);
	//precalc();
	cout.precision(10);
	cout << fixed;
	//cin >> t;
	start = clock();
	//int testNum = 1;
    while (t--) {
        solve();
		//cout << "Case #" << testNum++ << ": ";
		//++timer;
	}

#ifdef room111
	cerr << "\n\n" << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n";
#endif

    return 0;
}

//BE CAREFUL: IS INT REALLY INT?

#define int li

bool isSquare (int cur) {
	double h = sqrt(1.0 * cur);
	for (int g = (int)h - 2; g < (int)h + 3; ++g)
		if (g * g == cur)
			return true;
	return false;
}

vector<int> solutions[101];

void solve() {
	vector<int> vv;
	vv.push_back(3);
	vv.push_back(4);
	solutions[2] = vv;

	for (int n = 1; n <= 100; ++n) {
		if (n == 2)
			continue;
		bool flag = false;
		for (int a = 0; a <= n; ++a) {
			int now = a + 4 * (n - a);
			if (isSquare(now)) {

				vector<int> vv;
				for (int i = 0; i < a; ++i)
					vv.push_back(1);
				for (int i = a; i < n; ++i)
					vv.push_back(2);
				solutions[n] = vv;			

				flag = true;
				break;
			}
		}

		if (flag)
			continue;

		for (int a = 0; a <= n; ++a)
			for (int b = 0; b + a <= n; ++b) {
				int now = a + b * 4 + (n - b - a) * 9;
				if (isSquare(now)) {

					vector<int> vv;
					for (int i = 0; i < a; ++i)
						vv.push_back(1);
					for (int i = a; i < a + b; ++i)
						vv.push_back(2);
					for (int i = a + b; i < n; ++i)
						vv.push_back(3);
					solutions[n] = vv;

					flag = true;
					break;
				}
			}
	}

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			cout << solutions[n][i] * solutions[m][j] << ' ';
		cout << "\n";
	}

}