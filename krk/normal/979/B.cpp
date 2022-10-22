#include <bits/stdc++.h>
using namespace std;

char tmp[1000005];

int n;
int best1, all1;
int best2, all2;
int best3, all3;

void Get(int &best, int &all)
{
	scanf("%s", tmp);
	string s = tmp; all = s.length();
	map <char, int> M;
	for (int i = 0; i < all; i++)
		M[s[i]]++;
	for (map <char, int>::iterator it = M.begin(); it != M.end(); it++)
		best = max(best, it->second);
	int lft = n;
	int tk = min(lft, all - best);
	if (best == all && n == 1 && best > 1) best--;
	else {
		lft -= tk; best += tk;
	}
}

int main()
{
	scanf("%d", &n);
	Get(best1, all1);
	Get(best2, all2);
	Get(best3, all3);
	if (best1 > best2 && best1 > best3) printf("Kuro\n");
	else if (best2 > best1 && best2 > best3) printf("Shiro\n");
	else if (best3 > best1 && best3 > best2) printf("Katie\n");
	else printf("Draw\n");
	return 0;
}