#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int key = 7919;
const int Maxn = 1000005;
const int Maxm = 2 * Maxn;

string a, b;
int pw[Maxn];
int hsha[Maxn], hshb[Maxn];
string c;
int kmp[Maxm];
int bi = -1, bj = -1;

int Hash(int h[], int l, int r)
{
	return h[r] - (l? h[l - 1]: 0) * pw[r - l + 1];
}

int main()
{
	getline(cin, a);
	getline(cin, b);
	if (a.length() != b.length()) { printf("-1 -1\n"); return 0; }
	pw[0] = 1;
	for (int i = 1; i < Maxn; i++)
		pw[i] = pw[i - 1] * key;
	for (int i = 0; i < a.length(); i++)
		hsha[i] = (i? hsha[i - 1]: 0) * key + a[i];
	for (int i = 0; i < b.length(); i++)
		hshb[i] = (i? hshb[i - 1]: 0) * key + b[i];
	c = a; reverse(c.begin(), c.end());
	c += string(1, 0) + b;
	kmp[0] = -1; int j = -1;
	for (int i = 1; i <= c.length(); i++) {
		while (j >= 0 && c[i - 1] != c[j]) j = kmp[j];
		kmp[i] = ++j;
	}
	for (int i = 0; i + 1 < a.length() && a[i] == b[b.length() - 1 - i]; i++) {
		int ind = b.length() - 1 - i - 1;
		int best = kmp[a.length() + 1 + ind + 1];
		if (!best) continue;
		int j = a.length() - 1 - best + 1;
		if (Hash(hsha, i + 1, j - 1) == Hash(hshb, 0, j - i - 2)) { bi = i; bj = j; }
	}
	printf("%d %d\n", bi, bj);
	return 0;
}