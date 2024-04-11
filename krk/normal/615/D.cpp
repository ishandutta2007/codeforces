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

const int Maxn = 200005;
const int mod = 1000000007;

int m;
int p[Maxn];

int toPower(int a, int p)
{
	int res = 1;
	while (p) {
		if (p & 1) res = ll(res) * a % mod;
		p >>= 1; a = ll(a) * a % mod;
	}
	return res;
}

int main() 
{
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int a; scanf("%d", &a);
		p[a]++;
	}
	int divs = 1;
	for (int i = 1; i < Maxn; i++)
		divs = divs * (p[i] + 1) % 2;
	int res = 1;
	bool tk = false;
	int pw = 1;
	int my = 1;
	if (divs == 1) {
		divs--;
		for (int i = 1; i < Maxn; i++)
			my = ll(my) * toPower(i, p[i] / 2) % mod;
		for (int i = 1; i < Maxn; i++)
			if (p[i] > 0) {
				pw = ll(pw) * (p[i] + 1) % (mod - 1);
			}
	} else {
		for (int i = 1; i < Maxn; i++) {
			if (p[i] % 2 == 1 && !tk) { pw = ll(pw) * ((p[i] + 1) / 2) % (mod - 1); tk = true; }
			else pw = ll(pw) * (p[i] + 1) % (mod - 1);
			my = ll(my) * toPower(i, p[i]) % mod;
		}
	}
	res = ll(res) * toPower(my, pw) % mod;
	printf("%d\n", res);
    return 0;
}