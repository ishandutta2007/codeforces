#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int A, B, C, D;
	A = a ^ b;
	B = c | d;
	C = b & c;
	D = a ^ d;
	cout << ((A & B) ^ (C | D));

	return 0;
}