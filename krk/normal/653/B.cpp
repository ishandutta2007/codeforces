#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxn = 6;
const int Maxq = 40;

string s;
int n, q;
string a[Maxq], b[Maxq];
int res;

bool Check()
{
	char fir = s[0];
	for (int i = 1; i < n; i++) {
		char sec = s[i];
		int j = 0;
		for (; j < q; j++)
			if (a[j][0] == fir && a[j][1] == sec) {
				fir = b[j][0]; break;
			}
		if (j == q) return false;
	}
	return fir == 'a';
}

void Gen(int lvl)
{
	if (lvl == n) {
		res += Check();
	} else for (char ch = 'a'; ch <= 'f'; ch++) {
			s[lvl] = ch;
			Gen(lvl + 1);
		}
}

int main()
{
	scanf("%d %d", &n, &q);
	for (int i = 0; i < q; i++)
		cin >> a[i] >> b[i];
	s.resize(n);
	Gen(0);
	printf("%d\n", res);
	return 0;
}