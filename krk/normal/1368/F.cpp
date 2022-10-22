#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005;

int n;
int best = -1, wth;
bool nd[Maxn], has[Maxn];

void End()
{
    printf("0\n"); fflush(stdout);
}

void Query(int cnt)
{
    vector <int> seq;
    for (int i = 0; i < n && seq.size() < cnt; i++)
        if (nd[i] && !has[i]) { seq.push_back(i); has[i] = true; }
    for (int i = 0; i < n && seq.size() < cnt; i++)
        if (!nd[i] || has[i]) { seq.push_back(i); has[i] = true; }
    printf("%d", cnt);
    for (int i = 0; i < seq.size(); i++)
        printf(" %d", seq[i] + 1);
    printf("\n"); fflush(stdout);
    int x; scanf("%d", &x);
    x--;
    for (int i = 0; i < cnt; i++)
        has[(x + i) % n] = false;
}

int curAns()
{
    int res = 0;
    for (int i = 0; i < n; i++)
        if (has[i]) res++;
    return res;
}

int main()
{
    scanf("%d", &n);
    if (n == 1) { End(); return 0; }
    for (int i = 1; i < n; i++) {
        int hm = n / (i + 1);
        int cand = hm * i;
        if (hm * (i + 1) != n) cand += n - (i + 1) * hm - 1;
        cand -= i;
        if (cand > best) { best = cand; wth = i; }
    }
    int pnt = 0;
    while (pnt + wth + 1 <= n) {
        pnt++;
        for (int i = 0; i < wth; i++)
            nd[pnt++] = true;
    }
    if (pnt < n) {
        pnt++;
        while (pnt < n) nd[pnt++] = true;
    }
    while (curAns() < best)
        Query(wth + 1);
    End();
    return 0;
}