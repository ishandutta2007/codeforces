#include <algorithm>
#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

typedef long long ll;

const int Maxn = 4005;
const int Maxm = 40005;

int a;
string s;
int sum[Maxn];
int has[Maxm];
ll res;

ll Get(int x) { return x >= Maxm? 0: has[x]; }

int main()
{
	cin >> a >> s;
	for (int i = 0; i < s.length(); i++)
		sum[i + 1] = sum[i] + (s[i] - '0');
	for (int i = 1; i <= s.length(); i++)
		for (int j = i; j <= s.length(); j++)
			has[sum[j] - sum[i - 1]]++;
	if (a == 0) {
		int all = s.length() * (s.length() - 1) / 2 + s.length();
		res = ll(has[0]) * ll(all) * 2ll - ll(has[0]) * ll(has[0]);
	} else {
		for (int i = 1; i * i <= a; i++)
			if (a % i == 0) {
				int j = a / i;
				ll st = 1 + (i != j);
				res += st * Get(i) * Get(j);
			}
	}
	printf("%I64d\n", res);
	return 0;
}