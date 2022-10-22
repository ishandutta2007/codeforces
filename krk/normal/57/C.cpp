#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 200005;
const ll mod = 1000000007;

ll n;

bool prime[Maxn];
int canget[Maxn];
ll ans = 1;

int main()
{
    cin >> n;
    fill(prime, prime + Maxn, true);
    for (int i = 2; i < Maxn; i++) if (prime[i])
       for (int j = 2 * i; j < Maxn; j += i) prime[j] = false;
    for (int i = 2; i < Maxn; i++) if (prime[i])
       for (int l = 1; l <= Maxn / i; ) {
           l *= i;
           if (l == Maxn) break;
           for (int j = l; j < Maxn; j += l)
              if (n + 1 <= j && j <= 2 * n - 1) canget[i]++;
       }
    for (int i = 2; i < Maxn; i++) if (prime[i])
       for (int l = 1; l <= Maxn / i; ) {
           l *= i;
           if (l == Maxn) break;
           for (int j = l; j < Maxn; j += l)
              if (1 <= j && j <= n - 1) canget[i]--;
       }
    for (int i = 2; i <= 2 * n - 1; i++)
       for (int j = 0; j < canget[i]; j++)
          ans = ans * ll(i) % mod;
    ans = ans * 2LL % mod;
    ans -= n;
    if (ans < 0) ans += mod;
    cout << ans << endl;
    return 0;
}