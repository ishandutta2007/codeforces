#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

string a, b;
int res;

bool Win(char a, char b)
{
	return a == '8' && b == '[' ||
		   a == '[' && b == '(' ||
		   a == '(' && b == '8';
}

int Res(char a, char b)
{
	if (a == b) return 0;
	return Win(a, b)? 1: -1;
}

int main()
{
	cin >> a >> b;
	for (int i = 0; i < a.length(); i += 2)
		res += Res(a[i], b[i]);
	if (res > 0) printf("TEAM 1 WINS\n");
	else if (res == 0) printf("TIE\n");
	else printf("TEAM 2 WINS\n");
	return 0;
}