/*
    27.05.2018 17:59:33
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
    int test_count = 2;
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
        map< long long, long long > mp;
        long long sm = 0;
        for (int i = 0; i < n; ++i)
        {
            long long a, x;
            cin >> a >> x;
            mp[a] = x;
            sm += x;
        }
        int m;
        cin >> m;
        for (int i = 0; i < m; ++i)
        {
            long long a, x;
            cin >> a >> x;
            if (mp.find(a) == mp.end()) {
                sm += x;
            }
            else {
                if (mp[a] < x) {
                    sm += x - mp[a];
                }
            }
        }
        cout << sm << endl;
    }
    fclose(stdout);
    return 0;
}