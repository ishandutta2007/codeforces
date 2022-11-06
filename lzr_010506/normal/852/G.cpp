#include <bits/stdc++.h>
#define uint unsigned long long
#define ll long long
#define db double
#define ls rt << 1
#define rs rt << 1 | 1
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define vi vector<int>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define eps 1e-9
using namespace std;
const db pi = acos(-1.0);
inline int read()
{
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
}
int T, vis[100005], idx = 0;
int nxt[100005];

struct Node
{
	Node *ch[5];
	int head;

	Node()
	{
		memset(ch, 0, sizeof ch);
		head = 0;
	}
} *root;

void insert(Node *&k, char *s)
{
	if (!k) k = new Node();
	if (!*s)
	{
		nxt[idx] = k -> head;
		k -> head = idx;
		return;
	}
	insert(k->ch[*s - 'a'], s + 1);
}

int run(Node *k, char *s)
{
	if (!k) return 0;
	if (!*s)
	{
		int res = 0;
		for (int i = k -> head; i; i = nxt[i])
			if (vis[i] != T)
			{
				res ++;
				vis[i] = T;
			}
		return res;
	}
	if (*s == '?')
	{
		int res = 0;
		rep(i, 0, 4)
			res += run(k -> ch[i], s + 1);
		res += run(k, s + 1);
		return res;
	}
	else return run(k -> ch[*s - 'a'], s + 1);
}
char s[55];
int n, m;

int main()
{
	n = read();
	m = read();
	rep(i, 1, n)
	{
		scanf("%s", s);
		idx ++;
		insert(root, s);
	}

	while (m --)
	{
		scanf("%s", s);
		T ++;
		printf("%d\n", run(root, s));
	}

	return 0;
}