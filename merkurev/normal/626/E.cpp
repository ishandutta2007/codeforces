#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;

const int N = (int) 2e5 + 100;
int a[N];
int n;

long long ps[N];

vector <int> answer;
long long ans = 0, anscnt = 1, ansmid = -1;


void solve()
{
	for (int i = 1; i < N; i++)
		ps[i] = ps[i - 1] + a[i - 1];

	for (int mid = 0; mid < n; mid++)
	{
		int l = 0, r = min(mid, n - mid - 1);
		while (r - l > 1)
		{
			int m = (l + r) / 2;
			long long A = ps[mid] - ps[mid - m] + ps[n] - ps[n - m] + a[mid];
//			eprintf("%lld %lld %lld %lld %d\n", ps[mid], ps[mid - m], ps[n], ps[n - m], a[mid] );
			long long k = m * 2 + 1;
			long long a1 = a[mid - m - 1], a2 = a[n - m - 1];
//			eprintf("m = %d, %lld .. %lld\n", m, (a1 + a2) * k, 2 * A);
			if ( (a1 + a2) * k >= 2 * A)
				l = m;
			else
				r = m;
		}
		long long A = ps[mid] - ps[mid - r] + ps[n] - ps[n - r] + a[mid];
		long long k = r * 2 + 1;
		A -= a[mid] * k;

//		eprintf("mid = %d, r = %d, A = %lld, k = %lld\n", mid, r, A, k);

		if (A * anscnt >= ans * k)
		{
			ans = A;
			anscnt = k;
			ansmid = mid;
		}
	}
	for (int i = 0; i < anscnt / 2; i++)
	{
		answer.push_back(a[ansmid - i - 1] );
		answer.push_back(a[n - i - 1] );
	}
	answer.push_back(a[ansmid] );
	sort(answer.begin(), answer.end() );

//	printf("%lld\n", (ans * (long long)1e9) / anscnt);

	printf("%d\n", (int) answer.size() );
	for (int x : answer)
		printf("%d ", x);
	printf("\n");

}

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i] );
	sort(a, a + n);

	solve();


	return 0;
}