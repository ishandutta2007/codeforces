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

const int Maxn = 1000005;

int n;
string s;
int wh[Maxn][2];
vector <int> pos, vpos;
vector <int> neg, vneg;

int main() 
{
	getline(cin, s);
	for (int i = 0; i < s.length(); i++)
		if (s[i] == '?') {
			int j = i - 1;
			while (j >= 0 && s[j] != '-' && s[j] != '+') j--;
			if (j < 0 || s[j] == '+') { wh[i][0] = 0; wh[i][1] = pos.size(); pos.push_back(i); }
			else { wh[i][0] = 1; wh[i][1] = neg.size(); neg.push_back(i); }
		}
	int ind = s.find("=");
	stringstream ss(s.substr(ind + 1));
	ss >> n;
	int mn = pos.size() - n * neg.size(), mx = n * pos.size() - neg.size();
	if (mn <= n && n <= mx) {
		printf("Possible\n");
		vpos = vector <int>(pos.size(), 1);
		for (int i = 0; i < vpos.size(); i++) {
			int tk = min(n - mn, n - vpos[i]);
			vpos[i] += tk; mn += tk;
		}
		vneg = vector <int>(neg.size(), n);
		for (int i = 0; i < vneg.size(); i++) {
			int tk = min(n - mn, vneg[i] - 1);
			vneg[i] -= tk; mn += tk;
		}
		for (int i = 0; i < s.length(); i++)
			if (s[i] == '?')
				printf("%d", wh[i][0] == 0? vpos[wh[i][1]]: vneg[wh[i][1]]);
			else printf("%c", s[i]);
		printf("\n");
	} else printf("Impossible\n");
    return 0;
}