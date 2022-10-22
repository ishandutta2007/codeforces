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

typedef long long ll;

const int mod = 1000000007;

string s;
int res;

int main()
{
	cin >> s;
	int cur = 0;
	for (int i = s.length() - 1; i >= 0; i--)
		if (s[i] == 'b') cur = (cur + 1) % mod;
		else {
			res = (res + cur) % mod;
			cur = 2ll * cur % mod;
		}
	printf("%d\n", res);
	return 0;
}