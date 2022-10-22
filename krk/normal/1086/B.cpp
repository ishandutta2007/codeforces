#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

const int Maxn = 100005;

int n, s;
vector <int> neigh[Maxn];

void Print(ld x)
{
    cout << fixed << setprecision(10) << x << endl;
}

int main()
{
    scanf("%d %d", &n, &s);
    if (n == 2) {
        Print(s); return 0;
    }
    for (int i = 0; i < n - 1; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        if (neigh[i].size() == 1) cnt++;
    Print(ld(s) / ld(cnt) * 2.0l);
    return 0;
}