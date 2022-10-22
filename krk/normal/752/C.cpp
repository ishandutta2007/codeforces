#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int n;
string s;
set <char> S;
int res;

char Inv(char my) {
	if (my == 'L') return 'R';
	if (my == 'R') return 'L';
	if (my == 'U') return 'D';
	if (my == 'D') return 'U';
}

bool Check(char ch)
{
	bool nw = S.find(ch) == S.end();
	return S.size() + nw <= 2 && S.find(Inv(ch)) == S.end();
}

int main()
{
	scanf("%d", &n);
	cin >> s;
	for (int i = 0, j; i < s.length(); i = j) {
		j = i; S.clear(); res++;
		while (j < s.length() && Check(s[j])) {
			S.insert(s[j]); j++;
		}
	}
	printf("%d\n", res);
	return 0;
}