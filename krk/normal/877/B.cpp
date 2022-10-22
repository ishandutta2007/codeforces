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

const int Maxn = 5005;

string s;
int cnt[Maxn];
int res;

int main()
{
	cin >> s;
	cnt[s.length()] = 0;
	for (int i = int(s.length()) - 1; i >= 0; i--)
		cnt[i] = cnt[i + 1] + bool(s[i] == 'a');
	int cnt1 = 0;
	for (int i = 0; i <= s.length(); i++) {
		int cur = cnt1;
		for (int j = i; j <= s.length(); j++) {
			res = max(res, cur + cnt[j]);
			if (j < s.length()) cur += bool(s[j] == 'b');
		}
		if (i < s.length()) cnt1 += bool(s[i] == 'a');
	}
	printf("%d\n", res);
	return 0;
}