#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

typedef long long ll;

const string let = "fedabc";

string s;

ll toInt(const string &s)
{
	stringstream ss; ss << s;
	ll x; ss >> x;
	return x;
}

ll F(ll x)
{
	return (x - 1ll) / 4ll * 16ll + 7ll * ll(x % 2ll == 0ll);
}

int main()
{
	cin >> s;
	int cp = s.length() - 1;
	ll x = toInt(s.substr(0, cp));
	printf("%I64d\n", F(x) + ll(let.find(s[s.length() - 1])) + 1ll);
	return 0;
}