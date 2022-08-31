/*
    07.05.2018 16:48:48
*/

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

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
        vector< int > d(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> d[i];
        }
        int i1 = 0, i2 = n - 1;
        int sm = 0;
        int lastv = d[n - 1];
        vector< pi > v;
        while (i2 > i1) {
            int d1 = d[i1] - sm;
            int dn = d[i2] - sm;
            for (int i = 0; i < d1; ++i)
            {
                for (int j = 0; j < dn - i; ++j)
                {
                    v.push_back(pi(lastv - i + 1, lastv - i - j));
                }
            }
            sm += d1;
            lastv = d[i2 - 1] - sm;
            i1++; i2--;
        }
        if (n % 2 == 1) {
            for (int i = 0; i <= lastv; ++i)
            {
                for (int j = 0; j < i; ++j)
                {
                    v.push_back(pi(i + 1, j + 1));
                }
            }
        }
        cout << v.size() << endl;
        for (int i = 0; i < v.size(); ++i)
        {
            cout << v[i].first << ' ' << v[i].second << endl;
        }
    }
    fclose(stdout);
    return 0;
}