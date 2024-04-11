#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

typedef long long ll;

ll n;
map <ll, bool> win;
map <ll, ll> p;

bool Win(ll n)
{
    if (win.find(n) == win.end()) {
        bool w = false, was = false;
        ll rec = 0;
        for (ll i = 2LL; i * i <= n && !w; i++)
            if (n % i == 0LL) {
                if (!Win(i)) { w = true; rec = i; }
                if (!Win(n / i)) { w = true; rec = n / i; }
                was = true;
            }
        win[n] = w || !was; p[n] = rec;
    }
    return win[n];
}

int main()
{
    scanf("%I64d", &n);
    if (Win(n)) printf("1\n%I64d\n", p[n]);
    else printf("2\n");
    return 0;
}