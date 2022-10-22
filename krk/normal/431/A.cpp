#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

const int Maxd = 5;

int a[Maxd];
string s;
int res;

int main()
{
	for (int i = 1; i < Maxd; i++)
		scanf("%d", &a[i]);
	cin >> s;
	for (int i = 0; i < s.length(); i++)
		res += a[s[i] - '0'];
	printf("%d\n", res);
	return 0;
}