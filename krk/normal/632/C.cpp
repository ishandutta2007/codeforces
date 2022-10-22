#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxn = 50005;

char tmp[Maxn];
int n;
string s[Maxn];

bool Less(const string &a, const string &b)
{
	return a + b < b + a;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", tmp);
		s[i] = tmp;
	}
	sort(s, s + n, Less);
	for (int i = 0; i < n; i++)
		printf("%s", s[i].c_str());
	printf("\n");
	return 0;
}