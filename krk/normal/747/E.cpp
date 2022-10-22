#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

const int Maxl = 1000006;

char str[Maxl];
int len, pnt;
vector <string> com[Maxl];

string getString()
{
	int a = pnt;
	while (pnt < len && str[pnt] != ',') pnt++;
	string s(pnt - a, '?');
	for (int i = a; i < pnt; i++)
		s[i - a] = str[i];
	pnt++;
	return s;
}

int getNum()
{
	int res = 0;
	while (pnt < len && str[pnt] != ',') {
		res = 10 * res + (str[pnt] - '0');
		pnt++;
	}
	pnt++;
	return res;
}

void Solve(int lvl)
{
	if (pnt < len) {
		com[lvl].push_back(getString());
		int no = getNum();
		while (no--) Solve(lvl + 1);
	}
}

int main()
{
	scanf("%s", str); len = strlen(str);
	while (pnt < len) Solve(0);
	int i = 0;
	while (com[i].size() > 0) i++;
	printf("%d\n", i);
	for (int j = 0; j < i; j++)
		for (int k = 0; k < com[j].size(); k++)
			printf("%s%c", com[j][k].c_str(), k + 1 < com[j].size()? ' ': '\n');
	return 0;
}