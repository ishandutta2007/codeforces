#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;
const int Maxm = 105 * 2000;

int n;
int a[Maxn];
bool has[Maxm];

bool Even()
{
	for (int i = 0; i < n; i++)
		if (a[i] % 2) return false;
	return true;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	while (Even())
		for (int i = 0; i < n; i++)
			a[i] /= 2;
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += a[i];
	if (sum % 2) { printf("0\n"); return 0; }
	sum /= 2;
	has[0] = true;
	for (int i = 0; i < n; i++)
		for (int j = Maxm - 1; j >= 0; j--) if (has[j])
			has[j + a[i]] = true;
	if (!has[sum]) { printf("0\n"); return 0; }
	for (int i = 0; i < n; i++)
		if (a[i] % 2) { printf("1\n%d\n", i + 1); return 0; }
    return 0;
}