/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#pragma pack(0)
#define int long long
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

struct block
{
    int l, r;
    block operator+(const block &b)
    {
        if (this->l == 0 && this->r == 0)
            return b;
        if (b.l == 0 && b.r == 0)
            return *this;
        if (this->r == b.l)
            return block{this->l, b.r};
        if (this->r < b.l)
            return block{this->l + b.l - this->r, b.r};
        return block{this->l, b.r + this->r - b.l};
    }
};
int n;
block seg[4000005];
string s;

void build(int l, int r, int i)
{
    if (l == r)
    {
        if (s[l] == '(')
            seg[i] = block{0, 1};
        else
            seg[i] = block{1, 0};
    }
    else
    {
        int mid = (l + r) / 2;
        build(l, mid, i * 2);
        build(mid + 1, r, i * 2 + 1);
        seg[i] = (seg[i * 2] + seg[i * 2 + 1]);
    }
}

block query(int l, int r, int i, int a, int b)
{
    //cout << "query " << l << " to " << r << '\n';
    if (b < l || r < a)
        return {0, 0};
    else if (a <= l && r <= b)
        return seg[i];
    else
    {
        int mid = (l + r) / 2;
        return query(l, mid, i * 2, a, b) + query(mid + 1, r, i * 2 + 1, a, b);
    }
}

signed main()
{

    fast;
    cin >> s;
    cin >> n;
    build(0, s.length() - 1, 1);
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        block res = query(0, s.length() - 1, 1, x - 1, y - 1);
        //cout << "len: " << y - x + 1 << "  l: " << res.l << "  r: " << res.r << '\n';
        cout << (y - x + 1) - res.l - res.r << '\n';
    }
}