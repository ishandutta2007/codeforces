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

const int Maxn = 61;

int num[Maxn];
//map <set <int>, int> num[Maxn]; 
int n;
int res;

/*int Gen(int lft, set <int> S)
{
	if (lft == 0) return 0;
	set <int>::iterator sit = S.end();
	while (sit != S.begin()) {
		sit--;
		if (*sit > lft) S.erase(sit++);
		else break;
	}
	map <set <int>, int>::iterator it = num[lft].find(S);
	if (it == num[lft].end()) {
		ll got = 0;
		set <int>::iterator sit = S.begin();
		set <int> tmp = S;
		for (int i = 1; i <= lft; i++)
			if (sit == S.end() || i < *sit) {
				tmp.insert(i);
				got |= 1ll << Gen(lft - i, tmp);
				tmp.erase(i);
			} else sit++;
		int res = 0;
		while (got & 1ll << ll(res)) res++;
		num[lft][S] = res; return res;
	}
	return it->second;
}*/

int main() 
{
	int cur = 2, val = 1;
	int pnt = 1;
	while (pnt <= 60) {
		for (int i = 0; i < cur && pnt <= 60; i++) {
			num[pnt] = val; pnt++;
		}
		cur++; val++;
	}
	scanf("%d", &n);
	while (n--) {
		int a; scanf("%d", &a);
		res ^= num[a];
	}
	printf("%s\n", res? "NO": "YES");
    return 0;
}