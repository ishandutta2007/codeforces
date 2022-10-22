#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef unsigned int uint;

const int Maxp = 132;

uint n, p, q;
uint has[Maxp], add;
uint my[Maxp];
uint res;

void Add(uint x)
{
	for (uint i = 2; i < Maxp && i <= x; i++)
		while (x % i == 0) { has[i]++; x /= i; }
	add *= x;
}

void Rem(uint x)
{
	for (uint i = 2; i < Maxp && i <= x; i++)
		while (x % i == 0) { has[i]--; x /= i; }
}

uint C(uint n, uint k)
{ 
	fill(has, has + Maxp, 0); add = 1;
	for (uint i = n; i > n - k; i--)
		Add(i);
	for (uint i = 1; i <= k; i++)
		Rem(i);
	for (uint i = 1; i < Maxp; i++)
		for (uint j = 0; j < has[i]; j++) add *= i;
	return add;
}

int main()
{
	cin >> n >> p >> q;
	if (p >= n) p = n - 1;
	for (uint i = 0; i <= p; i++)
		my[i] = C(n, i);
	for (uint i = 1; i <= q; i++) {
		uint ans = 0;
		uint cur = 1;
		for (uint j = 0; j <= p; j++) {
			ans += i * cur * my[j];
			cur *= i;
		}
		res ^= ans;
	}
	cout << res << endl;
	return 0;
}