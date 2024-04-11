#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int n, m;
string s;
string t;
int L[Maxn], R[Maxn];

int main()
{
	cin >> n >> m;
	cin >> s;
	cin >> t;
	int pnt = 0;
	for (int i = 0; i < n; i++)
		if (pnt < m && s[i] == t[pnt]) { L[pnt] = i; pnt++; }
	pnt = int(t.length()) - 1;
	for (int i = n - 1; i >= 0; i--)
		if (pnt >= 0 && s[i] == t[pnt]) { R[pnt] = i; pnt--; }
	int mx = 0;
	for (int i = 0; i + 1 < m; i++)
		mx = max(mx, R[i + 1] - L[i]);
	printf("%d\n", mx);
    return 0;
}