#include<bits/stdc++.h>
#define X first
#define Y second
#define sz(a) (int)a.size()
using namespace std;
const int N = 3e5 + 100;
const int mod = 1e9 + 7;
int b[N];
int Tree[4 * N];
int Tree1[4 * N];
void upd1(int v, int l, int r, int al, int ar, int x)
{
    if(l >= al && r <= ar)
    {
        Tree[v] = min(Tree[v], x);
    }
    else if(l <= ar && r >= al)
    {
        upd1(v * 2, l, (r + l)  /2, al, ar, x);
        upd1(v * 2 + 1, (r + l) / 2 + 1, r, al, ar, x);
    }
}
int get1(int v, int l, int r, int x)
{
    if(l == r)
    {
        return Tree[v];
    }
    int m = (r + l) / 2;
    if(x <= m)
    {
        return min(Tree[v], get1(v * 2, l, (r + l) / 2, x));
    }
    return min(Tree[v], get1(v * 2 + 1, m + 1, r, x));
}
void upd2(int v, int l, int r, int x, int val)
{
    if(l == r)
    {
        Tree1[v] = val;
        return;
    }
    int m = (r + l )/ 2;
    if(x <= m)
    {
        upd2(v * 2, l, m, x, val);
    }
    else
    {
        upd2(v * 2 + 1, m + 1, r, x, val);
    }
    Tree1[v] = max(Tree1[v * 2], Tree1[v * 2 + 1]);
}
int get2(int v, int l, int r, int al, int ar)
{
    if(l >= al && r <= ar)
    {
        return Tree1[v];
    }
    if(l <= ar && r >= al)
    {
        return max(get2(v * 2, l, (r + l) / 2, al, ar), get2(v * 2 + 1, (r + l) /2 + 1, r, al, ar));
    }
    return 0;
}
signed main() {
 //   ios_base::sync_with_stdio(0);
   // cin.tie(0);
   // cout.tie(0);
    fill(Tree, Tree + 4 * N, 1e9 + 1);
    fill(Tree1, Tree1 + 4 * N, 0);
    int n, m;
    cin >> n >> m;
    map <int, int> mp;
    vector <bool> used1(m);
    vector <bool> used(n);
    vector <int> max_val(n);
    for(int i = 0; i < m; i++)
    {
        int t;
        cin >> t;
        if(t == 1)
        {
            int l, r, x;
            cin >> l >> r >> x;
            l--;
            r--;
            if(get2(1, 0, n - 1, l, r) > x)
            {
                cout << "NO";
                return 0;
            }
            if(get2(1, 0, n - 1, l, r) != x)
            {
                mp[x] = i;
            }
            else
            {
                used1[i] = 1;
            }
            upd1(1, 0, n - 1, l, r, x);
        }
        else {
            used1[i] = 1;
            int k, d;
            cin >> k>> d;
            k--;
            if(!used[k])
            {
                max_val[k] = get1(1, 0, n - 1, k);
            }
            used[k] = 1;
            upd2(1, 0, n - 1, k, d);
        }
    }
    vector <bool> bit(30);
    vector <pair <int, int> > vec;
    for(int i = 0; i < n; i++)
    {
        if(!used[i])
        {
            max_val[i] = get1(1, 0, n -1 , i);
        }
        if(mp.count(max_val[i]) && !used1[mp[max_val[i]]])
        {
            for(int j = 0; j < 30; j++)
            {
                if((1 << j) & max_val[i])
                {
                    bit[j] = 1;
                }
            }
            b[i] = max_val[i];
            used1[mp[max_val[i]]] = 1;
        }
        else
        {
            vec.push_back({max_val[i], i});
        }
    }
    for(int i = 0; i < m; i++)
    {
        if(!used1[i])
        {
            cout << "NO";
            return 0;
        }
    }
    sort(vec.begin(), vec.end());
    reverse(vec.begin(), vec.end());
    vector <int> cnt(30);
    for(auto p : vec)
    {
        int x = p.X;
        x = min(x, (int)1e9);
        for(int j = 0; j < 30; j++)
        {
            if((1 << j) & x)
            {
                cnt[j]++;
            }
        }
    }
    for(auto p : vec)
    {
        int idx = p.Y;
        int x = p.X;
        x = min(x, (int)1e9);
        for(int j = 29; j >= 0; j--)
        {
            if((1 << j) & x)
            {
                cnt[j]--;
            }
        }
        for(int j = 29; j >= 0; j--)
        {
            if(((1 << j) & x) && (bit[j] || cnt[j]))
            {
                j--;
                while(j >= 0)
                {
                    bit[j] = 1;
                    b[idx] += (1 << j);
                    j--;
                }
            }
            else if((1 << j) & x)
            {
                bit[j] = 1;
                b[idx] += (1 << j);
            }
        }
    }
    cout << "YES\n";
    for(int i = 0; i < n; i++)
    {
        cout << b[i] << " ";
    }
    return 0;
}