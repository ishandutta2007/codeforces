#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 998244353;
const int Maxn = 200005;

int n, k;
int inp[Maxn];
vector <int> seq;
ll res1;
int res2 = 1;

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        inp[a] = i;
    }
    for (int i = n; i > n - k; i--) {
        res1 += i;
        seq.push_back(inp[i]);
    }
    sort(seq.begin(), seq.end());
    for (int i = 0; i + 1 < seq.size(); i++)
        res2 = ll(res2) * (seq[i + 1] - seq[i]) % mod;
    printf("%I64d %d\n", res1, res2);
    return 0;
}