#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005;

int n;
int a[Maxn];
vector <int> V;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int i = n - 1;
    while (i >= 0) {
        V.push_back(a[i]);
        i -= a[i];
    }
    printf("%d\n", int(V.size()));
    for (int i = int(V.size()) - 1; i >= 0; i--)
        printf("%d%c", V[i], i - 1 >= 0? ' ': '\n');
    return 0;
}