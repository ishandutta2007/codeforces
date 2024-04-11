/*
    01.08.2018 16:36:41
*/

#include <bits/stdc++.h>

using namespace std;

const bool debug = false;

void showv(vector< long long > vect, bool endline=true) {
    cout << "[";
    for (int i = 0; i < (int)vect.size() - 1; ++i)
    {
        cout << vect[i] << ", ";
    }
    if (vect.size() > 0) {
        cout << vect[vect.size() - 1];
    }
    cout << "]";
    if (endline) {
        cout << endl;
    }
}

int main(int argc, char const *argv[])
{
    if (debug) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    int test_count = 4;
    if (!debug) {
        test_count = 1;
    }
    for (int test = 0; test < test_count; ++test)
    {
        if (debug) {
            cout << "Case #" << test + 1 << ":\n";
        }
        int n;
        cin >> n;
        vector< long long > a(2 * n);
        for (int i = 0; i < 2 * n; ++i)
        {
            cin >> a[i];
        }
        if (n == 1) {
            cout << 0 << endl;
            continue;
        }
        sort(a.begin(), a.end());
        // showv(a);
        long long p = a[2 * n - 1] - a[0];
        long long ans = (a[2 * n - 1] - a[n]) * (a[n - 1] - a[0]);
        for (int i = 1; i + n - 1 < 2 * n - 1; i++) {
            ans = min(ans, p * (a[i + n - 1] - a[i]));
        }
        cout << ans << endl;
    }
    fclose(stdout);
    return 0;
}