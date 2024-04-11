#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 400005;

int n;
int l[Maxn], r[Maxn];
vector <int> un;
int BITL[Maxn], BITR[Maxn];
int res[Maxn];
vector <ii> V;

void Insert(int BIT[], int x)
{
	for (int i = x; i <= un.size(); i += i & -i)
		BIT[i]++;
} 

int Get(int BIT[], int x)
{
	int res = 0;
	for (int i = x; i > 0; i -= i & -i)
		res += BIT[i];
	return res;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &l[i], &r[i]);
		un.push_back(l[i]);
		un.push_back(r[i]);
		V.push_back(ii(r[i], i));
	}
	sort(un.begin(), un.end()); un.erase(unique(un.begin(), un.end()), un.end());
	for (int i = 0; i < n; i++) {
		l[i] = lower_bound(un.begin(), un.end(), l[i]) - un.begin() + 1;
		r[i] = lower_bound(un.begin(), un.end(), r[i]) - un.begin() + 1;
	}
	sort(V.begin(), V.end());
	for (int i = 0; i < V.size(); i++) {
		ii my = V[i];
		res[my.second] = Get(BITR, r[my.second]) - Get(BITL, l[my.second] - 1);
		Insert(BITR, r[my.second]); Insert(BITL, l[my.second]);
	}
	for (int i = 0; i < n; i++)
		printf("%d\n", res[i]);
	return 0;
}