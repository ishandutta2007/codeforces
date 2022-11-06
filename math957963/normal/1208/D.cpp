#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;
#define MOD 1000000007
#define f(i,n) for(long long i=0;i<(long long)(n);i++)
#define N (1<<18)
long long a[2 * N];

//
void init(void) {
	f(i, 2 * N)a[i] = 0;
	return;
}

//
void all_insert(long long n) {
	f(i, n) {
		a[(i + N)] = i + 1;
	}
	f(i, N) {
		a[N - i - 1] = a[2 * (N - i - 1)] + a[2 * (N - i - 1) + 1];
	}
	return;
}

//(k=1-n)
void change(long long k, long long x) {
	k += N;
	a[k] = x;
	while (k > 1) {
		k = k / 2;
		a[k] = a[2 * k] + a[2 * k + 1];
	}
	return;
}
//(0<=l<r<=n)(l<=x<r)(l,r,1,0,N)
long long sum_search(long long l, long long r, long long k, long long sl, long long sr) {
	if (r <= sl || sr <= l)return 0;
	else if (l <= sl && sr <= r) return a[k];
	else {
		long long vl = sum_search(l, r, 2 * k, sl, (sl + sr) / 2);
		long long vr = sum_search(l, r, 2 * k + 1, (sl + sr) / 2, sr);
		return (vl + vr);
	}
}


int main() {
	long long aa[N];
	long long bb[N];
	long long n, k;
	long long l, r, m;
	long long x, y, z;
	long long s, ans;
	bool v = true;
	ans = 0;
	scanf("%I64d", &n);
	init();
	all_insert(n);
	f(i, n) {
		scanf("%I64d", &aa[i]);
	}

	for (long long i = n - 1; i >= 0; i--) {
		l = -1;
		r = n+1;
		while (l + 1 < r) {
			m = (l + r) / 2;
			x = sum_search(0, m + 1, 1, 0, N);
			if (x <= aa[i])l = m;
			else r = m;
		}
		bb[i] = r + 1;
		change(r, 0);
	}
	f(i, n - 1)printf("%I64d ", bb[i]);
	printf("%I64d\n", bb[n - 1]);

	return 0;
}