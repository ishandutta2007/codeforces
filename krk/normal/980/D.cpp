#include <bits/stdc++.h>
using namespace std;

const int Maxn = 5005;
const int Inf = 2000000017;

int n;
int a[Maxn];
vector <int> un;
int cnt[Maxn], tot;
int res[Maxn];

int Solve(int x)
{
	for (int i = 2; i * i <= x; i++) 
	    while (x % (i * i) == 0)
		    x /= (i * i);
	return x;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (a[i] == 0) { a[i] = Inf; continue; }
		if (a[i] < 0) a[i] = -Solve(abs(a[i]));
		else a[i] = Solve(a[i]);
		un.push_back(a[i]);
	}
	sort(un.begin(), un.end()); un.erase(unique(un.begin(), un.end()), un.end());
	for (int i = 0; i < n; i++) if (a[i] != Inf)
		a[i] = lower_bound(un.begin(), un.end(), a[i]) - un.begin();
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (a[j] != Inf)
				if (cnt[a[j]]++ == 0) tot++;
			res[max(1, tot)]++; 
		}
		for (int j = i; j < n; j++) if (a[j] != Inf)
			cnt[a[j]] = 0;
		tot = 0;
	}
	for (int i = 1; i <= n; i++)
		printf("%d%c", res[i], i + 1 <= n? ' ': '\n');
	return 0;
}