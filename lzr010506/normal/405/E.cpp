#include <bits/stdc++.h>
#define T 100010
using namespace std;
struct Node
{
    int num,x;
}t;
vector<Node> p[T];
bool flag[T];
int dfs(int now)
{
    queue<int>q;
    int l = p[now].size();
    for(int i = 0; i < l; i ++)
    {
        Node k = p[now][i];
        if(flag[k.num])
            continue;
        else flag[k.num] = 1;
        int r = dfs(k.x);
        if(r)
            printf("%d %d %d\n",now,k.x,r);
        else q.push(k.x);
    }
    while(q.size() >= 2)
    {
        int v1 = q.front();
        q.pop();
        int v2 = q.front();
        q.pop();
        printf("%d %d %d\n",v1,now,v2);
    }
    while(!q.empty())
    {
        int v3 = q.front();
        q.pop();
        return v3;
    }
    return 0;
}
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

int main()
{
    int n,m,a,b;
	while(scanf("%d%d",&n,&m) != EOF)
    {
        for(int i = 0; i < n; i ++)
            p[i].clear();
        for(int i = 1; i <= m; i ++)
        {
            a = read();
            b = read();
            t.num = i;
            t.x = a;
            p[b].push_back(t);
            t.x = b;
            p[a].push_back(t);
        }
        if(m % 2 == 1) printf("No solution\n");
        else
        {
            memset(flag,0,sizeof(flag));
            dfs(1);
        }
    }
    return 0;
}