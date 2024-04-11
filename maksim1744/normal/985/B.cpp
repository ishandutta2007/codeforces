/*
    21.05.2018 17:54:47
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
        int n, m;
        cin >> n >> m;
        vector< vector< int > > p(n);
        vector< int > c(m, 0);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                char ch;
                cin >> ch;
                if (ch == '1') {
                    p[i].push_back(j);
                    c[j]++;
                }
            }
        }
        string ans = "NO";
        for (int i = 0; i < n; ++i)
        {
            bool ok = true;
            for (int j = 0; j < p[i].size(); ++j)
            {
                if (c[p[i][j]] <= 1) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ans = "YES";
                break;
            }
        }
        cout << ans << endl;
    }
    fclose(stdout);
    return 0;
}