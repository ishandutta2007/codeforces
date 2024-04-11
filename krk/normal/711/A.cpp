#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int Maxn = 10005;

int n;
string s[Maxn];

int main()
{
	scanf("%d", &n);
	bool ok = false;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		if (s[i][0] == 'O' && s[i][1] == 'O' && !ok) {
			s[i][0] = s[i][1] = '+'; ok = true;
		}
		if (s[i][3] == 'O' && s[i][4] == 'O' && !ok) {
			s[i][3] = s[i][4] = '+'; ok = true;
		}
	}
	if (ok) {
		printf("YES\n");
		for (int i = 0; i < n; i++)
			printf("%s\n", s[i].c_str());
	} else printf("NO\n");
	return 0;
}