#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 10000005;
const int Maxm = 1000005;

int pr[Maxm], plen;
bool comp[Maxn];
int val[Maxn];
int n;
int res1[Maxn], res2[Maxn];

int main()
{
    for (int i = 2; i < Maxn; i++) {
        if (!comp[i]) { val[i] = i; pr[plen++] = i; }
        for (int j = 0; j < plen && ll(i) * pr[j] < Maxn; j++) {
            comp[i * pr[j]] = true;
            val[i * pr[j]] = pr[j];
            if (i % pr[j] == 0) break;
        }
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        res1[i] = val[a];
        int nw = 1;
        while (a % res1[i] == 0) { a /= res1[i]; nw *= res1[i]; }
        if (a == 1) res1[i] = res2[i] = -1;
        else { res1[i] = nw; res2[i] = a; }
    }
    for (int i = 0; i < n; i++)
        printf("%d%c", res1[i], i + 1 < n? ' ': '\n');
    for (int i = 0; i < n; i++)
        printf("%d%c", res2[i], i + 1 < n? ' ': '\n');
    return 0;
}