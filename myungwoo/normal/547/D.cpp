#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005
#define pb push_back

int N;
int X[MAXN], Y[MAXN];
char V[MAXN];
vector <int> con[MAXN];

void dfs(int n, char c)
{
    if (V[n]) return;
    V[n] = c;
    for (int t: con[n]) dfs(t, 'b'+'r'-c);
}

int main()
{
    scanf("%d", &N);
    for (int i=1;i<=N;i++){
        int x, y;
        scanf("%d%d", &x, &y);
        if (X[x]){
            con[i].pb(X[x]);
            con[X[x]].pb(i);
            X[x] = 0;
        }else X[x] = i;
        if (Y[y]){
            con[i].pb(Y[y]);
            con[Y[y]].pb(i);
            Y[y] = 0;
        }else Y[y] = i;
    }
    for (int i=1;i<=N;i++){
        dfs(i, 'b'); printf("%c", V[i]);
    }puts("");
}