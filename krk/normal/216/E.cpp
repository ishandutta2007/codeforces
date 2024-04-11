#include <cstdio>
#include <map>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int k, b, n;
int s[Maxn];
ll nils;
map <int, int> was;
ll res;

void getNils()
{
    int was = 0;
    for (int i = 0; i < n; i++)
        if (s[i]) was = 0;
        else nils += ++was;
}

int main()
{
    scanf("%d %d %d", &k, &b, &n);
    for (int i = 0; i < n; i++) scanf("%d", &s[i]);
    getNils();
    if (b == 0) { printf("%I64d\n", nils); return 0; }
    if (b == k - 1) {
        res = -nils;
        b = 0;
    }
    was[0] = 1;
    int mod = 0;
    for (int i = 0; i < n; i++) {
        mod = (mod + s[i]) % (k - 1);
        res += was[(mod - b + k - 1) % (k - 1)];
        was[mod]++;
    }
    printf("%I64d\n", res);
    return 0;
}