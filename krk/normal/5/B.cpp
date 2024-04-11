#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector <string> V;
string s;
int mx;

int main()
{
	while (getline(cin, s)) {
		V.push_back(s);
		mx = max(mx, (int)s.length());
	}
	printf("%s\n", string(mx + 2, '*').c_str());
	bool swp = false;
	for (int i = 0; i < V.size(); i++) {
		int lft = mx - V[i].length();
		int l = lft / 2, r = lft - l;
		if (l != r) {
			if (swp) swap(l, r);
			swp = !swp;
		}
		printf("*%s%s%s*\n", string(l, ' ').c_str(), V[i].c_str(), string(r, ' ').c_str());
	}
	printf("%s\n", string(mx + 2, '*').c_str());
	return 0;
}