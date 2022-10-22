#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

string s;
int res;

int main()
{
	cin >> s;
	for (int i = 0, j; i < s.length(); i = j) {
		j = i + 1;
		while (j < s.length() && s[i] == s[j]) j++;
		if ((j - i) % 2 == 0) res++;
	}
	printf("%d\n", res);
	return 0;
}