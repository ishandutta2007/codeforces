#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

string s;
int cnt[4];

int main()
{
	getline(cin, s);
	for (int i = 0; i < s.length(); i += 2)
		cnt[s[i] - '0']++;
	bool was = false;
	for (int i = 0; i < 4; i++)
		while (cnt[i]--) {
			if (was) printf("+");
			else was = true;
			printf("%d", i);
		}
	printf("\n");
	return 0;
}