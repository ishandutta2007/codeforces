#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<sstream>
#include<string>
#include<bitset>
#define pb push_back
#define nn 100100
#define maxk 18
#define LL long long
using namespace std;
inline int ReadInt()
{
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9')
	{
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9')
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
const LL LINF = (1LL <<60);
const int INF = 1 << 28;

const int NS = 100010;
const int MS = 17;
const LL MOD = 1000000007;
const int EDGE_MAX = NS;
struct graphEdge
{
    int pst;
    int next;
    int val;
};
struct ForwardStart
{
    int top;
    int head[EDGE_MAX];
    graphEdge edge[EDGE_MAX << 1];

    void init()
    {
        top = 0;
        memset(head, -1, sizeof(head));
    }
    void insert(int u, int v, int val)
    {
        edge[top].pst = v;
        edge[top].val = val;
        edge[top].next = head[u];
        head[u] = top ++;
    }

    void printAll()
    {
        printf("top = %d\n", top);
        for(int i = 1; i < EDGE_MAX; i ++)
        {
            if(-1 != head[i])
            {
                printf("head[%2d]'son:%2d", i, edge[head[i]].pst);
                for(int j = edge[head[i]].next; j != -1; j = edge[j].next)
                {
                    printf(",%2d", edge[j].pst);
                }
                puts("");
            }
        }
    }
}sTree;

int n, m, q;
int height[NS];
int par[NS][MS];
vector<int> re[NS][MS + 1];
void mergequeue(vector<int>& ans, const vector<int>& a, const vector<int>& b)
{
	int sa = a.size(), ida = 0;
	int sb = b.size(), idb = 0;
	ans.clear();
	int va, vb;
	while((ida < sa || idb < sb) && ans.size() < 10)
	{
		if(ida < sa) va = a[ida];
		else va = INF;
		if(idb < sb) vb = b[idb];
		else vb = INF;
		if(va < vb)
            ans.push_back(va), ida ++;
        else
            ans.push_back(vb), idb ++;
	}
}

void mergequeue(vector<int>& a, const vector<int>& b)
{
	vector<int> ans;
	int sa = a.size();
	int sb = b.size();
	int ida = 0, idb = 0;
	int va, vb;
	while((ida + idb) < 10 && (ida < sa || idb < sb))
	{
		if(ida < sa) va = a[ida];
		else va = INF;
		if(idb < sb) vb = b[idb];
		else vb = INF;
		if(va < vb)
        {
            ans.push_back(va);
            ida ++;
        }
        else
        {
            ans.push_back(vb);
            idb ++;
        }
	}
	int len = ans.size();
	a.clear();
	for(int i = 0; i < len; i ++)
		a.push_back(ans[i]);
}

void dfs(int rt, int fa)
{
	if(fa == -1) height[rt] = 1;
	else height[rt] = height[fa] + 1;
	par[rt][0] = fa;
	for(int i = 1; i < MS; i ++)
	{
		int anc = par[rt][i - 1];
		if(anc != -1)
		{
			par[rt][i] = par[anc][i - 1];
			mergequeue(re[rt][i], re[rt][i - 1], re[anc][i - 1]);
		}
		else break;
	}
	for(int i = sTree.head[rt]; i != -1; i = sTree.edge[i].next)
	{
		int cson = sTree.edge[i].pst;
		if(cson == fa) continue;
		dfs(cson, rt);
	}
}

vector<int> queryAnswer(int u, int v)
{
	if(height[u] < height[v])
		swap(u, v);
	vector<int> res;
	for(int i = MS - 1; i >= 0; i --)
	{
		int ances = par[u][i];
		if(ances >= 0 && height[ances] >= height[v])
		{
			mergequeue(res, re[u][i]);
			u = ances;
		}
	}
	if(u == v)
	{
		mergequeue(res, re[u][0]);
		return res;
	}
	for(int i = MS - 1; i >= 0; i --)
		if(par[u][i] != par[v][i])
		{
			mergequeue(res, re[u][i]);
			mergequeue(res, re[v][i]);
			u = par[u][i];
			v = par[v][i];
		}
	mergequeue(res, re[u][1]);
	mergequeue(res, re[v][0]);
	return res;
}

int main()
{
	n = ReadInt();
	m = ReadInt();
	q = ReadInt();
	sTree.init();
	for(int i = 1; i < n; i ++)
	{
		int u = ReadInt();
		int v = ReadInt();
		sTree.insert(u, v, 1);
        sTree.insert(v, u, 1);
	}
	for(int i = 0; i <= n; i++)
        re[i][0].clear();
	int c;
    for(int i = 1; i <= m; i++)
    {
        scanf("%d", &c);
        re[c][0].push_back(i);
    }
	memset(par, -1, sizeof(par));
	dfs(1, -1);
	while(q --)
	{
		int u = ReadInt();
		int v = ReadInt();
		int c = ReadInt();
		vector<int> ans = queryAnswer(u, v);
		int num = ans.size();
		if(num > c) num = c;
		printf("%d", num);
		for(int i = 0; i < num; i ++)
			printf(" %d", ans[i]);
		printf("\n");
	}
	return 0;
}