#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1000000007;
const int Maxn = 100005;

bool prime[Maxn];
vector <int> divs[Maxn];
int phi[Maxn];
int n;
int res;

int gcd(int x, int y) { return x? gcd(y % x, x): y; }

int main()
{
    fill(prime + 2, prime + Maxn, true);
    for (int i = 2; i < Maxn; i++)
        phi[i] = i;
    for (int i = 2; i < Maxn; i++) if (prime[i]) {
        phi[i] -= phi[i] / i;
        for (int j = i + i; j < Maxn; j += i) {
            phi[j] -= phi[j] / i;
            prime[j] = false;
        }
    }
    for (int i = 1; i < Maxn; i++)
        for (int j = i; j < Maxn; j += i)
            divs[j].push_back(i);
    scanf("%d", &n);
    for (int g0 = 1; g0 <= n; g0++) if (n % g0 == 0) {
        int lft = n / g0;
        for (int c = 1; c < lft; c++) {
            int rem = lft - c;
            for (int i = 0; i < divs[rem].size(); i++) {
                int g1 = divs[rem][i];
                if (gcd(g1, c) != 1) continue;
                res = (res + ll(g0) * g1 % mod * c % mod * phi[rem / g1]) % mod;
            }
        }
    }
    printf("%d\n", res);
    return 0;
}