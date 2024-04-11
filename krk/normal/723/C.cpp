#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int Maxn = 2005;

int n, m;
int mn, mx;
int a[Maxn];
int freq[Maxn];
vector <int> un, un2;
int res;

int main()
{
	scanf("%d %d", &n, &m);
	mn = n / m, mx = n / m + bool(n % m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (a[i] <= m)
			if (freq[a[i]] + 1 > mn) un2.push_back(i);
			else freq[a[i]]++;
		else un.push_back(i);
	}
	for (int i = 1; i <= m; i++)
		while (freq[i] < mn) {
			if (!un.empty()) { a[un.back()] = i; un.pop_back(); }
			else { a[un2.back()] = i; un2.pop_back(); }
			freq[i]++; res++;
		}
	printf("%d %d\n", mn, res);
	for (int i = 0; i < n; i++)
		printf("%d%c", a[i], i + 1 < n? ' ': '\n');
	return 0;
}