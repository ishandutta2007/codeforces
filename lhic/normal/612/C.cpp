#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>


typedef long long ll;
typedef double ld;

using namespace std;

vector<char> vv;

char s[2000000];
int n;
int ans = 0;

int main() {
	scanf("%s", s);
	n = strlen(s);
	for (int i = 0; i < n; ++i) {
		if (s[i] == '(' || s[i] == '{' || s[i] == '[' || s[i] == '<')
			vv.push_back(s[i]);
		else {
			if (vv.empty()) {
				cout << "Impossible\n";
				return 0;
			}
			if ((vv.back() == '(' && s[i] == ')') || (vv.back() == '[' && s[i] == ']') || (vv.back() == '{' && s[i] == '}') || (vv.back() == '<' && s[i] == '>'))
				vv.pop_back();
			else
				vv.pop_back(), ++ans;
		}
	}
	if (vv.empty()) {
		cout << ans << "\n";
	}
	else {
		cout << "Impossible\n";
	}
	return 0;
}