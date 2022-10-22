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

const int Maxn = 1005;

int n, m;
string s, t;
int res = Maxn, bi;
bool rep[Maxn];

int Solve(int a)
{
	int res = 0;
	for (int i = 0; i < s.length(); i++) {
		res += s[i] != t[a + i];
		rep[i] = s[i] != t[a + i];
	}
	return res;
}

int main()
{
	cin >> n >> m;
	cin >> s >> t;
	for (int i = 0; i + s.length() <= t.length(); i++) {
		int got = Solve(i);
		if (got < res) { res = got; bi = i; }
	}
	Solve(bi);
	vector <int> res;
	for (int i = 0; i < s.length(); i++)
		if (rep[i]) res.push_back(i + 1);
	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); i++)
		printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
	return 0;
}