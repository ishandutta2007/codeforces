#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <cctype>
#include <algorithm>
using namespace std;

const int Maxl = 26;

string s;
int freq[Maxl];
int res;

int main()
{
	int n; scanf("%d", &n);
	cin >> s;
	for (int i = 0; i < n; i++) {
		fill(freq, freq + Maxl, 0);
		int j = i;
		int obt = 0;
		while (j < s.length() && islower(s[j])) {
			obt += freq[s[j] - 'a']++ == 0; j++;
		}
		res = max(res, obt);
	}
	printf("%d\n", res);
	return 0;
}