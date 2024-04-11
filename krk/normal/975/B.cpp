#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 14;

int a[Maxn];
int b[Maxn];
ll res;

int main()
{
	for (int i = 0; i < Maxn; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < Maxn; i++) {
		for (int j = 0; j < Maxn; j++)
			b[j] = a[j];
		int my = a[i]; b[i] = 0;
		for (int j = 0; j < Maxn; j++)
			b[j] += my / Maxn;
		my %= Maxn;
		int pos = i;
		while (my) {
			pos = (pos + 1) % Maxn;
			b[pos]++;
			my--;
		}
		ll cand = 0;
		for (int j = 0; j < Maxn; j++)
			if (b[j] % 2 == 0) cand += b[j];
		res = max(res, cand);
	}
	cout << res << endl;
	return 0;
}