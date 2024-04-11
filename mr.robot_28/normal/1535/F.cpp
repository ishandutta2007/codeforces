#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")

#include<bits/stdc++.h>
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long
using namespace std;
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int N = 2e5 + 100;
struct node{
    int tin, tout;
    int go_to[26];
    node(){fill(go_to, go_to + 26, -1);};
};
string s[N];
int pow1[N], pow2[N];
node nodes[N];
ll ans = 0;
ll cnt = 0;
vector <pair <int, int> > suf[N];
map <pair <pair <int, int>, int>, int> Tree[4 * N];
int iter = 0;
int timer = 0;
void go_to_all(int v)
{
    for(int j = 0; j < 26; j++)
    {
        if(nodes[v].go_to[j] != -1)
        {
            go_to_all(nodes[v].go_to[j]);
        }
        nodes[v].go_to[j] = -1;
    }
}
void f1(int v, int ind, int i)
{
    if(i == sz(s[ind]))
    {
        return;
    }
    if(nodes[v].go_to[s[ind][i] - 'a'] == -1)
    {
        nodes[v].go_to[s[ind][i] - 'a'] = iter++;
    }
    f1(nodes[v].go_to[s[ind][i] - 'a'], ind, i + 1);
}
void f2(int v)
{
    nodes[v].tin = timer++;
    for(int i = 0; i < 26; i++)
    {
        if(nodes[v].go_to[i] != -1)
        {
            f2(nodes[v].go_to[i]);
        }
    }
    nodes[v].tout = timer - 1;
 //   cout << v << " " << nodes[v].tin << " " << nodes[v].tout << "\n";
}
void add(int v, int l, int r, int idx, pair <pair <int, int>, int> hs)
{
    Tree[v][hs]++;
    if(l == r)
    {
        return;
    }
    if(idx <= (r + l) / 2)
    {
        add(v * 2, l, (r + l) / 2, idx, hs);
    }
    else
    {
        add(v * 2 + 1, (r + l) / 2 + 1, r, idx, hs);
    }
}
int cp(int v, int l, int r, int al, int ar, pair <pair <int, int>, int> hs)
{
    if(l >= al && r <= ar)
    {
        return Tree[v][hs];
    }
    if(l <= ar && r >= al)
    {
        return cp(v * 2, l, (r + l) / 2, al, ar, hs) + cp(v * 2 + 1, (r + l) / 2 + 1, r, al, ar, hs);
    }
    return 0;
}
int go_to_idx(int v, int ind, int i)
{
    if(i == sz(s[ind]))
    {
        return v;
    }
    return go_to_idx(nodes[v].go_to[s[ind][i] - 'a'], ind, i + 1);
}
void solve(vector <int> x)
{
   // cout << "A\n";
    timer = 0;
    iter = 1;
    cnt += 1LL * sz(x) *  (sz(x) - 1) / 2;
    for(auto i : x)
    {
        f1(0, i, 0);
    }
    f2(0);
    for(auto i : x)
    {
        int idx = go_to_idx(0, i, 0);
        pair <int, int> hs = {0, 0};
        add(1, 0, nodes[0].tout, nodes[idx].tin, make_pair(make_pair(0, 0), 0));
        for(int j = 1; j <= sz(s[i]); j++)
        {
            hs.X = (1LL * hs.X * 27 + s[i][sz(s[i]) - j] - 'a' + 1) % mod1;
            hs.Y = (1LL * hs.Y * 27 + s[i][sz(s[i]) - j] - 'a' + 1) % mod2;
            add(1, 0, nodes[0].tout, nodes[idx].tin, make_pair(hs, j));
        }
    }
    for(auto i : x)
    {
        int idx = 0;
        for(int j = 0; j < sz(s[i]); j++)
        {
            int k = j;
            while(k + 1 < sz(s[i]) && s[i][k + 1] >= s[i][k])
            {
                k++;
            }
            ans += cp(1, 0, nodes[0].tout, nodes[idx].tin, nodes[idx].tout, {suf[i][k + 1], sz(s[i]) - 1 - k}) - 1;
            for(int p = j; p <= k; p++)
            {
                idx = nodes[idx].go_to[s[i][p] - 'a'];
            }
            j = k;
        }
    }
    for(int j = 0; j < 4 * (1 + nodes[0].tout); j++)
    {
        Tree[j].clear();
    }
    go_to_all(0);
}
signed main()
{
   // ifstream cin("rt.txt.txt");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    pow1[0] = 1;
    pow2[0] = 1;
    for(int i = 1; i < N; i++)
    {
        pow1[i] = 1LL * pow1[i - 1] * 27 % mod1;
        pow2[i] = 1LL * pow2[i - 1] * 27 % mod2;
    }
    map <vector <int>, vector <int> > mp;
    for(int i = 0; i < n; i++)
    {
        vector <int> cnt(26);
        cin >> s[i];
        suf[i].resize(sz(s[i]) + 1);
        suf[i][sz(s[i])] = {0, 0};
        for(int j = sz(s[i]) - 1; j >= 0; j--)
        {
            suf[i][j].X = (1LL * suf[i][j + 1].X * 27 + s[i][j] - 'a' + 1) % mod1;
            suf[i][j].Y = (1LL * suf[i][j + 1].Y * 27 + s[i][j] - 'a' + 1) % mod2;
        }
        for(int j = 0; j < sz(s[i]); j++)
        {
            cnt[s[i][j] - 'a']++;
        }
        mp[cnt].push_back(i);
    }
    for(auto p : mp)
    {
        solve(p.Y);
    }
    cout << (cnt - ans) * 2 + ans + ((n - 1) * n / 2 - cnt) * 1337;
    return 0;
}