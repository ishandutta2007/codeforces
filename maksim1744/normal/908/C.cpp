/*
    05.05.2018 15:15:55
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
    int t = 1;
    if (!debug) {
        t = 1;
    }
    for (int test = 0; test < t; ++test)
    {
        if (debug) {
            cout << "Case #" << test + 1 << ":\n";
        }
        int n, r;
        cin >> n >> r;
        vector< int > x(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> x[i];
        }
        vector< double > y(n);
        y[0] = r;
        for (int i = 1; i < n; ++i)
        {
            double mx = r;
            for (int j = 0; j < i; ++j)
            {
                if (abs(x[i] - x[j]) > r * 2) {
                    continue;
                }
                double h = sqrt((double) (r * r * 4) - (double) ((x[i] - x[j]) * (x[i] - x[j])));
                mx = max(mx, h + y[j]);
            }
            y[i] = mx;
        }
        for (int i = 0; i < n; ++i)
        {
            cout << setprecision(10) << y[i] << ' ';
        }
        cout << endl;
    }
    fclose(stdout);
    return 0;
}