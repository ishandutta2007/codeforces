#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 300005;
const int Maxm = 1000005;

int n, k;
int a[Maxn];
int A[Maxm], B[Maxm];
ll res;

int getNeed(int mx, int hasb) { return (mx - hasb + k) % k; }

void Calc(int l, int r)
{
	if (l == r) return;
	int m = l + r >> 1;
	Calc(l, m); Calc(m + 1, r);
	int hasa = a[m] % k; A[hasa]++;
	int hasb = a[m + 1] % k; B[hasb]++;
	int i = m - 1, j = m + 2;
	int mx = max(a[m], a[m + 1]);
	bool lef = a[m] >= a[m + 1];
	while (true) {
		if (lef) {
			while (j <= r && a[j] <= mx) { hasb = (hasb + a[j]) % k; B[hasb]++; j++; }
			int nd = getNeed(mx, hasa);
			res += B[nd];
			while (i >= l && a[i] < mx) {
				hasa = (hasa + a[i]) % k; A[hasa]++; i--;
				nd = getNeed(mx, hasa);
				res += B[nd];
			}
		} else {
			while (i >= l && a[i] < mx) { hasa = (hasa + a[i]) % k; A[hasa]++; i--; }
			int nd = getNeed(mx, hasb);
			res += A[nd];
			while (j <= r && a[j] <= mx) { 
				hasb = (hasb + a[j]) % k; B[hasb]++; j++;
				nd = getNeed(mx, hasb);
				res += A[nd];
			}
		}
		if (i < l && j > r) break;
		mx = i >= l && (j > r || a[i] <= a[j])? a[i]: a[j];
		if (j <= r && mx == a[j]) { hasb = (hasb + a[j]) % k; B[hasb]++; j++; lef = false; }
		else { hasa = (hasa + a[i]) % k; A[hasa]++; i--; lef = true; } 
	}
	hasa = 0;
	for (int i = m; i >= l; i--) {
		hasa = (hasa + a[i]) % k; A[hasa] = 0;
	}
	hasb = 0;
	for (int j = m + 1; j <= r; j++) {
		hasb = (hasb + a[j]) % k; B[hasb] = 0;
	}
}

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	Calc(0, n - 1);
	printf("%I64d\n", res);
	return 0;
}