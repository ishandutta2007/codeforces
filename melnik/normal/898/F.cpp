#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

#define f first
#define s second
#define pb push_back
#define mp make_pair

const int maxn = 1000500;
const int inf = 2e9;
const double eps = 1e-8;
// const int base = 1073676287;

int base;
int st[maxn];
int pref_sum[maxn];
char t[maxn];

int res[maxn];

void init() {

	base = 1e9 + 7;


	for (int i = 0; i < 1; ++i)
		st[0] = 1;
	for (int i = 1; i < maxn; ++i)
		for (int j = 0; j < 1; ++j)
			st[i] = (1LL * 10 * st[i - 1]) % base;

	for (int i = 0; i < 1; ++i)
		pref_sum[0] = t[0] - '0';
	for (int i = 1; i < maxn; ++i)
		for (int j = 0; j < 1; ++j)
			pref_sum[i] = (1LL * 10 * pref_sum[i - 1] + t[i] - '0') % base;
}

inline void Try(int a_len, int b_len, int sum_len, int n) {
	assert(a_len + b_len + sum_len == n);
	if ((t[0] == '0' && a_len > 1) || (t[a_len] == '0' && b_len > 1) ||
			(t[a_len + b_len] == '0' && sum_len > 1))
		return;
	for (int i = 0; i < 1; ++i) {
		int a = pref_sum[a_len - 1];
		int pref_odd_sum = (1LL * pref_sum[a_len - 1] * st[b_len]) % base;
		int b = (pref_sum[a_len + b_len - 1] - pref_odd_sum + base) % base;
		pref_odd_sum = (1LL * pref_sum[a_len + b_len - 1] * st[sum_len]) % base;
		int c = (pref_sum[a_len + b_len + sum_len - 1] - pref_odd_sum + base) % base;
		if ((a + b) % base != c)
			return;
	}
	for (int i = maxn - 1; i >= 0; --i) {
		int pos1 = a_len - 1 - (maxn - 1 - i);
		int c1 = pos1 >= 0 ? t[pos1] - '0' : 0;

		int pos2 = a_len + b_len - 1 - (maxn - 1 - i);
		int c2 = pos2 >= a_len ? t[pos2] - '0' : 0;
		res[i] = c1 + c2;
	}
	for (int i = maxn - 1; i >= 0; --i)
		if (res[i] >= 10) {
			res[i] -= 10;
			++res[i - 1];
		}
	for (int i = maxn - 1; i >= 0; --i) {
		int pos = n - 1 - (maxn - 1 - i);
		int c = pos >= a_len + b_len ? t[pos] - '0' : 0;
		if (res[i] != c)
			return;
	}

	for (int i = 0; i < a_len; ++i)
		putchar(t[i]);
	putchar('+');
	for (int i = a_len; i < a_len + b_len; ++i)
		putchar(t[i]);
	putchar('=');
	for (int i = a_len + b_len; i < n; ++i)
		putchar(t[i]);
	exit(0);
}

inline void Try1(int sum_len, int n) {
	int a_len = sum_len - 1;
	int b_len = n - sum_len - a_len;
	if (b_len > sum_len || b_len <= 0 || a_len <= 0)
		return;
	Try(a_len, b_len, sum_len, n);
}

inline void Try2(int sum_len, int n) {
	int a_len = sum_len;
	int b_len = n - sum_len - a_len;
	if (b_len > sum_len || b_len <= 0 || a_len <= 0)
		return;
	Try(a_len, b_len, sum_len, n);
}

inline void Try3(int sum_len, int n) {
	int b_len = sum_len - 1;
	int a_len = n - sum_len - b_len;
	if (a_len > sum_len || a_len <= 0 || b_len <= 0)
		return;
	Try(a_len, b_len, sum_len, n);
}

inline void Try4(int sum_len, int n) {
	int b_len = sum_len;
	int a_len = n - sum_len - b_len;
	if (a_len > sum_len || a_len <= 0 || b_len <= 0)
		return;
	Try(a_len, b_len, sum_len, n);
}

int main()
{
    srand(time(0));
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // ios_base::sync_with_stdio(false);
    gets(t);
    int n = strlen(t);
    init();

    for (int sum_len = 1; sum_len <= n; ++sum_len) {
    	Try1(sum_len, n);
    	Try2(sum_len, n);
    	Try3(sum_len, n);
    	Try4(sum_len, n);
    }
    return 0;
}