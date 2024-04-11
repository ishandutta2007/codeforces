#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b)
{
    if (a < b)
        swap(a, b);
    return b ? gcd(b, a % b) : a;
}

long long solve(long long a, long long b)
{
    long long g = gcd(a, b);
    a /= g;
    b /= g;
    if (b == 1)
        return a;
    if (a == 1)
        return b;
    if (a > b)
        return solve(a % b, b) + a / b;
    else
        return solve(a, b % a) + b / a;
}

int main()
{
    #if defined DEBUG
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    long long a, b;
    cin >> a >> b;
    cout << solve(a, b);

    return 0;
}