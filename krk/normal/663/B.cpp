#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

typedef long long ll;

int n;
string s;

ll Get(int lvl, ll cur = 1988)
{
	if (lvl < 0) return cur;
	if (cur % 10 < s[lvl] - '0') cur /= 10;
	else cur = cur / 10 + 1;
	return Get(lvl - 1, cur) * 10ll + ll(s[lvl] - '0');
}

int main() 
{
	scanf("%d", &n);
	while (n--) {
		cin >> s;
		int p = s.find("'");
		stringstream ss(s.substr(p + 1));
		s = s.substr(p + 1);
		printf("%I64d\n", Get(int(s.length()) - 1));
	}
    return 0;
}