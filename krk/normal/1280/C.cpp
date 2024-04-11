#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 200005;

int T;
int k, n;
vector <ii> neigh[Maxn];
int cnt[Maxn], mida, w, midb;
ll A, B;

void Count(int v, int p)
{
    cnt[v] = 1;
    for (int i = 0; i < neigh[v].size(); i++) {
        ii u = neigh[v][i];
        if (u.first == p) continue;
        Count(u.first, v);
        if (cnt[u.first] % 2) A += u.second;
        B += ll(min(cnt[u.first], n - cnt[u.first])) * u.second;
        cnt[v] += cnt[u.first];
    }
}

void Add(int v, int p, ll a)
{
    B += a;
    for (int i = 0; i < neigh[v].size(); i++) {
        ii u = neigh[v][i];
        if (u.first == p) continue;
        Add(u.first, v, a + u.second);
    }
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &k); n = 2 * k;
        for (int i = 1; i <= n; i++)
            neigh[i].clear();
        for (int i = 0; i < n - 1; i++) {
            int a, b, c; scanf("%d %d %d", &a, &b, &c);
            neigh[a].push_back(ii(b, c));
            neigh[b].push_back(ii(a, c));
        }
        A = B = 0;
        Count(1, 0);
        printf("%I64d %I64d\n", A, B);
    }
    return 0;
}