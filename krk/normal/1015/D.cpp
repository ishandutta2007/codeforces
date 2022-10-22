#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, k;
ll s;

int main()
{
    cin >> n >> k >> s;
    if (ll(n - 1) * k < s || k > s) { printf("NO\n"); return 0; }
    ll a = s / k;
    ll b = s / k + 1;
    int timsb = s % k;
    int timsa = k - timsb;
    ll cur = 1;
    printf("YES\n");
    bool was = false;
    for (int i = 0; i < timsb; i++) {
        if (cur - b >= 1) cur -= b;
        else cur += b;
        if (was) printf(" ");
        else was = true;
        printf("%I64d", cur);
    }
    for (int i = 0; i < timsa; i++) {
        if (cur - a >= 1) cur -= a;
        else cur += a;
        if (was) printf(" ");
        else was = true;
        printf("%I64d", cur);
    }
    printf("\n");
    return 0;
}