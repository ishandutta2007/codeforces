#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int Maxn = 2000005;

bool prime[Maxn];
int n, a[Maxn];
vector <int> E, O;
int ones;
vector <int> res;

int main()
{
	fill(prime + 2, prime + Maxn, true);
	for (int i = 2; i < Maxn; i++) if (prime[i])
		for (int j = i + i; j < Maxn; j += i) prime[j] = false;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (a[i] == 1) ones++;
		else if (a[i] % 2 > 0) O.push_back(a[i]);
		else E.push_back(a[i]);
	}
	res.push_back(a[0]);
	for (int i = 0; i < O.size(); i++)
		for (int j = 0; j < E.size(); j++)
			if (prime[O[i] + E[j]] && res.size() < 2) {
				res.clear();
				res.push_back(O[i]);
				res.push_back(E[j]);
			}
	if (ones > res.size()) {
		res.clear();
		for (int i = 0; i < ones; i++)
			res.push_back(1);
	}
	for (int i = 0; i < E.size(); i++)
		if (prime[E[i] + 1] && res.size() < ones + 1) {
			res.clear();
			for (int j = 0; j < ones; j++)
				res.push_back(1);
			res.push_back(E[i]);
		}
	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); i++)
		printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
	return 0;
}