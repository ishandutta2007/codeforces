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

set <string> S;
int n;

int main()
{
	cin >> n;
	while (n--) {
		string s; cin >> s;
		if (S.find(s) != S.end()) printf("YES\n");
		else printf("NO\n");
		S.insert(s);
	}
	return 0;
}