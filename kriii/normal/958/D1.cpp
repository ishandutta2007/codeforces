#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;

int gcd(int a, int b)
{
	return b ? gcd(b, a%b) : a;
}

void proc()
{
	std::ios::sync_with_stdio(false);
	int n; cin >> n;
	map<pair<int, int>, vector<int> > pos;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (auto &c : s) {
			if (c == '(' || c == ')' || c == '+' || c == '/') c = ' ';
		}

		istringstream in(s);
		int a, b, c;
		in >> a >> b >> c;

		int g = (gcd(a + b, c));
		pos[{(a + b) / g, c / g}].push_back(i+1);
	}

	int ans[200100];
	for (auto &p : pos) {
		for (auto &v : p.second) ans[v] = p.second.size();
	}

	for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
}

int main()
{
#ifdef __LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	proc();
	return 0;
}