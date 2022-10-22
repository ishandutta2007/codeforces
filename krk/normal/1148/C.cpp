#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 300005;

int n;
int p[Maxn], inp[Maxn];
vector <ii> V;

void Swap(int a, int b)
{
    V.push_back(ii(a, b));
    swap(p[a], p[b]);
    inp[p[a]] = a;
    inp[p[b]] = b;
}

void gSwap(int a, int b)
{
    if (a > b) swap(a, b);
    if (b - a >= n / 2)
        Swap(a, b);
    else if (b <= n / 2) {
        Swap(b, n);
        Swap(a, n);
        Swap(b, n);
    } else if (n / 2 < a) {
        Swap(b, 1);
        Swap(a, 1);
        Swap(b, 1);
    } else {
        Swap(a, n);
        Swap(b, 1);
        Swap(1, n);
        Swap(a, n);
        Swap(b, 1);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
        inp[p[i]] = i;
    }
    for (int i = 1; i <= n; i++)
        if (inp[i] != i) gSwap(inp[i], i);
    printf("%d\n", int(V.size()));
    for (int i = 0; i < V.size(); i++)
        printf("%d %d\n", V[i].first, V[i].second);
    return 0;
}