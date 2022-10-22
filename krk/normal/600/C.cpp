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

const int Maxl = 26;

string s;
int freq[Maxl];

int main()
{
	cin >> s;
	for (int i = 0; i < s.length(); i++)
		freq[s[i] - 'a']++;
	int l = 0, r = Maxl - 1;
	while (l < r)
		if (freq[l] % 2 == 0) l++;
		else if (freq[r] % 2 == 0) r--;
		else {
			freq[l]++; freq[r]--;
			l++; r--;
		}
	int lef = 0, rig = s.length() - 1;
	for (int i = 0; i < Maxl; i++)
		while (freq[i] >= 2) {
			freq[i] -= 2;
			s[lef++] = 'a' + i; s[rig--] = 'a' + i;
		}
	for (int i = 0; i < Maxl; i++)
		if (freq[i] == 1) s[lef] = 'a' + i;
	printf("%s\n", s.c_str());
	return 0;
}