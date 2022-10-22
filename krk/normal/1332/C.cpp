#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
const int Maxd = 26;

int T;
int n, k;
char str[Maxn];
int slen;
bool tk[Maxn];

void Traverse(int v, vector <int> &V)
{
    if (tk[v]) return;
    tk[v] = true;
    V[str[v] - 'a']++;
    Traverse(slen + 1 - v, V);
    if (v <= slen - k) Traverse(v + k, V);
    if (v >= 1 + k) Traverse(v - k, V);
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        scanf("%s", str + 1);
        slen = strlen(str + 1);
        fill(tk + 1, tk + slen + 1, false);
        int res = slen;
        for (int i = 1; i <= n; i++) if (!tk[i]) {
            vector <int> V(Maxd, 0);
            Traverse(i, V);
            int mx = 0;
            for (int j = 0; j < Maxd; j++)
                mx = max(mx, V[j]);
            res -= mx;
        }
        printf("%d\n", res);
    }
    return 0;
}