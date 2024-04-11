#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
const int Maxm = 524288;

struct node {
	int spec;
	int my;
	node(): spec(0), my(0) {}
};

char S[2][Maxn];
int slen[2];
node st[2][Maxm];
int q;

node Union(const node &a, const node &b)
{
	node c;
	c.spec = a.spec + b.spec;
	c.my = b.my;
	if (b.spec == 0) c.my += a.my;
	return c;
}

void Create(int s, int v, int l, int r)
{
	if (l == r)
		if (S[s][l] == 'A') st[s][v].my = 1;
		else st[s][v].spec = 1;
	else {
		int m = l + r >> 1;
		Create(s, 2 * v, l, m); Create(s, 2 * v + 1, m + 1, r);
		st[s][v] = Union(st[s][2 * v], st[s][2 * v + 1]);
	}
}

node Get(int s, int v, int l, int r, int a, int b)
{
	if (l == a && r == b) return st[s][v];
	else {
		int m = l + r >> 1;
		if (b <= m) return Get(s, 2 * v, l, m, a, b);
		if (m + 1 <= a) return Get(s, 2 * v + 1, m + 1, r, a, b);
		return Union(Get(s, 2 * v, l, m, a, m), Get(s, 2 * v + 1, m + 1, r, m + 1, b));
	}
}

bool Solve(const node &a, const node &b)
{
	if (a.spec < b.spec) return false;
	if (b.spec == 0 && a.my + (a.spec != b.spec) > b.my) return false; 
	if (a.my > b.my) return false;
	if (a.spec == b.spec && a.my % 3 != b.my % 3) return false; 
	if (a.spec % 2 != b.spec % 2) return false;
	return true;
}

int main()
{
	scanf("%s", S[0] + 1); slen[0] = strlen(S[0] + 1);
	scanf("%s", S[1] + 1); slen[1] = strlen(S[1] + 1);
	Create(0, 1, 1, slen[0]); Create(1, 1, 1, slen[1]);
	scanf("%d", &q);
	while (q--) {
		int a, b, c, d; scanf("%d %d %d %d", &a, &b, &c, &d);
		node V1 = Get(0, 1, 1, slen[0], a, b);
		node V2 = Get(1, 1, 1, slen[1], c, d);
		printf("%c", Solve(V2, V1)? '1': '0');
	}
	printf("\n");
	return 0;
}