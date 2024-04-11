#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define mp make_pair
#define pb push_back
using namespace std;
const int N = 1e5;

ll n, k, p = 1;

int main()
{
    cin >> n >> k;
    ll n1 = n, a1 = 0, a2 = 0;
    while (n % 5 == 0)
    {
        a1++;
        n /= 5;
    }
    while (n % 2 == 0)
    {
        a2++;
        n /= 2;
    }
    n = n1;
    while (a1 < k)
    {
        a1++;
        n *= 5;
    }
    while (a2 < k)
    {
        a2++;
        n *= 2;
    }
    cout << n;
    return 0;
}