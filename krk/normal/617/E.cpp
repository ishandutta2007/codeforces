#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 3000000;
const int Maxm = 330;

int n, m, k;
int a[Maxn];
int M[Maxn];
int l[Maxn], r[Maxn];
vector <ii> rind[Maxm];
ll res;
ll my[Maxn];

void Add(int x)
{
	res += M[x ^ k]; M[x]++; 
}

void Rem(int x)
{
	M[x]--; res -= M[x ^ k];
}

void addInt(int l, int r)
{
	for (int i = l; i <= r; i++)
		Add(a[i]);
}

void remInt(int l, int r)
{
	for (int i = l; i <= r; i++)
		Rem(a[i]);
}

int main() 
{
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		a[i] ^= a[i - 1];
	}
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &l[i], &r[i]); l[i]--;
		if (r[i] - l[i] <= Maxm) {
			addInt(l[i], r[i]);
			my[i] = res;
			remInt(l[i], r[i]);
		} else rind[l[i] / Maxm].push_back(ii(r[i], i));
	}
	for (int i = Maxm; i <= n; i += Maxm) {
		int j = i / Maxm - 1;
		sort(rind[j].begin(), rind[j].end());
		int lstl = i, lstr = i - 1;
		for (int z = 0; z < rind[j].size(); z++) {
			int ind = rind[j][z].second;
			addInt(lstr + 1, r[ind]); lstr = r[ind];
			if (l[ind] < lstl) addInt(l[ind], lstl - 1);
			else if (lstl < l[ind]) remInt(lstl, l[ind] - 1);
			lstl = l[ind];
			my[ind] = res;
		}
		remInt(lstl, lstr);
	}
	for (int i = 0; i < m; i++)
		printf("%I64d\n", my[i]);
    return 0;
}