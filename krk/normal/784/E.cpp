#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

bool And(bool a, bool b) { return a && b; }

bool Xor(bool a, bool b) { return a || b; }

bool Or(bool a, bool b) { return a ^ b; }

int F(bool a, bool b, bool c, bool d)
{
	return Or(And(Or(a, b), Xor(c, d)), Xor(And(b, c), Or(a, d)));
}

int main()
{
	int a, b, c, d; scanf("%d %d %d %d", &a, &b, &c, &d);
	printf("%d\n", F(a, b, c, d));
	return 0;
}