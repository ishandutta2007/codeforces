#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

typedef long long ll;

const int mod = 1000000007;

string x;
int res;

int main()
{
	cin >> x;
	res = 0;
	for (int i = 0; i < x.length(); i++)
		res = (2 * res + (x[i] - '0')) % mod;
	for (int i = 0; i < x.length() - 1; i++)
		res = 2 * res % mod;
	printf("%d\n", res);
	return 0;
}