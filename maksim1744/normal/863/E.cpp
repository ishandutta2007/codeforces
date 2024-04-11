/*
    18.05.2018 18:07:06
*/

#include <bits/stdc++.h>

using namespace std;

struct tel
{
    int l, r, num;
    tel(){}
};

const bool debug = false;

inline operator<(const tel & a, const tel & b)
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
    int test_count = 4;
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
        vector< tel > a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i].l >> a[i].r;
            a[i].num = i + 1;
        }
        sort(a.begin(), a.end());
        int ans = -1;
        int last = -1;
        for (int i = 0; i < n; ++i)
        {
            if (a[i].r <= last) {
                ans = a[i].num;
                break;
            }
            if (i < n - 1 && a[i + 1].l <= last + 1 && a[i + 1].r >= a[i].r) {
                ans = a[i].num;
                break;
            }
            last = max(last, a[i].r);
        }
        cout << ans << endl;
    }
    fclose(stdout);
    return 0;
}