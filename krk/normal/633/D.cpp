#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

const int Maxn = 1005;
const int lim = 1000000000;

int n;
int a[Maxn];
map <int, int> ID;
int num[Maxn];
int freq[Maxn];
int m;
int my[Maxn];
int seq[Maxn], slen;
int res;

int getInd(int x) {
	map <int, int>::iterator it = ID.find(x);
	return it == ID.end()? -1: it->second;
}

void Check(int a, int b)
{
	int cand = 2;
	seq[slen++] = a; my[a]++;
	seq[slen++] = b; my[b]++;
	while (true)
		if (num[a] == 0 && num[b] == 0) { cand += freq[a] - my[a]; break; }
		else {
			int c = getInd(num[a] + num[b]);
			if (c == -1 || my[c] == freq[c]) break;
			else { a = b; b = c; seq[slen++] = c; my[c]++; cand++; }
		}
	res = max(res, cand);
	for (int i = 0; i < slen; i++)
		my[seq[i]] = 0;
	slen = 0;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (ID.find(a[i]) == ID.end()) {
			int siz = ID.size(); ID[a[i]] = siz; num[siz] = a[i];
		}
		freq[ID[a[i]]]++;
	}
	m = ID.size();
	for (int i = 0; i < m; i++) {
		if (freq[i] >= 2) Check(i, i);
		for (int j = 0; j < m; j++) if (i != j)
			Check(i, j);
	}
	printf("%d\n", res);
	return 0;
}