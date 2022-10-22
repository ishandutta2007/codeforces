#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;

const int Maxn = 10000;

char str[Maxn];
int slen;
ull mx;

ull Calc(int l, int r)
{
	if (l == r) return ull(1);
	ull res = 0ll, cur = ull(str[l + 1] - '0');
	for (int i = l + 2; i < r; i += 2)
		if (str[i] == '+') { res += cur; cur = ull(str[i + 1] - '0'); }
		else cur *= ull(str[i + 1] - '0');
	res += cur;
	return res;
}

ull getCur(int l, int r)
{
	ull mid = Calc(l, r);
	ull res = 0ll, cur = ull(str[0] - '0');
	for (int i = 1; i < l; i += 2)
		if (str[i] == '+') { res += cur; cur = ull(str[i + 1] - '0'); }
		else cur *= ull(str[i + 1] - '0'); 
	cur *= mid;
	cur *= ull(str[r + 1] - '0');
	for (int i = r + 2; i < slen; i += 2)
		if (str[i] == '+') { res += cur; cur = ull(str[i + 1] - '0'); }
		else cur *= ull(str[i + 1] - '0');
	res += cur;
	return res;
}

int main()
{
	str[0] = '1'; str[1] = '*';
	scanf("%s", str + 2); slen = strlen(str);
	str[slen++] = '*'; str[slen++] = '1'; str[slen] = '\0';
	mx = getCur(1, 1);
	for (int i = 1; i < slen; i += 2) if (str[i] == '*')
		for (int j = i + 2; j < slen; j += 2) if (str[j] == '*')
			mx = max(mx, getCur(i, j));
	cout << mx << endl;
	return 0;
}