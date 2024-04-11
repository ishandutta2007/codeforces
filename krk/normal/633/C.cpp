#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <cctype>
#include <cstring>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

const int Maxl = 26;
const int Maxn = 100005;

struct node {
	node *pnt[Maxl];
	int ind;
	node() { for (int i = 0; i < Maxl; i++) pnt[i] = NULL; ind = -1; }
};

int n;
char tmp[Maxn];
string str;
int m;
string W[Maxn];
node *root;
int best[Maxn], par[Maxn];

void Insert(node *tr, int val, const string &s, int ind)
{
	if (ind < 0) tr->ind = val;
	else {
		int pl = tolower(s[ind]) - 'a';
		if (!tr->pnt[pl]) tr->pnt[pl] = new node();
		Insert(tr->pnt[pl], val, s, ind - 1);
	}
}

int Get(int pos);

int Get(node *tr, int pos)
{
	if (tr->ind != -1)
		if (Get(pos) > 0) return tr->ind;
	if (pos == n) return -1;
	int pl = tolower(str[pos]) - 'a';
	if (!tr->pnt[pl]) return -1;
	return Get(tr->pnt[pl], pos + 1);
}

int Get(int pos) 
{ 
	if (!best[pos]) {
		if (pos == n) return best[pos] = 1;
		int val = Get(root, pos);
		if (val == -1) best[pos] = -1;
		else { best[pos] = 1; par[pos] = val; }
	}
	return best[pos];
}

int main()
{
	scanf("%d", &n);
	scanf("%s", tmp); str = tmp;
	root = new node();
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%s", tmp); W[i] = tmp;
		Insert(root, i, W[i], W[i].length() - 1);
	}
	Get(0);
	int pos = 0;
	while (pos < n) {
		if (pos) printf(" ");
		printf("%s", W[par[pos]].c_str());
		pos += W[par[pos]].size();
	}
	printf("\n");
	return 0;
}