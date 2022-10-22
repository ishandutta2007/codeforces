#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

int t;
ll a, b;

bool Win(ll a, ll b)
{
    if (a > b) swap(a, b);
    if (a == 0LL) return false;
    if (!Win(b % a, a)) return true;
    if (a % 2LL) return b / a % 2LL == 0;
    return b / a % (a + 1LL) % 2LL == 0;
}

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%I64d %I64d", &a, &b);
        printf(Win(a, b)? "First\n": "Second\n");
    }
    return 0;
}