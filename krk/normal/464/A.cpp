#include <cstdio>
#include <iostream>
using namespace std;

const int Maxn = 1005;

int n, p;
string s;
char res[Maxn];
bool found;

bool Check(int lvl, char ch)
{
	if (lvl > 0 && res[lvl - 1] == ch ||
		lvl > 1 && res[lvl - 2] == ch) return false;
	return true;
}

void Traverse(int lvl, bool all)
{
	if (lvl >= s.length()) {
		if (all == false) return;
		res[lvl] = '\0';
		printf("%s\n", res);
		found = true;
	} else {
		char from = all? 'a': s[lvl];
		for (res[lvl] = from; res[lvl] < 'a' + p && !found; res[lvl]++) 
			if (Check(lvl, res[lvl])) Traverse(lvl + 1, all || res[lvl] > s[lvl]);
	}
}

int main()
{
	cin >> n >> p;
	cin >> s;
	Traverse(0, false);
	if (!found) printf("NO\n"); 
	return 0;
}