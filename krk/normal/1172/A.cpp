#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int n;
int has[Maxn];
deque <int> D;
int res;

void Put(int x)
{
    res++;
    has[D.front()]++;
    has[x]--;
    D.pop_front();
    D.push_back(x);
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        has[a]++;
    }
    for (int i = 0; i < n; i++) {
        int b; scanf("%d", &b);
        D.push_back(b);
    }
    int mx = 0;
    for (int i = 0; i < D.size(); i++)
        if (D[i] > 0) mx = max(mx, i + 2 - D[i]);
    int gres = mx + n;
    while (has[0] != n) {
        int nxt = D.back() + 1;
        if (has[nxt])
            Put(nxt);
        else Put(0);
    }
    bool ok = true;
    for (int i = 0; i + 1 < D.size() && ok; i++)
        ok = D[i] < D[i + 1];
    if (ok) gres = min(gres, res);
    printf("%d\n", gres);
    return 0;
}