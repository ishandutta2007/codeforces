#include <iostream>
#include <cmath>
#include <assert.h>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
int main() {
	ll a,b,c;
	cin >> a;
	cin >> b;
	cin >> c;
	ll e = (a+b-c)/2;
	ll f = b-e;
	ll g = a-e;
	if (e >= 0 && f >= 0 && g >= 0 && e+g == a && e+f == b && f+g == c) {
		cout << e << " " << f << " " << g << endl;
		return 0;
	}
	cout << "Impossible" << endl;
	return 0;
}