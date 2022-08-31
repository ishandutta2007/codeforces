#include <bits/stdc++.h>

using namespace std;

const bool debug = false;

struct it
{
    int lt, rt, c, p;
    it(int c): lt(-1), rt(-1), c(c), p(-1) {}
    int operator[] (int i)
    {
        if (i == 0) {
            return lt;
        }
        if (i == 1) {
            return rt;
        }
    }
};

vector< it > tree;

int main(int argc, char const *argv[])
{
    if (debug) {
        freopen("input.txt", "r", stdin);
    }
    int n;
    cin >> n;
    vector< int > a(n);
    vector< int > p(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    tree.push_back(it(0));
    for (int i = 0; i < n; i++) {
        int k = p[i];
        vector< int > bn(30, 0);
        int ind = 0;
        while (k > 0) {
            bn[ind] = k % 2;
            k /= 2;
            ind++;
        }
        reverse(bn.begin(), bn.end());
        int v = 0;
        for (int j = 0; j < 30; j++) {
            if (bn[j] == 1) {
                if (tree[v].rt == -1) {
                    tree[v].rt = tree.size();
                    tree.push_back(it(0));
                    tree[tree[v].rt].p = v;
                }
                v = tree[v].rt;
            }
            else {
                if (tree[v].lt == -1) {
                    tree[v].lt = tree.size();
                    tree.push_back(it(0));
                    tree[tree[v].lt].p = v;
                }
                v = tree[v].lt;
            }
        }
        while (v != -1) {
            tree[v].c++;
            v = tree[v].p;
        }
    }
    vector< int > ans(n);
    for (int i = 0; i < n; i++) {
        int k = a[i];
        vector< int > bn(30, 0);
        int ind = 0;
        while (k > 0) {
            bn[ind] = k % 2;
            k /= 2;
            ind++;
        }
        reverse(bn.begin(), bn.end());
        vector< int > xr(30, 0);
        int v = 0;
        for (int j = 0; j < 30; j++) {
            if (tree[v][bn[j]] != -1 && tree[tree[v][bn[j]]].c > 0) {
                v = tree[v][bn[j]];
                xr[j] = bn[j];
            }
            else {
                v = tree[v][1 - bn[j]];
                xr[j] = 1 - bn[j];
            }
        }
        while (v != -1) {
            tree[v].c--;
            v = tree[v].p;
        }
        int p2 = 1;
        int xri = 0;
        for (int j = 29; j >= 0; j--) {
            xri += xr[j] * p2;
            p2 *= 2;
        }
        ans[i] = xri ^ a[i];
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
    return 0;
}