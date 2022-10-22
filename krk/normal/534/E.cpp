#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 400005;

int n;
int a[Maxn];
int m;
int f1[Maxn], f2[Maxn];
int curp, curd, dist;
ll cand;
ll res = -1;

void trySave(ll cand)
{
    if (res == -1) res = cand;
    else if (res != cand) res = -2;
}

bool canGo(int f[])
{
    if (curp + curd < 1 || curp + curd > n) curd = -curd;
    if (f[curp + curd]) { cand += abs(a[curp + curd] - a[curp]); curp += curd; f[curp]--; dist++; return true; }
    return false;
}

void Check1()
{
    dist = cand = 0;
    for (int i = n; i >= 1; i--) {
        if (dist < 1 && f1[i]) {
            curp = i; curd = -1; dist = 1; cand = 0;
            f1[i]--;
        }
        if (dist >= 1) {
            while (canGo(f1)) ;
            if (dist == m) trySave(cand);
            dist--; cand -= a[i] - a[i - 1];
            f1[i]++;
        }
    }
}

void Check2()
{
    dist = cand = 0;
    for (int i = 1; i <= n; i++) {
        if (dist < 1 && f2[i]) {
            curp = i; curd = 1; dist = 1; cand = 0;
            f2[i]--;
        }
        if (dist >= 1) {
            while (canGo(f2)) ;
            if (dist == m) trySave(cand);
            dist--; cand -= a[i + 1] - a[i];
            f2[i]++;
        }
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int b; scanf("%d", &b);
        f1[b]++; f2[b]++;
    }
    Check1(); Check2();
    if (res < 0) printf("-1\n");
    else printf("%I64d\n", res);
    return 0;
}