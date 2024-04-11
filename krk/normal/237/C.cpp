#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 1000005;

bool pr[Maxn];
int sum[Maxn];
int a, b, k;
int res = -1;

bool Enough(int l)
{
	for (int i = a; i + l - 1 <= b; i++)
		if (sum[i + l - 1] - sum[i - 1] < k) return false;
	return true;
}

int main()
{
	fill(pr + 2, pr + Maxn, true);
	for (int i = 2; i < Maxn; i++) {
		sum[i] = sum[i - 1];
		if (pr[i]) {
			sum[i]++;
			for (int j = i + i; j < Maxn; j += i) 
				pr[j] = false;
		}
	}
	scanf("%d %d %d", &a, &b, &k);
	int lef = 1, rig = b - a + 1;
	while (lef <= rig) {
		int mid = lef + rig >> 1;
		if (Enough(mid)) { res = mid; rig = mid - 1; }
		else lef = mid + 1;
	}
	printf("%d\n", res);
	return 0;
}