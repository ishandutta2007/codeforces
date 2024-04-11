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

const int Inf = 1000000000;

int k;
string s;
vector <string> V;

int Need(int w)
{
	int lft = 0, tk = 0;
	for (int i = 0; i < V.size(); i++) {
		int my = V[i].length() + int(i + 1 < V.size());
		if (my > lft) {
			lft = w; tk++;
			if (my > lft) return Inf;
			lft -= my;
		} else lft -= my;
	}
	return tk;
}

int main()
{
	scanf("%d", &k); getline(cin, s);
	getline(cin, s);
	int i = 0;
	while (i < s.length()) {
		int j = i;
		while (j < s.length() && s[j] != '-' && s[j] != ' ') j++;
		V.push_back(s.substr(i, j - i));
		i = j + 1;
	}
	int lef = 1, rig = 10000000;
	while (lef <= rig) {
		int mid = lef + rig >> 1;
		if (Need(mid) <= k) rig = mid - 1;
		else lef = mid + 1;
	}
	printf("%d\n", rig + 1);
	return 0;
}