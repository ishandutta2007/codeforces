/*
    30.05.2018 16:52:36
*/

#include <bits/stdc++.h>

using namespace std;

const bool debug = false;

vector<int> t;
int n;

void init (int nn)
{
    n = nn;
    t.assign (n, 0);
}

int sum (int r)
{
    int result = 0;
    for (; r >= 0; r = (r & (r+1)) - 1)
        result += t[r];
    return result;
}

void inc (int i, int delta)
{
    for (; i < n; i = (i | (i+1)))
        t[i] += delta;
}

int sum (int l, int r)
{
    return sum (r) - sum (l-1);
}

void init (vector<int> a)
{
    init ((int) a.size());
    for (unsigned i = 0; i < a.size(); i++)
        inc (i, a[i]);
}

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
        int w, s;
        cin >> w >> s;
        vector< int > a(w - 1);
        for (int i = 0; i < w - 1; ++i)
        {
            cin >> a[i];
        }
        init(a);
        int mn = 1000000000;
        for (int i = 0; i < w - s; ++i)
        {
            // cout << i << ' ' << i + s - 1 << ' ' << sum(i, i + s - 1) << endl;
            mn = min(mn, sum(i, i + s - 1));
        }
        cout << mn << endl;
    }
    fclose(stdout);
    return 0;
}