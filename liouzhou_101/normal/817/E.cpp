#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;

#define X first
#define Y second

const int MAXN = 100010;

struct node
{
	node *son[2];
	int tot;
	node();
};

node *nil, *root;

node::node ()
{
	son[0] = son[1] = nil;
	tot = 0;
}

void add(int p, int d)
{
	node *x = root;
	x->tot += d;
	for (int k = 26; k >= 0; -- k)
	{
		int s = p>>k&1;
		if (x->son[s] == nil)
			x->son[s] = new node();
		x = x->son[s];
		x->tot += d;
	}
}

void calc(int p, int v)
{
	node *x = root;
	int ans = 0;
	for (int k = 26; k >= 0; -- k)
	{
		int s = p>>k&1, t = v>>k&1;
		if (t == 0)
		{
			if (s == 0)
			{
				x = x->son[0];
			}
			else
			{
				x = x->son[1];
			}
		}
		else
		{
			if (s == 0)
			{
				ans += x->son[0]->tot;
				x = x->son[1];
			}
			else
			{
				ans += x->son[1]->tot;
				x = x->son[0];
			}
		}
	}
	printf("%d\n", ans);
}

int main()
{
	
	nil = new node();
	nil->son[0] = nil->son[1] = nil;
	nil->tot = 0;
	
	int T;
	scanf("%d", &T);
	root = new node();
	while (T --)
	{
		int op, p;
		scanf("%d%d", &op, &p);
		if (op == 1)
			add(p, 1);
		else if (op == 2)
			add(p, -1);
		else
		{
			int v;
			scanf("%d", &v);
			calc(p, v);
		}
	}
	
	return 0;
}