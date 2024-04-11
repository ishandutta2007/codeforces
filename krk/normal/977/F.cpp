#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int n;
int a[Maxn];
map <int, int> M;
int best = 0, bi;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = n - 1; i >= 0; i--) {
        M[a[i]] = M[a[i] + 1] + 1;
        if (M[a[i]] > best) { best = M[a[i]]; bi = a[i]; }
    }
    vector <int> res;
    for (int i = 0; i < n; i++)
        if (a[i] == bi) { res.push_back(i); bi++; }
    printf("%d\n", int(res.size()));
    for (int i = 0; i < res.size(); i++)
        printf("%d%c", res[i] + 1, i + 1 < res.size()? ' ': '\n');
    return 0;
}