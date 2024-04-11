/*
    08.05.2018 18:24:28
*/

#include <bits/stdc++.h>

using namespace std;

const bool debug = false;

int main(int argc, char const *argv[])
{
    if (debug) {
        freopen("inputC.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    int t = 3;
    if (!debug) {
        t = 1;
    }
    for (int test = 0; test < t; ++test)
    {
        if (debug) {
            cout << "Case #" << test + 1 << ":\n";
        }
        int n, k;
        cin >> n >> k;
        vector< int > p(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> p[i];
        }
        vector< int > col(256, -1);
        vector< int > cnt(256, 0);
        for (int ind = 0; ind < n; ++ind)
        {
            int i = p[ind];
            if (col[i] != -1) {
                continue;
            }
            int c = max(i - k + 1, 0);
            for (int j = 0; j < k; ++j)
            {
                if (i - j < 0) {
                    break;
                }
                if (col[i - j] != -1) {
                    c = i - j + 1;
                    if (k - cnt[col[i - j]] + i - j >= i) {
                        c = col[i - j];
                    }
                    break;
                }
            }
            for (int j = c; j < i + 1; ++j)
            {
                if (col[j] != c) {
                    cnt[c]++;
                }
                col[j] = c;
            }
        }
        for (int i = 0; i < n; ++i)
        {
            cout << col[p[i]] << ' ';
        }
        cout << endl;
    }
    fclose(stdout);
    return 0;
}