#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string s;
int res;

int Get(char a, char b) {
	int dif = b - a;
	while (dif < 0) dif += 26;
	return dif;
}

int main()
{
	cin >> s;
	char cur = 'a';
	for (int i = 0; i < s.length(); i++) {
		res += min(Get(cur, s[i]), Get(s[i], cur));
		cur = s[i];
	}
	printf("%d\n", res);
	return 0;
}