#include <iostream>
#include <cmath>
#include <assert.h>
#include <vector>
#include <algorithm>
using namespace std;
#define ll unsigned long long
int main() {
	long double a,b,c,d;
	cin >> a;
	cin >> b;
	cin >> c;
	cin >> d;
	long double p = a/b;
	long double q = c/d;
	cout.precision(30);
	cout.setf(ios::fixed,ios::floatfield);
	cout << p/(1-(1-p)*(1-q)) << endl;
	return 0;
}