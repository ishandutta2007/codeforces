#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

typedef long long ll;

const ll mod = 100000;

string s;

int main()
{
	cin >> s;
	ll num = 10000 * (s[0] - '0') + 1000 * (s[2] - '0') + 100 * (s[4] - '0') + 10 * (s[3] - '0') + (s[1] - '0');
	ll res = num * num % mod * num % mod * num % mod * num % mod;
	cout << setfill('0') << setw(5) << res << endl;
	return 0;
}