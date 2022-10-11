#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

vector <int> adj[1005];
int n, ans = 0, x, y;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
    {
        scanf("%d%d", &x, &y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (int i = 1; i <= n; i++)
        if (adj[i].size() == 1) ans++;
    printf("%d", ans);
	return 0;
}