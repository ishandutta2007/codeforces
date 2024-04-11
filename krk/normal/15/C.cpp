#include <cstdio>
using namespace std;

typedef long long ll;

int n;
ll ans;

ll Xor(ll x)
{
    ll ans, i = x;
    while (i % 4 != 0) i--;
    ans = i;
    for (i++; i <= x; i++) ans ^= i;
    return ans;
}

int main()
{
    ll x, m;
    scanf("%d", &n);
    while (n--) {
          scanf("%I64d %I64d", &x, &m);
          ans ^= Xor(x - 1) ^ Xor(x + m - 1);
    }
    if (ans) printf("tolik\n");
    else printf("bolik\n");
    return 0;
}