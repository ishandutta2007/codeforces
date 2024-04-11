#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 5005;

int T;
int n;
int a[Maxn];
vector <ii> res;
bool tk[Maxn];

void Traverse(int v)
{
    tk[v] = true;
    for (int i = 1; i <= n; i++) if (v != i && !tk[i] && a[v] != a[i]) {
        res.push_back(ii(v, i));
        Traverse(i);
    }
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            tk[i] = false;
        }
        res.clear();
        Traverse(1);
        if (res.size() != n - 1) printf("NO\n");
        else {
            printf("YES\n");
            for (int i = 0; i < res.size(); i++)
                printf("%d %d\n", res[i].first, res[i].second);
        }
    }
    return 0;
}