#include <bits/stdc++.h>

using namespace std;

const bool debug = false;

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
        long long n, q;
        cin >> n >> q;
        vector< long long > a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        vector< long long > sm(n + 1);
        sm[0] = 0;
        for (int i = 0; i < n; ++i)
        {
            sm[i + 1] = sm[i] + a[i];
        }
        long long nk = 0;
        for (int i = 0; i < q; ++i)
        {
            long long k;
            cin >> k;
            nk += k;
            if (nk >= sm[n]) {
                nk = 0;
                cout << n << '\n';
            }
            else {
                long long l = 0, r = n + 1;
                while (r - l > 1) {
                    long long c = (r - l) / 2 + l;
                    bool left = true;
                    left = (nk >= sm[c]);
                    if (left) {
                        l = c;
                    }
                    else {
                        r = c;
                    }
                }
                cout << n - l << '\n';
            }
        }
    }
    fclose(stdout);
    return 0;
}