#include <iostream>
#include <iomanip>
#include <cstdio>
#include <stdio.h>
#include <cstdlib>
#include <bitset>
#include <memory>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <stack>
#include <complex>
#include <wchar.h>
#include <wctype.h>
#include <cmath>
#include <queue>
#include <ctime>
#include <numeric>
#include <bitset>
#include <sstream>
//#include <random>

using namespace std;

template<typename T> T mabs(const T &a){ return a<0 ? -a : a; }
#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define SQR(x) ((x)*(x))
#define all(c) (c).begin(), (c).end()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef short int si;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, int> pdi;

ll gcd(ll a, ll b) {
	while (a) {
		b %= a;
		swap(a, b);
	}
	return b;
}

ll calc(ll x) {
	ll res = 0;
	rep(i, 1, x + 1) {
		if (x % i == 0 && gcd(i, x / i) == 1)
			res += i;
	}
	return res;
}

pii probs[1005];
int n;

int dyn[1005][1005];
int getDyn(int i, int j) {
	int &cv = dyn[i][j];
	if (cv != -1)
		return cv;
	if (j == 0)
		return 0;
	if (i == n)
		return 0;
	int dt = probs[i + 1].first - probs[i].first;
	int timeMul = 1005;
	if (dt < 10)
		timeMul = 1 << dt;
	int timeLeftTake = timeMul * (j - 1);
	if (timeLeftTake > 1002)
		timeLeftTake = 1002;
	int val1 = probs[i].second + getDyn(i + 1, timeLeftTake);
	int timeLeftSkip = timeMul * j;
	if (timeLeftSkip > 1002)
		timeLeftSkip = 1002;
	int val2 = getDyn(i + 1, timeLeftSkip);
	cv = max(val1, val2);
	return cv;
}

void run()
{
	memset(dyn, -1, sizeof(dyn));
	scanf("%d", &n);
	int T;
	scanf("%d", &T);
	rep(i, 0, n) {
		int t, q;
		scanf("%d%d", &t, &q);
		probs[i] = pii(T - t, q);
	}
	sort(probs, probs + n);
	probs[n] = probs[n - 1];
	int startTime = 1002;
	if (probs[0].first < 10) {
		startTime = 1 << probs[0].first;
	}
	int res = getDyn(0, startTime);
	printf("%d\n", res);
	//rep(i, 1, 1000) {
	//	ll cres = calc(i);
	//	cout << cres << endl;
	//}
}

int main()
{
#ifdef LOCAL_DEBUG
	freopen("test.in", "r", stdin);
	freopen("test.out","w",stdout);
	time_t st = clock();
#else
#ifdef prob
	freopen(prob".in", "r", stdin);
	//freopen(prob".out","w",stdout);
#endif
#endif
	run();
#ifdef LOCAL_DEBUG
	printf("\n=============\n");
	printf("Time: %.2lf sec\n", (clock() - st) / double(CLOCKS_PER_SEC));
#endif

	return 0;
}