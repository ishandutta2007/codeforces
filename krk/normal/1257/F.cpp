#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 105;
const int Maxb = 15;
const int nil = 105;
const int mod1 = 1000000007;
const int mod2 = 1000000009;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int arg1, arg2;
int bits[1 << Maxb];
int n;
int a[Maxn];
map <ii, int> M;

bool Prime(int x)
{
    if (x <= 1) return false;
    if (x == 2) return true;
    if (x % 2 == 0) return false;
    for (int i = 3; i * i <= x; i += 2)
        if (x % i == 0) return false;
    return true;
}

int main()
{
    arg1 = uniform_int_distribution<int>(10000000, 100000000)(rng);
    arg2 = uniform_int_distribution<int>(10000000, 500000000)(rng);
    while (!Prime(arg1)) arg1++;
    while (!Prime(arg2)) arg2++;
    for (int i = 0; i < 1 << Maxb; i++)
        bits[i] = __builtin_popcount(i);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < 1 << Maxb; i++) {
        int x = bits[(a[0] >> Maxb) ^ i];
        ii h = ii(0, 0);
        for (int j = 1; j < n; j++) {
            int cur = bits[(a[j] >> Maxb) ^ i];
            int val = cur - x + nil;
            h.first = (ll(h.first) * arg1 + ll(val)) % mod1;
            h.second = (ll(h.second) * arg2 + ll(val)) % mod2;
        }
        M[h] = i;
    }
    int all = (1 << Maxb) - 1;
    for (int i = 0; i < 1 << Maxb; i++) {
        int x = bits[(a[0] & all) ^ i];
        ii h = ii(0, 0);
        for (int j = 1; j < n; j++) {
            int cur = bits[(a[j] & all) ^ i];
            int val = x - cur + nil;
            h.first = (ll(h.first) * arg1 + ll(val)) % mod1;
            h.second = (ll(h.second) * arg2 + ll(val)) % mod2;
        }
        auto it = M.find(h);
        if (it != M.end()) { printf("%d\n", ((it->second << Maxb) | i)); return 0; }
    }
    printf("-1\n");
    return 0;
}