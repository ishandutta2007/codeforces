#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-8;

int main()
{
    ios_base::sync_with_stdio(0);
    #if defined DEBUG
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    long long r, h;
    cin >> r >> h;
    r *= 2;
    h *= 2;
    long long res = (h + r / 2) / r;
    long long y = res * r - r / 2;
    long long L = h + r - y - r / 2;
    long long R = r * r * 3 / 4;
    res *= 2;
    if (L >= 0 && L * L >= R)
        res++;
    cout << res;

    return 0;
}