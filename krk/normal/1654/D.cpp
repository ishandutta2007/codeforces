#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;
typedef pair <int, ii> iii;

const int Maxn = 200005;
const int mod = 998244353;

int mx[Maxn];
int T;
int n;
vector <iii> neigh[Maxn];
int mult, sum;
int cur[Maxn], big[Maxn];

void Rem(int x)
{
    while (x > 1) {
        int my = mx[x];
        while (mx[x] == my) {
            cur[my]--;
            x /= my;
        }
    }
}

void Add(int x)
{
    while (x > 1) {
        int my = mx[x];
        while (mx[x] == my) {
            cur[my]++;
            if (cur[my] > big[my]) {
                big[my]++;
                mult = ll(mult) * my % mod;
            }
            x /= my;
        }
    }
}

int toPower(int x, int p)
{
    int res = 1;
    while (p) {
        if (p & 1) res = ll(res) * x % mod;
        p >>= 1; x = ll(x) * x % mod;
    }
    return res;
}

int Inv(int x) { return toPower(x, mod - 2); }

void Traverse(int v, int p, int add)
{
    sum = (sum + add) % mod;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i].first;
        if (u == p) continue;
        ii pr = neigh[v][i].second;
        Rem(pr.first); Add(pr.second);
        Traverse(u, v, ll(add) * pr.first % mod * Inv(pr.second) % mod);
        Rem(pr.second); Add(pr.first);
    }
}

int main()
{
    for (int i = 2; i < Maxn; i++) if (mx[i] == 0)
        for (int j = i; j < Maxn; j += i)
            mx[j] = i;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        mult = 1;
        sum = 0;
        fill(cur, cur + n + 1, 0);
        fill(big, big + n + 1, 0);
        for (int i = 1; i <= n; i++) 
            neigh[i].clear();
        for (int i = 0; i < n - 1; i++) {
            int a, b, x, y; scanf("%d %d %d %d", &a, &b, &x, &y);
            neigh[a].push_back(iii(b, ii(y, x)));
            neigh[b].push_back(iii(a, ii(x, y)));
        }
        Traverse(1, 0, 1);
        int res = ll(mult) * sum % mod;
        printf("%d\n", res);
    }
    return 0;
}