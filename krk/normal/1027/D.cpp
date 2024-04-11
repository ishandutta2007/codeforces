#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int n;
int c[Maxn];
int a[Maxn];
bool tk[Maxn];
int in[Maxn];
int res;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &c[i]);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		in[a[i]]++;
	}
	vector <int> Q;
	for (int i = 1; i <= n; i++)
		if (in[i] == 0) Q.push_back(i);
	for (int i = 0; i < Q.size(); i++) {
		tk[Q[i]] = true;
		if (--in[a[Q[i]]] == 0) Q.push_back(a[Q[i]]);
	}
	for (int i = 1; i <= n; i++) if (!tk[i]) {
		int mn = Maxn;
		int cur = i;
		while (!tk[cur]) {
			tk[cur] = true; mn = min(mn, c[cur]);
			cur = a[cur];
		}
		res += mn;
	}
	printf("%d\n", res);
	return 0;
}