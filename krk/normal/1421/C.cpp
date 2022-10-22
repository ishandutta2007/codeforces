#include <bits/stdc++.h>
using namespace std;

string s;

int main()
{
	cin >> s;
	int len = int(s.length()) - 2;
	printf("3\n");
	printf("R 2\n");
	printf("L %d\n", len + 2);
	printf("L %d\n", len + 1);
    return 0;
}