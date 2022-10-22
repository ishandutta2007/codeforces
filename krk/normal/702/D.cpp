#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;

ll d, k, a, b, t;

int main()
{
	scanf("%I64d %I64d %I64d %I64d %I64d", &d, &k, &a, &b, &t);
	ll go = min(k, d);
	ll res1 = go * a + (d - go) * b;
	ll res2 = d * a + (d - 1) / k * t;
	go = d / k * k;
	ll res3 = go * a + (d - go) * b + (go - 1) / k * t;
	cout << min(res1, min(res2, res3)) << endl;
	return 0;
}