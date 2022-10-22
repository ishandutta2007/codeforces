#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <map>
#include <iomanip>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int mod = 1000000007;
const int Maxn = 100005;
const int Maxb = 21;

int pw2[Maxn];
int n, q;
int a[Maxn];
int got[Maxb];
int tot;
int res[Maxn];
int L[Maxn], X[Maxn];
vector <ii> quer;

void Insert(int x)
{
    for (int i = Maxb - 1; i >= 0; i--)
        if (x & 1 << i)
            if (got[i] == -1) { got[i] = x; return; }
            else x ^= got[i];
    tot++;
}

int Get(int x)
{
    for (int i = Maxb - 1; i >= 0; i--)
        if (x & 1 << i)
            if (got[i] == -1) return 0;
            else x ^= got[i];
    return pw2[tot];
}

int main() {
    pw2[0] = 1;
    for (int i = 1; i < Maxn; i++)
        pw2[i] = 2ll * pw2[i - 1] % mod;
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    fill(got, got + Maxb, -1);
    for (int i = 1; i <= q; i++) {
        scanf("%d %d", &L[i], &X[i]);
        quer.push_back(ii(L[i], i));
    }
    sort(quer.begin(), quer.end());
    int pnt = 0;
    for (int i = 0; i < quer.size(); i++) {
        int ind = quer[i].second;
        while (pnt < L[ind]) Insert(a[++pnt]);
        res[ind] = Get(X[ind]);
    }
    for (int i = 1; i <= q; i++)
        printf("%d\n", res[i]);
	return 0;
}