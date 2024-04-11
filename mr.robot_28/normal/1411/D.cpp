#include<bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define sz(a) (int)a.size()

using namespace std;
#define int long long
vector <int> tree, upd;
void update(int v, int l, int r, int ind, int val)
{
    tree[v] += val;
    if(l == r)
    {
        return;
    }
    if(ind <= (r + l)/ 2)
    {
        update(v * 2, l, (r + l) / 2, ind, val);
    }
    else
    {
        update(v * 2 + 1, (r + l) / 2 + 1, r, ind, val);
    }
}
int ans(int v, int l, int r, int al, int ar)
{
    if(l >= al && r <= ar)
    {
        return tree[v];
    }
    else if(l <= ar && r >= al)
    {
        return ans(v * 2, l, (r + l)/ 2, al, ar) + ans(v * 2 + 1, (r + l) / 2 + 1, r, al, ar);
    }
    return 0;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    int x, y;
    cin >> x >> y;
    tree.resize(4 * n);
    int c =0;
    for(int i = 0; i < n; i++)
    {
        if(s[i] == '1')
        {
            update(1, 0, n - 1, i, 1);
        }
    }
    int ansx = 0;
    int cnt0 = 0, cnt1 = 0;
    for(int i = 0; i < n; i++)
    {
        if(s[i] == '1')
        {
            ansx += cnt0 * x;
            cnt1++;
        }
        else
        {
            ansx += cnt1 * y;
            cnt0++;
        }
    }
    int ans0 = ansx;
    int ans1 = ansx;
    for(int i = 0; i < n; i++)
    {
        if(s[i] != '?')
        {
            continue;
        }
        int c1 = 0;
        if(i != 0)
        {
            c1 = ans(1, 0, n - 1, 0, i - 1);
        }
        int c2 = 0;
        if(i != n - 1)
        {
            c2 = ans(1, 0, n - 1, i + 1, n - 1);
        }
        ansx += -c1 * y + (i - c1) * x + y * (n - i - 1 - c2) - x * c2;
        ans0 = min(ans0, ansx);
        update(1, 0, n - 1, i, 1);
    }
    ansx = ans1;
    for(int i = 0; i < n; i++)
    {
        if(s[i] == '?')
        {
            update(1, 0, n - 1, i, -1);
        }
    }
    for(int i = n - 1; i >= 0; i--)
    {
        if(s[i] != '?')
        {
            continue;
        }
        int c1 = 0;
        if(i != 0)
        {
            c1 = ans(1, 0, n - 1, 0, i - 1);
        }
        int c2 = 0;
        if(i != n - 1)
        {
            c2 = ans(1, 0, n - 1, i + 1, n - 1);
        }
        ansx += -c1 * y + (i - c1) * x + y * (n - i - 1 - c2) - x * c2;
        ans0 = min(ans0, ansx);
        update(1, 0, n - 1, i, 1);
    }
    cout << ans0;
    return 0;
}