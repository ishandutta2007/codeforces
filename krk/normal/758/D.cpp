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
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 80;
const ll Inf = 4000000000000000000ll;

int n;
string s;
string sn;
ll best[Maxn];

ll toInt(const string &s)
{
	stringstream ss(s);
	ll num; ss >> num;
	return num;
}

ll Mult(ll a, ll b)
{
	if (a == 0 || b == 0) return 0;
	if (a <= Inf / b) return a * b;
	return Inf;
}

ll Add(ll a, ll b)
{
	return min(a + b, Inf);
}

ll Get(int ind)
{
	if (ind < 0) return 0;
	if (best[ind] < 0) {
		best[ind] = Inf;
		for (int i = 0; i <= ind; i++) {
			string my = s.substr(i, ind - i + 1);
			if (my.length() > sn.length() || my[0] == '0' && my.length() > 1) continue;
			if (my.length() < sn.length() || my < sn) best[ind] = min(best[ind], Add(Mult(Get(i - 1), n), toInt(my)));
		}
	}
	return best[ind];
}

int main() 
{
	cin >> n >> s;
	stringstream ss; ss << n;
	ss >> sn;
	fill(best, best + Maxn, -1ll);
	printf("%I64d\n", Get(int(s.length()) - 1));
    return 0;
}