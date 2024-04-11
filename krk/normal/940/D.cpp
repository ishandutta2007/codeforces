#include <bits/stdc++.h>
using namespace std;

const int lim = 1000000000;
const int Maxn = 100005;

int n;
int a[Maxn], b[Maxn];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++) {
		char ch; scanf(" %c", &ch);
		b[i] = ch == '1';
	}
	int lef = -lim, rig = lim;
	for (int i = 1; i < n; i++)
		if (b[i] != b[i - 1])
			if (b[i] == 0)
				for (int j = 0; j <= 4; j++)
					rig = min(rig, a[i - j] - 1);
			else for (int j = 0; j <= 4; j++)
					lef = max(lef, a[i - j] + 1);
	printf("%d %d\n", lef, rig);
	return 0;
}