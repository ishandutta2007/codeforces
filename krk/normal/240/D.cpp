#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

const int Maxn = 100005;

int n, m;
int a[Maxn], b[Maxn];
vector <int> ind;
int res;
stack <int> S;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	for (int i = n - 1; i >= 0; i--)
		scanf("%d", &a[i]);
	scanf("%d", &m);
	for (int j = m - 1; j >= 0; j--)
		scanf("%d", &b[j]);
	int l = 0, r = 0;
	res = -1;
	int cur = 0;
	while (l < n || r < m) {
		int cnt = 0;
		while (l < n && a[l] == cur) { ind.push_back(n - l); l++; cnt++; }
		while (r < m && b[r] == cur) { ind.push_back(n + m - r); r++; cnt++; }
		S.push(cnt);
		res++;
		cur = 1 - cur;
	}
	for (int i = ind.size() - 1; i >= 0; i--) 
		printf("%d%c", ind[i], i? ' ': '\n');
	printf("%d\n", res);
	int sum = 0;
	while (res) {
		sum += S.top(); S.pop();
		printf("%d", sum);
		printf("%c", --res? ' ': '\n');
	}
	return 0;
}