#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <queue>
#include <iomanip>
#include <algorithm>
using namespace std;

string s;
vector <int> P, A;

bool Pos(int x)
{
	int pnt = 0;
	for (int i = 0; i < P.size() && pnt < A.size(); i++) {
		int L = P[i], R = P[i];
		while (pnt < A.size()) {
			L = min(L, A[pnt]); R = max(R, A[pnt]);
			int lef = P[i] - L, rig = R - P[i];
			if (2 * min(lef, rig) + max(lef, rig) <= x) pnt++;
			else break;
		}
	}
	return pnt >= A.size();
}

int main()
{
	int n; cin >> n;
	cin >> s;
	for (int i = 0; i < s.length(); i++)
		if (s[i] == 'P') P.push_back(i);
		else if (s[i] == '*') A.push_back(i);
	int l = 0, r = 1000000;
	while (l <= r) {
		int m = l + r >> 1;
		if (Pos(m)) r = m - 1;
		else l = m + 1;
	}
	printf("%d\n", r + 1);
	return 0;
}