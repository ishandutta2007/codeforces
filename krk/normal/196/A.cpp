#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

const int Maxn = 100005;

string s;
char S[Maxn];
int len;

int main()
{
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		while (len > 0 && S[len - 1] < s[i]) len--;
		S[len++] = s[i];
	}
	for (int i = 0; i < len; i++)
		printf("%c", S[i]);
	printf("\n");
	return 0;
}