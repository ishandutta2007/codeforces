/*
    07.05.2018 17:23:12
*/

#include <bits/stdc++.h>

using namespace std;

const bool debug = false;

struct hero
{
    long long hp, dmg;
    hero() {}
};

bool comp(hero a, hero b)
{
    return a.hp - a.dmg > b.hp - b.dmg;
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
        int n, a, b;
        cin >> n >> a >> b;
        b = min(b, n);
        vector< hero > v(n);
        long long mx = 0, mxi = -1;
        long long k = 1 << a;
        for (int i = 0; i < n; ++i)
        {
            cin >> v[i].hp >> v[i].dmg;
            long long d = v[i].hp * k - max(v[i].dmg, v[i].hp);
            if (d > mx) {
                mxi = i;
                mx = d;
            }
        }
        sort(v.begin(), v.end(), comp);
        long long sm = 0;
        mx = 0;
        for (int i = 0; i < n; ++i)
        {
            sm += v[i].dmg;
            if (i < b) {
                sm += max(0ll, v[i].hp - v[i].dmg);
            }
        }
        for (int i = 0; i < n; ++i)
        {
            long long d = 0;
            if (i < b) {
                d = v[i].hp * k - max(v[i].hp, v[i].dmg);
            }
            else if (b > 0) {
                d = v[i].hp * k - v[i].dmg - (max(v[b - 1].hp, v[b - 1].dmg) - v[b - 1].dmg);
            }
            mx = max(mx, d);
            if (debug) {
                cout << "d(" << i + 1 << ") = " << d << endl;
            }
        }
        if (debug) {
            cout << "sm = " << sm << endl << "mx = " << mx << endl;
        }
        cout << sm + mx << endl;
    }
    fclose(stdout);
    return 0;
}