/*
    06.05.2018 17:22:32
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
    int t = 3;
    if (!debug) {
        t = 1;
    }
    for (int test = 0; test < t; ++test)
    {
        if (debug) {
            cout << "Case #" << test + 1 << ":\n";
        }
        int n;
        cin >> n;
        vector< long long > a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        vector< vector< long long > > d3(40);
        for (int i = 0; i < n; ++i)
        {
            long long k = a[i];
            int t = 0;
            while (k % 3 == 0) {
                t++;
                k /= 3;
            }
            d3[t].push_back(a[i]);
        }
        reverse(d3.begin(), d3.end());
        for (int i = 0; i < 40; ++i)
        {
            sort(d3[i].begin(), d3[i].end());
        }
        for (int i = 0; i < 40; ++i)
        {
            for (int j = 0; j < d3[i].size(); ++j)
            {
                cout << d3[i][j] << ' ';
            }
        }
        cout << endl;
    }
    fclose(stdout);
    return 0;
}