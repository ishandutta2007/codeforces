#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int tux; cin >> tux;
	int foo = 0, bar = 0, baz = 0, quz = 1;
	while (tux--) {
		int pur; cin >> pur;
		foo += pur; bar++;
		if (max(foo * quz, bar * baz) == foo * quz) {
			baz = foo;
			quz = bar;
		}
	}
	printf("%.6lf\n", double(baz) / quz);
	return 0;
}