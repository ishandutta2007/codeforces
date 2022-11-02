#include <algorithm>
#include <iostream>
#include <string.h>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <cstdio>
#include <vector>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <sstream>

using namespace std;

struct segm
{
    int l, r, id;
    segm() {}
    segm(int _l, int _r, int _id): l(_l), r(_r), id(_id) {}
};

const int N = 2 * 1000 * 1000;
segm s[N];
vector<segm> cur;
bool need[N];

bool cmp(segm a, segm b)
{
    return a.l < b.l || a.l == b.l && a.r > b.r;
}


int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    int mxr = 0;
    for (int i = 0; i < m; i++)
    {
        int a, l;
        cin >> a >> l;
        int L = a;
        int R = a + l - 1;
        mxr = max(mxr, R);
        s[i] = segm(L, R, i);
    }
    fill(need, need + m, false);
    sort(s, s + m, cmp);
    need[s[0].id] = true;
    int r = s[0].r;
    segm best = s[0];
    int p = 0;
    for (;;)
    {
        if (r == mxr)
            break;
        while (p + 1 < m && s[p + 1].l <= r + 1)
        {
            p++;
            if (s[p].r > best.r)
                best = s[p];
        }
        need[best.id] = true;
        r = best.r;
        if (r == mxr)
            break;
        if (s[p + 1].l > r)
        {
            p++;
            need[s[p].id] = true;
            best = s[p];
            r = best.r;
        }
    }
    int res = 0;
    for (int i = 0; i < m; i++)
        if (!need[i])
            res++;
    cout << res << "\n";
    for (int i = 0; i < m; i++)
        if (!need[i])
            cout << i + 1 << " ";

    return 0;
}