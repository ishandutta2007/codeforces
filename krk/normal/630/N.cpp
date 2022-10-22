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

ld a, b, c;

int main()
{
	cin >> a >> b >> c;
	ld D = b * b - 4 * a * c;
	ld x1 = (-b - sqrt(D)) / (2 * a);
	ld x2 = (-b + sqrt(D)) / (2 * a);
	cout << fixed << setprecision(15) << max(x1, x2) << endl;
	cout << fixed << setprecision(15) << min(x1, x2) << endl;
	return 0;
}