#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;
const int mod = 998244353;

int n;
vector <ll> seq;
int b[Maxn];
int res;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        seq.push_back(ll(a) * (i + 1) * (n - i));
    }
    sort(seq.rbegin(), seq.rend());
    for (int i = 0; i < n; i++)
        scanf("%d", &b[i]);
    sort(b, b + n);
    for (int i = 0; i < n; i++)
        res = (res + ll(b[i]) * (seq[i] % mod)) % mod;
    cout << res << endl;
    return 0;
}