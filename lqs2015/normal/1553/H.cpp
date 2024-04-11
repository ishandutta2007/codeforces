#include <bits/stdc++.h>
#define Accepted 0
using namespace std;
int test, n, k, a[555555];
bool ex[555555];
vector<int> res;
vector<int> calc(int l, int r, int dep)
{
	vector<int> v;
	v.resize(3 * (1 << dep));
	if (l == r)
	{
		if (ex[l]) 
		{
			v[0] = v[1] = 0;
			v[2] = 1e9;
		}
		else
		{
			v[0] = v[2] = 1e9;
			v[1] = -1e9;
		}
		return v;
	}
	int mid = (l + r) >> 1;
	vector<int> v1 = calc(l, mid, dep - 1), v2 = calc(mid + 1, r, dep - 1);
	for (int i = 0; i < (1 << (dep - 1)); i++)
	{
		v[i] = min(v1[i], v2[i] + (1 << (dep - 1)));
		v[i | (1 << (dep - 1))] = min(v1[i] + (1 << (dep - 1)), v2[i]);
		v[(1 << dep) + i] = max(v1[(1 << (dep - 1)) + i], v2[(1 << (dep - 1)) + i] + (1 << (dep - 1)));
		v[(1 << dep) + i + (1 << (dep - 1))] = max(v1[(1 << (dep - 1)) + i] + (1 << (dep - 1)), v2[(1 << (dep - 1)) + i]);
		v[(1 << (dep + 1)) + i] = min(v1[(1 << dep) + i], v2[(1 << dep) + i]);
		if (v1[(1 << (dep - 1)) + i] >= 0 && v2[i] <= (1 << dep)) v[(1 << (dep + 1)) + i] = min(v[(1 << (dep + 1)) + i], v2[i] + (1 << (dep - 1)) - v1[(1 << (dep - 1)) + i]);
		v[(1 << (dep + 1)) + (1 << (dep - 1)) + i] = min(v1[(1 << dep) + i], v2[(1 << dep) + i]);
		if (v1[i] <= (1 << dep) && v2[(1 << (dep - 1)) + i] >= 0) v[(1 << (dep + 1)) + (1 << (dep - 1)) + i] = min(v[(1 << (dep + 1)) + (1 << (dep - 1)) + i], v1[i] + (1 << (dep - 1)) - v2[(1 << (dep - 1)) + i]);
	}
	return v;
}
int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) ex[a[i]] = 1;
	res = calc(0, (1 << k) - 1, k);
	for (int i = (1 << (k + 1)); i < res.size(); i++) printf("%d ", res[i]);
	printf("\n");
	return Accepted;
}