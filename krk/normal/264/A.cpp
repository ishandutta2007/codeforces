#include <cstdio>
#include <iostream>
#include <string>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

string s;

void Go(int n)
{
	if (n == s.length()) { printf("%d\n", n); return; }
	if (s[n - 1] == 'l') {
		Go(n + 1); printf("%d\n", n);
	} else { printf("%d\n", n); Go(n + 1); }
}

int main()
{
	getline(cin, s);
	Go(1);
	return 0;
}