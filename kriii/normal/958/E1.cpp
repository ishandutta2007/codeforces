#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;

int gcd(int a, int b)
{
	return b ? gcd(b, a%b) : a;
}

void proc()
{
	int n, m;
	scanf("%d %d", &n, &m);
	puts(n == m ? "Yes" : "No");
}

int main()
{
#ifdef __LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	proc();
	return 0;
}