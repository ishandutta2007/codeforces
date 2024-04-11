#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 200005;
const int Maxm = 400015;

int n;
int H[Maxm], sum[Maxm];
ll res;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a); H[a]++;
	}
	for (int i = 1; i < Maxm; i++) sum[i] = sum[i - 1] + H[i];
	for (int i = 1; i < Maxn; i++) if (H[i] > 0) {
		ll tot = 0;
		for (int j = i; j < Maxn; j += i)
			tot += ll(j) * (sum[j + i - 1] - sum[j - 1]);
		res = max(res, tot); 
	}
	printf("%I64d\n", res);
	return 0;
}