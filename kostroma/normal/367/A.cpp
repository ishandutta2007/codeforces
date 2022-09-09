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
#include <unordered_map>
#include <unordered_set>
#include <ctime>
using namespace std;
//#define FILENAME ""
#define mp make_pair
#define all(a) a.begin(), a.end()
typedef long long li;
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
    while (t--)
        solve();

#ifdef room111
	cerr << "\n\n" << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n";
#endif

    return 0;
}

//BE CAREFUL: IS INT REALLY INT?

//#define int li

string s;

void solve(){
	cin >> s;
	vector<vector<int>> have(s.length() + 1, vector<int>(3, 0));
	int cur = 0;
	for (int i = 0; i < s.length(); ++i) {
		have[i + 1][0] = have[i][0];
		have[i + 1][1] = have[i][1];
		have[i + 1][2] = have[i][2];
		if (s[i] == 'x')
			++have[i + 1][0];
		if (s[i] == 'y')
			++have[i + 1][1];
		if (s[i] == 'z')
			++have[i + 1][2];
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int l, r;
		cin >> l >> r;
		if (r - l + 1 < 3) {
			cout << "YES\n";
			continue;
		}
		--l; --r;
		
		int num[3];
		int sum = 0;
		for (int w = 0; w < 3; ++w) {
			num[w] = have[r + 1][w] - have[l][w];
			sum += num[w];
		}

		bool flag = true;
		if (sum != r - l + 1)
			flag = false;
		for (int w = 0; w < 3; ++w)
			for (int k = 0; k < 3; ++k)
				if (abs(num[w] - num[k]) > 1) {
					flag = false;
				}
		if (!flag) {
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
	}

}