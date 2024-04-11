#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

const int Maxn = 1005;

int n;
int m;
int a[Maxn], b[Maxn];

bool Ok(ld fuel)
{
	for (int i = 1; i <= n; i++) {
		int ni = i == n? 1: i + 1;
		ld need = (fuel + m) / a[i];
		if (need > fuel) return false;
		fuel -= need;
		need = (fuel + m) / b[ni];
		if (need > fuel) return false;
		fuel -= need;
	}
	return true;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
		scanf("%d", &b[i]);
	ld lef = 0, rig = 2000000000;
	for (int i = 0; i < 70; i++) {
		ld mid = (lef + rig) / 2.0l;
		if (Ok(mid)) rig = mid;
		else lef = mid;
	}
	if (rig > 1500000000) printf("-1\n");
	else cout << fixed << setprecision(10) << rig << endl;
	return 0;
}