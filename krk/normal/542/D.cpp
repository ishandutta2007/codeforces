#include <cstdio>
#include <map>
using namespace std;

typedef long long ll;
typedef pair <ll, ll> llll;

const ll lim = 1000000000001ll;
const int Maxn = 100000;

int nwmx[Maxn];
ll A;
map <ll, ll> zero;
map <llll, ll> vals;

ll newMax(ll A)
{
    for (ll i = 2; i * i <= A; i++)
        if (A % i == 0ll) {
            while (A % i == 0ll) A /= i;
            return A == 1? i: -1;
        }
    return A;
}

ll newMax(ll A, ll mx)
{
    if (A < Maxn) return nwmx[A] < mx? nwmx[A]: -1;
    for (ll i = 2; i * i <= A && i < mx; i++)
        if (A % i == 0ll) {
            while (A % i == 0ll) A /= i;
            return A == 1? i: -1;
        }
    return A < mx? A: -1;
}

ll Get(ll A, ll mx);

ll Find(ll A, ll dv, ll mx)
{
    if (dv >= 3) {
        mx = newMax(dv - 1, mx);
        if (mx != -1) return Get(A / dv, mx);
    }
    return 0ll;
}

ll Get(ll A, ll mx)
{
    if (A == 1ll) return 1;
    map <ll, ll>::iterator it = zero.find(A);
    if (it != zero.end() && it->second >= mx) return 0;
    map <llll, ll>::iterator it2 = vals.find(llll(A, mx));
    if (it2 != vals.end()) return it2->second;
    ll res = 0ll;
    for (ll i = 1; i * i <= A; i++)
        if (A % i == 0ll) {
            res += Find(A, i, mx);
            if (i * i != A) res += Find(A, A / i, mx);
        }
    if (res == 0ll) zero[A] = mx;
    else vals[llll(A, mx)] = res;
    return res;
}

int main()
{
    for (int i = 2; i < Maxn; i++)
        nwmx[i] = newMax(i);
    scanf("%I64d", &A);
    printf("%I64d\n", Get(A, lim));
    return 0;
}