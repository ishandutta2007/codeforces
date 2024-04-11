#include <iostream>
#include <cstdio>
using namespace std;

int n, m, a, x = 0, ans;
bool chk[300005];

struct node
{
	int cnt;
	node *c[2];
	
	node()
	{
		c[0] = c[1] = nullptr;
		cnt = 0;
	}
} *root;

void build(node *cur, int l)
{
	++(cur -> cnt);
	if (l == 0)
		return;
	--l;
	if (cur -> c[(a >> l) & 1] == nullptr)
		cur -> c[(a >> l) & 1] = new node();
	build(cur -> c[(a >> l) & 1], l);
}

void get(node *cur, int l)
{
	if (l == 0)
		return;
	--l;
	int m = (x >> l) & 1;
	if (cur -> c[m] == nullptr)
		return;
	else if (cur -> c[m] -> cnt < (1 << l))
	{
		get(cur -> c[m], l);
		return;
	}
	ans += (1 << l); m = 1 - m;
	if (cur -> c[m] == nullptr)
		return;
	else get(cur -> c[m], l);
}

int main()
{
	scanf("%d%d", &n, &m);
	root = new node();
	while (n--)
	{
		scanf("%d", &a);
		if (!chk[a])
		{
			chk[a] = true;
			build(root, 20);
		}
	}
	while (m--)
	{
		scanf("%d", &a); x ^= a; ans = 0;
		get(root, 20);
		printf("%d\n", ans);
	}
}