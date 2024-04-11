#include <bits/stdc++.h>
using namespace std;

const int Maxn = 300005;

int n, k;
char state[Maxn];
vector <int> my[Maxn];
int par[Maxn], siz[Maxn];
int A[Maxn], B[Maxn];
int xr[Maxn];
int res;

void getPar(int x)
{
    if (par[x] == x) return;
    int p = par[x];
    getPar(p);
    par[x] = par[p];
    xr[x] ^= xr[p];
}

void unionSet(int a, int b, int col)
{
    getPar(a); getPar(b);
    int para = par[a], parb = par[b];
    if (para == parb) return;
    getPar(0);
    if (par[0] == para) res -= xr[0]? A[para]: B[para];
    else res -= min(A[para], B[para]);
    if (par[0] == parb) res -= xr[0]? A[parb]: B[parb];
    else res -= min(A[parb], B[parb]);
    if (siz[para] < siz[parb]) swap(para, parb);
    if (xr[a] ^ xr[b] ^ col) swap(A[parb], B[parb]);
    siz[para] += siz[parb]; par[parb] = para;
    xr[parb] = (xr[a] ^ xr[b] ^ col);
    A[para] += A[parb];
    B[para] += B[parb];
    getPar(0);
    if (par[0] == para) res += xr[0]? A[para]: B[para];
    else res += min(A[para], B[para]);
}

int main()
{
    scanf("%d %d", &n, &k);
    scanf("%s", state + 1);
    for (int i = 1; i <= k; i++) {
        int siz; scanf("%d", &siz);
        while (siz--) {
            int num; scanf("%d", &num);
            my[num].push_back(i);
        }
    }
    for (int i = 0; i <= k; i++) {
        par[i] = i, siz[i] = 1, xr[i] = 0;
        A[i] = 1; B[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        if (my[i].empty()) ;
        else if (my[i].size() == 1) unionSet(0, my[i][0], state[i] == '0');
        else if (my[i].size() == 2) unionSet(my[i][0], my[i][1], state[i] == '0');
        printf("%d\n", res);
    }
    return 0;
}