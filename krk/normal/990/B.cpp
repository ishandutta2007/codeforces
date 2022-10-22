#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int n, k;
int a[Maxn];

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	vector <int> S;
	for (int i = 0; i < n; i++) {
		while (!S.empty() && S.back() < a[i] && a[i] <= S.back() + k)
			S.pop_back();
		S.push_back(a[i]);
	}
	printf("%d\n", int(S.size()));
	return 0;
}