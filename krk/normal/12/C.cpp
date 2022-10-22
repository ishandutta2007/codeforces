#include <cstdio>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

const int Maxn = 105;

int n, m;
int a[Maxn];
map <string, int> freq;
int b[Maxn];
int res1, res2;

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	for (int i = 0; i < m; i++) {
		string s; cin >> s;
		freq[s]++;
	}
	m = 0;
	for (map <string, int>::iterator it = freq.begin(); it != freq.end(); it++)
		b[m++] = it->second;
	sort(b, b + m);
	for (int i = 0; i < m; i++) {
		res1 += a[i] * b[m - 1 - i]; res2 += a[n - 1 - i] * b[m - 1 - i];
	}
	printf("%d %d\n", res1, res2);
	return 0;
}