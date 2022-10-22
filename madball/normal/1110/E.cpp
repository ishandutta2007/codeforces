#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
typedef long long lint, ll;
typedef long double ld, ldouble;

#define For(i, n) for (int (i) = 0; (i) < (int)(n); (i)++)
#define sz(x) (int)(x).size()
#define all(v) (v).begin(), (v).end()

#ifdef LOCAL
#pragma comment(linker, "/STACK:16777216")
#endif

void solve()
{
	int n;
	cin >> n;
	vector<lint> ar(n), br(n);
	For(i, n)
		cin >> ar[i];
	For(i, n)
		cin >> br[i];
	if (ar[0] != br[0] || ar.back() != br.back())
	{
		cout << "No\n";
		return;
	}
	vector<lint> ar2(n - 1), br2(n - 1);
	For(i, n - 1)
		ar2[i] = ar[i + 1] - ar[i];
	For(i, n - 1)
		br2[i] = br[i + 1] - br[i];
	sort(all(ar2));
	sort(all(br2));
	cout << (ar2 == br2 ? "Yes\n" : "No\n");
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	solve();
#ifdef LOCAL
	printf("\n\n%.3lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif
}