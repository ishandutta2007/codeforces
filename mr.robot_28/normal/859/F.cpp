#include<bits/stdc++.h>
#define X first
#define Y second
#define ll long long
#define sz(a) (int)a.size()
using namespace std;
#define int long long
const int N = 3e5 + 100;
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
int Tree[4  * N];
int s[N * 2];
void upd(int v, int l, int r, int idx, int val)
{
    if(l == r)
    {
        Tree[v] = val;
        return;
    }
    int m = (r + l) / 2;
    if(idx <= m)
    {
        upd(v * 2, l, m, idx, val);
    }
    else
    {
        upd(v * 2 + 1, m + 1, r, idx, val);
    }
    Tree[v] = max(Tree[v * 2], Tree[v * 2 + 1]);
}
int get(int v, int l, int r, int al, int ar)
{
    if(l >= al && r <= ar)
    {
        return Tree[v];
    }
    if(l <= ar && r >= al)
    {
        return max(get(v * 2, l, (r + l) / 2, al, ar), get(v * 2 + 1, (r + l) / 2 + 1, r, al, ar));
    }
    return -1e9;
}
int t[N];
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    fill(Tree, Tree + 4 * N, -1e9);
    upd(1, 0, n, 0, 0);
    s[0] = 0;
    for(int i = 1; i <= n * 2 - 1; i++)
    {
        cin >> s[i];
        s[i] += s[i - 1];
    }
    int j = 0;
    for(int i = 1; i <= n; i++)
    {
        while(j < i && s[i * 2 - 1] - s[j * 2] > k)
        {
            j++;
        }
        if(j > 0)
        {
            t[i] = t[j - 1] + k;
        }
        if(j < i)
        {
            t[i] = max(t[i], s[i * 2 - 1] + get(1, 0, n, j, i - 1));
        }
        upd(1, 0, n, i, t[i] - s[i * 2]);
    }
    cout << t[n];
    return 0;
}