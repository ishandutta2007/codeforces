#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
const int maxn = 505;
const int inf = 1e9;
const double eps = 1e-8;
const int base = 1073676287;


int main()
{
    srand(time(0));
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // ios_base::sync_with_stdio(false);
    int k;
    scanf ("%d", &k);
    ull ans = 0;
    while (k && ans < 1ULL * inf * inf)
        if (k & 1) {
            ans *= 10ULL;
            ans += 4ULL;
            --k;
        } else {
            ans *= 10ULL;
            ans += 8ULL;
            k -= 2;
        }
    if (!k && ans <= 1ULL * inf * inf)
        cout << ans << '\n';
    else
        cout << -1 << '\n';
}