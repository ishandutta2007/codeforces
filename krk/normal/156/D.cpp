#include <cstdio>
#include <vector>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int n, m, k;
vector <int> neigh[Maxn];
bool taken[Maxn];
int comp;
int res = 1;

int getCnt(int v)
{
    if (taken[v]) return 0;
    int res = 1; taken[v] = true;
    for (int i = 0; i < neigh[v].size(); i++) res += getCnt(neigh[v][i]);
    return res;
}

int toPower(int a, int p)
{
    if (p == 0) return 1;
    int tmp = toPower(a, p / 2);
    tmp = ll(tmp) * ll(tmp) % ll(k);
    if (p & 1) tmp = ll(tmp) * ll(a) % ll(k);
    return tmp;
}

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    while (m--) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b); neigh[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) if (!taken[i]) {
        comp++;
        res = ll(res) * getCnt(i) % ll(k);
    }
    if (comp == 1) printf("%d\n", 1 % k);
    else printf("%d\n", int(ll(res) * ll(toPower(n, comp - 2)) % ll(k)));
    return 0;
}