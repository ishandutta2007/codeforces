#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 500005;

int n;
int a[Maxn];
ii seq[Maxn];
int slen;
ll L[Maxn], R[Maxn];
int res[Maxn];

void Left(int ind)
{
    int cur = a[ind];
    for (int i = ind; i >= 1; i--) {
        cur = min(cur, a[i]);
        res[i] = cur;
    }
}

void Right(int ind)
{
    int cur = a[ind];
    for (int i = ind; i <= n; i++) {
        cur = min(cur, a[i]);
        res[i] = cur;
    }
}

int main()
{
    scanf("%d", &n);
    ll cur = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        ii add = ii(a[i], 1);
        cur += a[i];
        while (slen > 0 && seq[slen - 1].first > a[i]) {
            cur -= ll(seq[slen - 1].first - a[i]) * seq[slen - 1].second;
            add.second += seq[slen - 1].second;
            slen--;
        }
        seq[slen++] = add;
        L[i] = cur;
    }
    slen = 0;
    cur = 0;
    for (int i = n; i > 0; i--) {
        ii add = ii(a[i], 1);
        cur += a[i];
        while (slen > 0 && seq[slen - 1].first > a[i]) {
            cur -= ll(seq[slen - 1].first - a[i]) * seq[slen - 1].second;
            add.second += seq[slen - 1].second;
            slen--;
        }
        seq[slen++] = add;
        R[i] = cur;
    }
    ll best = -1;
    int bi = 0;
    for (int i = 0; i <= n; i++) {
        ll cand = L[i] + R[i + 1];
        if (cand > best) {
            best = cand;
            bi = i;
        }
    }
    Left(bi);
    Right(bi + 1);
    for (int i = 1; i <= n; i++)
        printf("%d%c", res[i], i + 1 <= n? ' ': '\n');
    return 0;
}