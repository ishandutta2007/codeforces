#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int n, a, b;
string s;

int main()
{
	cin >> n >> a >> b; a--; b--;
	if (a > b) swap(a, b);
	cin >> s;
	if (s[a] == s[b]) printf("0\n");
	else printf("1\n");
	return 0;
}