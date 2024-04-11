#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

const int Maxlen = 100005;
const int Maxl = 26;

char tmp[Maxlen];
bool good[Maxl];
string pat;
int tot;
int q;
string cur;

void Read(string &s)
{
	scanf("%s", tmp); s = tmp;
}

bool Check()
{
	int tk = int(cur.length()) - tot;
	if (tk < 0) return false;
	if (tot == pat.length() && tk > 0) return false;
	int j = 0;
	for (int i = 0; i < pat.length(); i++)
		if (pat[i] == '*')
			while (tk--) {
				if (good[cur[j] - 'a']) return false;
				j++;
			}
		else if (pat[i] == '?') {
			if (!good[cur[j] - 'a']) return false;
			j++;
		} else {
			if (pat[i] != cur[j]) return false;
			j++;
		}
	return true;
}

int main()
{
	string goodl; Read(goodl);
	for (int i = 0; i < goodl.length(); i++)
		good[goodl[i] - 'a'] = true;
	Read(pat);
	for (int i = 0; i < pat.length(); i++)
		tot += pat[i] != '*';
	scanf("%d", &q);
	while (q--) {
		Read(cur);
		printf("%s\n", Check()? "YES": "NO");
	}
	return 0;
}