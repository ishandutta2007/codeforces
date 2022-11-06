#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int N = 305;
int p[N];
char A[N][N];
vector<int>V[N];
int wsk[N];
int rep[N];
int n;
int find(int w)
{
    return w == rep[w]? w: rep[w] = find(rep[w]);
}
void Union(int a, int b)
{
    rep[find(a)] = find(b);
}
int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &p[i]);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        {
            scanf(" %c", &A[i][j]);
            A[i][j] -= '0';
        }
    for(int i = 1; i <= n; i++)
        rep[i] = i;
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(A[i][j]) Union(i, j);
    for(int i = 1; i <= n; i++)
        V[find(i)].push_back(p[i]);
    for(int i = 1; i <= n; i++)
        sort(V[i].begin(), V[i].end());
    for(int i = 1; i <= n; i++)
        printf("%d ", V[find(i)][wsk[find(i)]++]);
    return 0;
}