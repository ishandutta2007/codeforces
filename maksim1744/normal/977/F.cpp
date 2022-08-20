/*
    06.05.2018 17:45:07
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
    int t = 4;
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
        vector< int > a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        map< int, int > m;
        vector< int > mx(n, 1);
        for (int i = 0; i < n; ++i)
        {
            if (m.count(a[i] - 1) != 0) {
                mx[i] = mx[m[a[i] - 1]] + 1;
            }
            m[a[i]] = i;
        }
        int imx = -1;
        int mxk = 0;
        for (int i = 0; i < n; ++i)
        {
            if (mx[i] > mxk) {
                imx = i;
                mxk = mx[i];
            }
        }
        vector< int > ans;
        int now = a[imx];
        for (int i = n - 1; i >= 0; i--) {
            if (a[i] == now) {
                ans.push_back(i + 1);
                now--;
            }
        }
        reverse(ans.begin(), ans.end());
        cout << mxk << endl;
        for (int i = 0; i < mxk; ++i)
        {
            cout << ans[i] << ' ';
        }
        cout << endl;
    }
    fclose(stdout);
    return 0;
}