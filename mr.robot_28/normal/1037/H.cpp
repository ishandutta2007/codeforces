#include<bits/stdc++.h>
#define X first
#define Y second
#define sz(a) (int)a.size()
using namespace std;
const int N = 3e5 + 100;
const int mod = 1e9 + 7;
string s;
int n;
int cnt[N];
int st[N];
int idx[N];
int new_idx[N];
int color[N], new_color[N];
const int mod1 = 998244353;
const int mod2 = 1e9 + 7;
void build()
{
    int n1 = max(30, n);
    for(int i = 0; i < n; i++)
    {
        cnt[s[i] - 'a' + 1]++;
    }
    for(int i =1; i < n1; i++)
    {
        st[i] = st[i - 1] + cnt[i - 1];
    }
    for(int i = 0; i < n; i++)
    {
        idx[st[s[i] - 'a' + 1]++] = i;
    }
    int f = 0;
    for(int i = 0; i < n; i++)
    {
        if(i != 0 && s[idx[i - 1]] != s[idx[i]])
        {
            f++;
        }
        color[idx[i]] = f;
    }
    for(int l = 0; (1 << l) <= n; l++)
    {
        for(int i = 0; i < n1; i++)
        {
            cnt[i] = 0;
        }
        for(int i = 0; i < n; i++)
        {
            cnt[color[i]]++;
        }
        st[0] =0;
        for(int i = 1; i < n1; i++)
        {
            st[i] = st[i - 1] + cnt[i - 1];
        }
        for(int i = 0; i < n; i++)
        {
            int i1 = (idx[i] - (1 << l) + n) % n;
            new_idx[st[color[i1]]++] = i1;
        }
        f= 0;
        for(int i = 0; i < n; i++)
        {
            idx[i] = new_idx[i];
            if(i != 0 && (color[idx[i]] != color[idx[i - 1]] || color[(idx[i] + (1 << l)) % n] != color[(idx[i - 1] + (1 << l)) % n]))
            {
                f++;
            }
            new_color[idx[i]] = f;
        }
        for(int i = 0; i < n; i++)
        {
            color[i] = new_color[i];
        }
    }
}
vector <int> Tree[N * 4];
vector <int> it_left[N * 4], it_right[N * 4];
void build_tree(int v, int l, int r)
{
    if(l == r)
    {
        Tree[v].push_back(idx[l]);
        return;
    }
    build_tree(v * 2, l, (r + l) / 2);
    build_tree(v * 2 + 1, (r + l) / 2 + 1, r);
    it_left[v].resize(r - l + 1);
    it_right[v].resize(r - l + 1);
    int j = 0;
    for(int i = 0; i < sz(Tree[v * 2]); i++)
    {
        while(j < sz(Tree[v * 2 + 1]) && Tree[v * 2 + 1][j] < Tree[v * 2][i])
        {
            Tree[v].push_back(Tree[v * 2 + 1][j++]);
        }
        Tree[v].push_back(Tree[v * 2][i]);
    }
    while(j < sz(Tree[v * 2 + 1]))
    {
        Tree[v].push_back(Tree[v * 2 + 1][j++]);
    }
    int it1 = 0, it2 = 0;
    for(int i = 0;i < sz(Tree[v]); i++)
    {
        while(it1 < sz(Tree[v * 2]) && Tree[v * 2][it1] <= Tree[v][i])
        {
            it1++;
        }
        while(it2 < sz(Tree[v * 2 + 1]) && Tree[v * 2 + 1][it2] <= Tree[v][i])
        {
            it2++;
        }
        it_left[v][i]= it1;
        it_right[v][i] = it2;
    }
}
bool get(int v, int l, int r, int al, int ar, int xl, int xr)
{
    if(xr == -1 || l > ar || r < al)
    {
        return 0;
    }
    if(l >= al && r <= ar)
    {
        if(Tree[v][xr] >= xl)
        {
            return 1;
        }
        return 0;
    }
    return get(v * 2, l, (r + l) / 2, al, ar, xl, it_left[v][xr] - 1) | get(v * 2 + 1, (r + l) / 2 + 1, r, al, ar, xl, it_right[v][xr] - 1);
}
signed main() {
 //   ios_base::sync_with_stdio(0);
   // cin.tie(0);
   // cout.tie(0);
    cin >> s;
    char t = 'a' - 1;
    s += t;
    n = sz(s);
    build();
    build_tree(1, 0, n - 1);
    int q;
    cin >> q;
    while(q--)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        string ask;
        cin >> ask;
        int anslen = -1;
        char anschar;
        int L1 = 1, R1 = n - 1;
        for(int i = 0; i < sz(ask); i++)
        {
            if(L1 > R1 || i + 1 > r - l + 1)
            {
                break;
            }
            int u = ask[i] - 'a';
            for(int j = u + 1; j < 26; j++)
            {
                int l1 = L1 - 1, r1 = R1 + 1;
                char u_ch = 'a' + j;
                while(r1 - l1 > 1)
                {
                    int midd = (r1 + l1) / 2;
                    if(s[idx[midd] + i] < u_ch)
                    {
                        l1 = midd;
                    }
                    else
                    {
                        r1 = midd;
                    }
                }
                int l2 = L1 - 1, r2 = R1 + 1;
                while(r2 - l2 > 1)
                {
                    int midd = (l2 + r2) / 2;
                    if(s[idx[midd] + i] > u_ch)
                    {
                        r2 = midd;
                    }
                    else
                    {
                        l2 = midd;
                    }
                }
                if(l2 >= r1 && get(1, 0, n - 1, r1, l2, l, r - i))
                {
                    anslen = i;
                    anschar = u_ch;
                    break;
                }
            }
            int l1 = L1 - 1, r1 = R1 + 1;
            while(r1 - l1 > 1)
            {
                int midd = (l1 + r1) / 2;
                if(s[idx[midd] + i] < ask[i])
                {
                    l1 = midd;
                }
                else
                {
                    r1 = midd;
                }
            }
            int l2 = L1 - 1,r2 = R1 + 1;
            while(r2 - l2 > 1)
            {
                int midd = (l2 + r2) / 2;
                if(s[idx[midd] + i] > ask[i])
                {
                    r2 = midd;
                }
                else
                {
                    l2 = midd;
                }
            }
            L1 = r1;
            R1 = l2;
            if(L1 <= R1 && s[idx[L1] + i + 1] == t)
            {
                L1++;
            }
        }
      //  cout << L1 << " " << R1 << "\n";
        if(L1 <= R1 && sz(ask) + 1 <= r - l + 1)
        {
            for(int j = 0; j < 26; j++)
            {
                int l1 = L1 - 1, r1 = R1 + 1;
                char u_ch = 'a' + j;
                while(r1 - l1 > 1)
                {
                    int midd = (r1 + l1) / 2;
                    if(s[idx[midd] + sz(ask)] < u_ch)
                    {
                        l1 = midd;
                    }
                    else
                    {
                        r1 = midd;
                    }
                }
                int l2 = L1 - 1, r2 = R1 + 1;
                while(r2 - l2 > 1)
                {
                    int midd = (l2 + r2) / 2;
                    if(s[idx[midd] + sz(ask)] > u_ch)
                    {
                        r2 = midd;
                    }
                    else
                    {
                        l2 = midd;
                    }
                }
                if(l2 >= r1 && get(1, 0, n - 1, r1, l2, l, r - sz(ask)))
                {
                    anslen = sz(ask);
                    anschar = u_ch;
                    break;
                }
            }
        }
        if(anslen == -1)
        {
            cout << -1 << "\n";
        }
        else
        {
            for(int i = 0; i < anslen; i++)
            {
                cout << ask[i];
            }
            cout << anschar << "\n";
        }
    }
    return 0;
}