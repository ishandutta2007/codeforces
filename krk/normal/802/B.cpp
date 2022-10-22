#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 400004;

int n, k;
int a[Maxn];
int nxt[Maxn];
int lst[Maxn];
set <ii> S;
int res;

int main()
{
	fill(lst, lst + Maxn, Maxn);
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = n - 1; i >= 0; i--) {
		nxt[i] = lst[a[i]]; lst[a[i]] = i;
	}
	for (int i = 0; i < n; i++) {
		if (S.find(ii(i, a[i])) == S.end()) {
			res++;
			if (S.size() >= k) {
				set <ii>::iterator it = S.end(); it--;
				S.erase(it);
			}
		}
		S.erase(ii(i, a[i]));
		S.insert(ii(nxt[i], a[i]));
	}
	printf("%d\n", res);
	return 0;
}