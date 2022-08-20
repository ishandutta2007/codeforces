/*
    06.05.2018 19:47:57
*/

#include <bits/stdc++.h>

using namespace std;

const bool debug = false;

typedef pair<int, int> pi;

struct otr
{
    int l, r, num;
    otr() {}
};

bool comp(otr a, otr b)
{
    if (a.l != b.l) {
        return a.l < b.l;
    }
    return a.r > b.r;
}

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
        vector< otr > a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i].l >> a[i].r;
            a[i].num = i + 1;
        }
        sort(a.begin(), a.end(), comp);
        bool ok = false;
        for (int i = 1; i < n; ++i)
        {
            if (a[i].r <= a[i - 1].r) {
                ok = true;
                cout << a[i].num << ' ' << a[i - 1].num << endl;
                break;
            }
        }
        if (!ok) {
            cout << -1 << ' ' << -1 << endl;
        }
    }
    fclose(stdout);
    return 0;
}