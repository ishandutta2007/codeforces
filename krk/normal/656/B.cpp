#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;

typedef long double ld;

const int Maxn = 20;

int n;
int M[Maxn], R[Maxn];
int wsh;

bool Check(int x)
{
	for (int i = 0; i < n; i++)
		if (x % M[i] == R[i]) return true;
	return false;
}

int gcd(int a, int b) { return a? gcd(b % a, a): b; }

int main()
{
	int lcm = 1;
	for (int i = 1; i <= 16; i++)
		lcm = lcm / gcd(lcm, i) * i;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &M[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &R[i]);
	for (int i = 0; i < lcm; i++)
		if (Check(i)) wsh++;
	printf("%.10lf\n", double(ld(wsh) / ld(lcm)));
	return 0;
}