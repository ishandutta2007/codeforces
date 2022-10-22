#include <cstdio>
using namespace std;

const int Maxn = 100005;

int n, m;
int g[Maxn];
int pos[Maxn], neg[Maxn];
int P, N;
bool canbe[Maxn];
int sus;

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &g[i]);
        if (g[i] > 0) { pos[g[i]]++; P++; }
        else { neg[-g[i]]++; N++; }
    }
    for (int i = 1; i <= n; i++) { canbe[i] = pos[i] + N - neg[i] == m; if (canbe[i]) sus++; }
    for (int i = 1; i <= n; i++)
        if (g[i] > 0)
            if (canbe[g[i]])
                if (sus == 1) printf("Truth\n");
                else printf("Not defined\n");
            else printf("Lie\n");
        else if (!canbe[-g[i]]) printf("Truth\n");
             else if (canbe[-g[i]])
                    if (sus == 1) printf("Lie\n");
                    else printf("Not defined\n");
    return 0;
}