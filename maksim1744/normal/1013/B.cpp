/*
    01.08.2018 17:51:02
*/

#include <bits/stdc++.h>

using namespace std;

const bool debug = false;

int main(int argc, char const *argv[])
{
    if (debug) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    int test_count = 3;
    if (!debug) {
        test_count = 1;
    }
    for (int test = 0; test < test_count; ++test)
    {
        if (debug) {
            cout << "Case #" << test + 1 << ":\n";
        }
        int n, x;
        cin >> n >> x;
        vector< int > a(n), b;
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int ans = -1;
        for (int i = 0; i < n - 1; ++i)
        {
            if (a[i] == a[i + 1]) {
                ans = 0;
                cout << "0\n";
                break;
            }
        }
        if (ans != -1) {
            continue;
        }
        for (int i = 0; i < n; ++i)
        {
            if (a[i] != (a[i] & x)) {
                b.push_back(a[i] & x);
            }
        }
        sort(b.begin(), b.end());
        set< int > s;
        for (int i = 0; i < b.size(); ++i)
        {
            s.insert(b[i]);
        }
        for (int i = 0; i < n; ++i)
        {
            if (s.find(a[i]) != s.end()) {
                ans = 1;
                cout << "1\n";
                break;
            }
        }
        if (ans != -1) {
            continue;
        }
        if (s.size() < b.size()) {
            cout << "2\n";
        }
        else {
            cout << "-1\n";
        }
    }
    fclose(stdout);
    return 0;
}