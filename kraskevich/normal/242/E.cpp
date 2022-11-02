#include <iostream>
#include <algorithm>
#include <cstdio>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

const int N = 1000 * 100 + 1;

bool bit(int mask, int pos)
{
    return ((mask & (1 << pos)) ? 1 : 0);
}

struct segm_tree
{
    int t[4 * N];
    bool rev[4 * N];
    
    void init()
    {
        for (int i = 0; i < 4 * N; ++i)
            t[i] = rev[i] = 0;
    }
    void makeXor(int i, int l, int r, int tl, int tr, bool now)
    {
        if (l == tl && r == tr)
        {
            rev[i] = (rev[i] ^ now);
        }
        else
        {
            int ll = 2 * i + 1, rr = 2 * i + 2, m = (tl + tr) / 2;
            if (l <= m)
                makeXor(ll, l, min(m, r), tl, m, now);
            if (r > m)
                makeXor(rr, max(l, m + 1), r, m + 1, tr, now);
                
            t[i] = 0;
            
            if (rev[ll])
                t[i] = m - tl + 1 - t[ll];
            else
                t[i] = t[ll];
                
            if (rev[rr])
                t[i] += tr - m - t[rr];
            else
                t[i] += t[rr];
        }
    }
    int getSum(int i, int l, int r, int tl, int tr, bool now)
    {
        now ^= rev[i];
        if (l == tl && r == tr)
            return (now ? tr - tl + 1 - t[i] : t[i]);
        int sl = 0, sr = 0, ll = 2 * i + 1, rr = 2 * i + 2, m = (tl + tr) / 2;
        if (l <= m)
            sl = getSum(ll, l, min(m, r), tl, m, now);
        if (r > m)
            sr = getSum(rr, max(m + 1, l), r, m + 1, tr, now);
        return sl + sr;
    }
};

segm_tree bits[20];

void init()
{
    for (int i = 0; i < 20; ++i)
        bits[i].init();
}

void makeXor(int x, int l, int r)
{
    for (int i = 0; i < 20; ++i)
        bits[i].makeXor(0, l, r, 0, N - 1, bit(x, i));
}

long long getSum(int l, int r)
{
    long long res = 0;
    for (int i = 0; i < 20; ++i)
    {
        int cur = bits[i].getSum(0, l, r, 0, N - 1, 0);
        res += (1ll << i) * cur;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    
    init();
    
    int n;
    cin >> n;
    
    for (int i = 0; i < n; ++i)
    {
        int a;
        cin >> a;
        
        makeXor(a, i, i);
    }
    
    int m;
    cin >> m;
    
    for (int i = 0; i < m; ++i)
    {
        int t;
        cin >> t;
        
        if (t == 1)
        {
            int l, r;
            cin >> l >> r;
            --l;
            --r;
            cout << getSum(l, r) << "\n";
        }
        else
        {
            int l, r, x;
            cin >> l >> r >> x;
            makeXor(x, l - 1, r - 1);
        }
    }
    
    return 0;
}