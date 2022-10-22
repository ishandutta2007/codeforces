#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long double ld;

int n, t;

int main()
{
	scanf("%d %d", &n, &t);
	cout << fixed << setprecision(10) << n * pow(1.000000011l, ld(t)) << endl;
	return 0;
}