#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 1000005;
ll mod = 1000000000000037LL;

int n, m;
ll pw[Maxn], h[Maxn];
int seq[Maxn];
ll res;

ll Insert(ll a, ll ind) { return (a + pw[ind]) % mod; }

bool Less(const int &a, const int &b)
{
    return h[a] < h[b];
}

int main()
{
    scanf("%d %d", &n, &m);
    pw[1] = 1LL;
    for (int i = 2; i <= n; i++) pw[i] = 2LL * pw[i - 1] % mod;
    while (m--) {
        int u, v; scanf("%d %d", &u, &v);
        h[u] = Insert(h[u], v); h[v] = Insert(h[v], u);
    }
    // Case 1
    for (int i = 1; i <= n; i++) seq[i - 1] = i;
    sort(seq, seq + n, Less);
    int j;
    for (int i = 0; i < n; i = j) {
        j = i + 1;
        while (j < n && h[seq[i]] == h[seq[j]]) j++;
        ll len = j - i;
        res += len * (len - 1) / 2LL;
    }
    // Case 2
    for (int i = 1; i <= n; i++) {
        seq[i - 1] = i;
        h[i] = Insert(h[i], i);
    }
    sort(seq, seq + n, Less);
    for (int i = 0; i < n; i = j) {
        j = i + 1;
        while (j < n && h[seq[i]] == h[seq[j]]) j++;
        ll len = j - i;
        res += len * (len - 1) / 2LL;
    }
    printf("%I64d\n", res);
    return 0;
}