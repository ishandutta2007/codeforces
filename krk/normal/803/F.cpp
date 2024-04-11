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

const int Maxm = 100005;
const int mod = 1000000007;

int pw2[Maxm];
int n;
int cnt[Maxm], res[Maxm];

int main()
{
	pw2[0] = 1;
	for (int i = 1; i < Maxm; i++)
		pw2[i] = 2ll * pw2[i - 1] % mod;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		cnt[a]++;
	}
	for (int i = Maxm - 1; i > 0; i--) {
		int my = 0;
		for (int j = i; j < Maxm; j += i)
			my += cnt[j];
		res[i] = (pw2[my] - 1 + mod) % mod;
		for (int j = i + i; j < Maxm; j += i)
			res[i] = (res[i] - res[j] + mod) % mod;
	}
	printf("%d\n", res[1]);
	return 0;
}