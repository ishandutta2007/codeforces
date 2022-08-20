/*
    05.05.2018 20:27:24
*/

#include <bits/stdc++.h>

using namespace std;

const bool debug = false;

long long allc(long long n)
{
    if (n <= 1) {
        return 1;
    }
    return 2ll * allc(n / 2) + 1;
}

long long cnt(long long n, long long k)
{
    long long cn = allc(n);
    if (k == 0) {
        return 0;
    }
    if (k == cn) {
        return n;
    }
    if (k <= cn / 2) {
        return cnt(n / 2, k);
    }
    else {
        return (long long) (n % 2) + cnt(n / 2, k - cn / 2 - 1) + n / 2;
    }
}

int main(int argc, char const *argv[])
{
    if (debug) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    int t = 2;
    if (!debug) {
        t = 1;
    }
    for (int test = 0; test < t; ++test)
    {
        if (debug) {
            cout << "Case #" << test + 1 << ":\n";
        }
        long long n, l, r;
        cin >> n >> l >> r;
        cout << cnt(n, r) - cnt(n, l - 1) << endl;
    }
    fclose(stdout);
    return 0;
}