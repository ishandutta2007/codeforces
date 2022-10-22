#include <bits/stdc++.h>
using namespace std;

int t;
long long n, k;

int main()
{
    cin >> t;
    while (t--) {
        cin >> n >> k;
        long long res = 0;
        while (n) {
            res += n % k;
            n /= k; res++;
        }
        res--;
        printf("%lld\n", res);
    }
    return 0;
}