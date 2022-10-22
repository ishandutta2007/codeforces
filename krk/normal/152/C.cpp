#include <cstdio>
#include <set>
using namespace std;

typedef long long ll;

const ll mod = 1000000007LL;
const int Maxn = 105;

int n, m;
set <char> S[Maxn];
ll res = 1LL;

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            char c; scanf(" %c", &c);
            S[j].insert(c);
        }
    for (int j = 0; j < m; j++) res = res * ll(S[j].size()) % mod;
    printf("%I64d\n", res);
    return 0;
}