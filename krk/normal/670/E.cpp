#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 500005;

int n, m, p;
char str[Maxn];
ii er[Maxn];
int L[Maxn], R[Maxn];

int main()
{
	scanf("%d %d %d", &n, &m, &p);
	scanf("%s", str + 1);
	stack <int> S;
	for (int i = 1; i <= n; i++)
		if (str[i] == '(') S.push(i);
		else { er[S.top()] = er[i] = ii(S.top(), i); S.pop(); }
	for (int i = 0; i <= n; i++)
		R[i] = i + 1;
	for (int i = 1; i <= n + 1; i++)
		L[i] = i - 1;
	while (m--) {
		char ch; scanf(" %c", &ch);
		if (ch == 'L') p = L[p];
		else if (ch == 'R') p = R[p];
		else {
			R[L[er[p].first]] = R[er[p].second];
			L[R[er[p].second]] = L[er[p].first];
			if (R[L[er[p].first]] != n + 1) p = R[L[er[p].first]];
			else p = L[er[p].first];
		}
	}
	for (int i = R[0]; i <= n; i = R[i])
		printf("%c", str[i]);
	printf("\n");
	return 0;
}