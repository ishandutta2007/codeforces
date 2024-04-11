#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#define maxn 10010
using namespace std;
int n, m;
int d[maxn];
bool vis[maxn];

struct Node
{
    int u, d;
    Node(int u, int d):u(u), d(d) {}
};

queue<Node> Q;
int BFS()
{
    Node head = Node(n, 0);
    vis[n] = true;
    Q.push(head);
    while(!Q.empty())
    {
        Node x = Q.front();
		Q.pop();
        if(x.u == m) return x.d;
        int a = x.u - 1;
        int d = x.d + 1;
        if(a > 0 && !vis[a])
        {
            vis[a] = true;
            Q.push(Node(a, d));
        }
        a = x.u * 2;
        if(a < maxn && !vis[a])
        {
            vis[a] = true;
            Q.push(Node(a, d));
        }
    }
    return -1;
}

int main()
{
    scanf("%d%d", &n, &m);
    printf("%d\n", BFS());
    return 0;
}