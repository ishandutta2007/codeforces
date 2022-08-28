#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__);fflush(stderr);
#else
	#define eprintf(...) 42
#endif

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
	return (ull)rng() % B;
}

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

const int N = 1010;
const int K = 60;
int n, m;
char s[N];
int a[N];
int b[K], c[K];

int chooseMove(ll A, ll B) {
	return myRand(A + B) >= A;
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	while(m--) {
		scanf("%s", s);
		for (int i = 0; i < K; i++)
			b[i] = c[i] = 0;
		int mn = (int)1e9;
		for (int i = 0; i < n; i++)
			mn = min(mn, a[i]);
		for (int i = 0; i < n; i++) {
			int k = a[i] - mn;
			if (k >= K) continue;
			if (s[i] == '0')
				b[k]++;
			else
				c[k]++;
		}
		ll A = 0, B = 0;
		for (int k = 0; k < K / 2; k++) {
			A = A * 2 + b[k];
			B = B * 2 + c[k];
		}
		int w = chooseMove(A, B);
		printf("%d\n", w);
		fflush(stdout);
		scanf("%d", &w);
		for (int i = 0; i < n; i++) {
			a[i] += ((int)(s[i] - '0') != w);
		}
	}

	return 0;
}