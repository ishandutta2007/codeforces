#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n;
char str[Maxn];
int has[Maxn];
vector <int> neigh[Maxn];
bool tk[Maxn];

void addEdge(int a, int b)
{
    neigh[a].push_back(b);
    neigh[b].push_back(a);
}

void Fill(int v)
{
    if (tk[v]) return;
    tk[v] = true;
    for (int i = 0; i < neigh[v].size(); i++)
        Fill(neigh[v][i]);
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n); n *= 2;
        scanf("%s", str + 1);
        for (int i = 1; i <= n + 1; i++) {
            has[i] = 0;
            neigh[i].clear();
            tk[i] = false;
        }
        vector <int> seq;
        for (int i = 1; i <= n; i++)
            if (str[i] == '(') seq.push_back(i);
            else if (str[i] == ')' && !seq.empty()) {
                has[seq.back()] = i;
                seq.pop_back();
            }
        for (int i = 1; i <= n; i++)
            if (has[i]) {
                addEdge(i, has[i]);
                if (has[has[i] + 1])
                    addEdge(i, has[has[i] + 1]);
            }
        int res = 0;
        for (int i = 1; i <= n; i++) if (!tk[i]) {
            res++;
            Fill(i);
        }
        printf("%d\n", res);
    }
    return 0;
}