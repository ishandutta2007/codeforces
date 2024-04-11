#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int n;
int a[Maxn];
int freq[Maxn];
ll res;

bool Palin()
{
	int l = 0, r = n - 1;
	while (l < r)
		if (a[l] != a[r]) return false;
		else l++, r--;
	return true;
}

bool canBePalin()
{
	for (int i = 0; i < n; i++)
		freq[a[i]]++;
	int odd = 0;
	for (int i = 1; i <= n; i++)
		odd += freq[i] % 2;
	return odd <= 1;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	if (Palin()) { printf("%I64d\n", ll(n) * (n + 1) / 2); return 0; }
	if (!canBePalin()) { printf("0\n"); return 0; }
	int d = 0;
	while (a[d] == a[n - 1 - d]) d++;
	res += ll(d + 1) * (d + 1);
	int h = d, lst = 0;
	for (int i = d; i < n - 1 - i; i++) {
		if (a[i] != a[n - 1 - i]) h = i;
		lst = i;
	}
	fill(freq + 1, freq + n + 1, 0);
	for (int i = d; i <= h; i++) {
		freq[a[i]]++; freq[a[n - 1 - i]]--;
	}
	bool ok = true;
	for (int i = 1; i <= n && ok; i++)
		ok = freq[i] == 0;
	if (ok) res += 2ll * ll(lst - h + 1) * (d + 1);

	int neg = 0;
	fill(freq + 1, freq + n + 1, 0);
	for (int i = d; i <= lst; i++) {
		freq[a[i]]++; freq[a[n - 1 - i]]--;
	}
	if (n % 2) freq[a[n / 2]]--;
	for (int i = 1; i <= n; i++)
		neg += freq[i] < 0;
	for (int i = lst + 1; i < n - 1 - d; i++) {
		bool flag = freq[a[i]] < 0;
		freq[a[i]] += 2;
		if (freq[a[i]] >= 0 && flag) neg--;
		if (neg == 0) res += d + 1;
	}

	neg = 0;
	fill(freq + 1, freq + n + 1, 0);
	for (int i = d; i <= lst; i++) {
		freq[a[i]]--; freq[a[n - 1 - i]]++;
	}
	if (n % 2) freq[a[n / 2]]--;
	for (int i = 1; i <= n; i++)
		neg += freq[i] < 0;
	for (int i = n - 1 - lst - 1; i > d; i--) {
		bool flag = freq[a[i]] < 0;
		freq[a[i]] += 2;
		if (freq[a[i]] >= 0 && flag) neg--;
		if (neg == 0) res += d + 1;
	}
	
	printf("%I64d\n", res);
	return 0;
}