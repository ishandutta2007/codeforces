/*
    29.05.2018 18:56:53
*/

#include <bits/stdc++.h>

using namespace std;

const bool debug = false;

// struct item
// {
//     int l, r, v, p;
//     item(): l(-1), r(-1), v(0), p(-1) {}
// };

// vector< item > tree(1);
// int last = 0;
// int n;

// void build(int i = 0, int vl = 0, int vr = n - 1) {
//     if (vr > vl) {
//         int m = (vr + vl) / 2;
//         tree.push_back(item());
//         tree.push_back(item());
//         tree[i].l = last + 1;
//         tree[i].r = last + 2;
//         tree[last + 1].p = i;
//         tree[last + 2].p = i;
//         last += 2;
//         int k = last;
//         build(k - 1, vl, m);
//         build(k, m + 1, vr);
//     }
//     tree[i].v = 0;
// }

// void add(int k, int i = 0, int l = 0, int r = n - 1) {
//     if (l >= r) {
//         tree[i].v++;
//         return;
//     }
//     int m = (l + r) / 2;
//     tree[i].v++;
//     if (k <= m) {
//         add(k, tree[i].l, l, m);
//     }
//     else {
//         add(k, tree[i].r, m + 1, r);
//     }
// }

// int ask(int l, int r, int i = 0, int vl = 0, int vr = n - 1) {
//     if (l == vl && r == vr) {
//         return tree[i].v;
//     }
//     int m = (vl + vr) / 2;
//     if (r <= m) {
//         return ask(l, r, tree[i].l, vl, m);
//     }
//     if (l > m) {
//         return ask(l, r, tree[i].r, m + 1, vr);
//     }
//     return ask(l, m, tree[i].l, vl, m) + ask(m + 1, r, tree[i].r, m + 1, vr);
// }

vector< int > t;
int n;

void init ()
{
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

int main(int argc, char const *argv[])
{
    if (debug) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    int test_count = 1;
    if (!debug) {
        test_count = 1;
    }
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    for (int test = 0; test < test_count; ++test)
    {
        if (debug) {
            cout << "Case #" << test + 1 << ":\n";
        }
        cin >> n;
        vector< int > a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            a[i]--;
        }
        // reverse(a.begin(), a.end());
        init();
        int p = 0;
        for (int i = 0; i < n; ++i)
        {
            p += sum(a[i], n - 1);
            p = p & 1;
            inc(a[i], 1);
        }
        if (n % 2 == 0) {
            p = 1 - p;
        }
        if (p == 0) {
            cout << "Um_nik" << endl;
        }
        else {
            cout << "Petr" << endl;
        }
    }
    fclose(stdout);
    return 0;
}