#include<bits/stdc++.h>
#define X first
#define Y second
#define ll long long
#define sz(a) (int)a.size()
using namespace std;
const int maxn = 2e5 + 100;
const int mod = 1e9 + 7;
int Tree[4 * maxn];
int upd[4 * maxn];
string s[maxn];
int n;
void push(int v)
{
    Tree[v * 2] += upd[v];
    upd[v * 2] += upd[v];
    Tree[v * 2 + 1] += upd[v];
    upd[v * 2 + 1] += upd[v];
    upd[v] = 0;
}
void update(int v, int l, int r, int al, int ar, int x)
{
    if(al > ar)
    {
        return;
    }
    if(l >= al && r <= ar)
    {
        Tree[v] += x;
        upd[v] += x;
    }
    else if(l <= ar && r >= al)
    {
        push(v);
        update(v * 2, l, (r + l)/ 2, al, ar, x);
        update(v * 2 + 1, (r + l) / 2 + 1, r, al, ar, x);
        Tree[v] = min(Tree[v * 2], Tree[v * 2 + 1]);
    }
}
int go_to(int v, int l, int r)
{
    if(l == r)
    {
        return l;
    }
    push(v);
    if(Tree[v * 2 + 1] == 0)
    {
        return go_to(v * 2 + 1, (r + l) / 2 + 1, r);
    }
    return go_to(v * 2, l, (r + l) / 2);
}
void funct()
{
    if(Tree[1] == 1)
    {
        cout << "blue\n";
    }
    else
    {
        int i = go_to(1, 0, n - 1);
        cout << s[i] << "\n";
    }
}
signed main()
{
   // ifstream cin("rt.txt.txt");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    set <int> s1, s2;
    bool fl = 0;
    fill(Tree, Tree + 4 * maxn, 0);
    fill(upd, upd + 4 * maxn, 0);
    for(int i = 0; i < n; i++)
    {
        cin >> s[i];
        if(s[i] == "lock")
        {
            fl = 1;
            update(1, 0, n - 1, i, i, 1);
            s1.insert(i);
        }
        else if(s[i] == "unlock")
        {
            fl = 0;
            s2.insert(i);
            update(1, 0, n - 1, i, i, 1);
        }
        else if(fl)
        {
            update(1, 0, n - 1, i, i, 1);
        }
    }
    s2.insert(n);
    int q;
    cin >> q;
    funct();
    while(q--)
    {
        int i;
        string a;
        cin >> i >> a;
        i--;
        if(s[i] == "lock")
        {
            s1.erase(i);
            auto it = s1.lower_bound(i);
            if(it == s1.begin())
            {
                int k = n - 1;
                if(it != s1.end())
                {
                    k = *it - 1;
                }
                it = s2.lower_bound(i);
                k = min(k, *it - 1);
                update(1, 0, n - 1, i, k, -1);
            }
            else
            {
                int k = n - 1;
                if(it != s1.end())
                {
                    k = *it - 1;
                }
                it--;
                auto it1 = s2.lower_bound(*it);
                if(*it1 < i)
                {
                    it = s2.lower_bound(i);
                    k = min(k, *it - 1);
                    update(1, 0, n - 1, i, k, -1);
                }
            }
        }
        else if(s[i] == "unlock")
        {
            s2.erase(i);
            auto it = s1.lower_bound(i);
            int k = n - 1;
            if(it != s1.end())
            {
                k = *it - 1;
            }
            if(it == s1.begin())
            {
                update(1, 0, n - 1, i, i, -1);
            }
            else
            {
                it--;
                auto it1 = s2.lower_bound(*it);
                if(*it1 > i)
                {
                    k = min(k, *it1 - 1);
                    update(1, 0, n - 1, i + 1, k, 1);
                }
                else
                {
                    update(1, 0, n - 1, i, i, -1);
                }
            }
        }
        if(a == "lock")
        {
            auto it = s1.lower_bound(i);
            int k = n - 1;
            if(it != s1.end())
            {
                k = *it - 1;
            }
            if(it == s1.begin())
            {
                auto it1 = s2.lower_bound(i);
                k = min(k, *it1 - 1);
                update(1, 0, n - 1, i, k, 1);
            }
            else
            {
                it--;
                auto it1 = s2.lower_bound(*it);
                if(*it1 < i)
                {
                    it = s2.lower_bound(i);
                    k = min(k, *it - 1);
                    update(1, 0, n - 1, i, k, 1);
                }
            }
            s1.insert(i);
        }
        else if(a == "unlock")
        {
            auto it = s1.lower_bound(i);
            int k = n - 1;
            if(it != s1.end())
            {
                k = *it - 1;
            }
            if(it == s1.begin())
            {
                update(1, 0, n - 1, i, i, 1);
            }
            else
            {
                it--;
                auto it1 = s2.lower_bound(*it);
                if(*it1 > i)
                {
                    k = min(k, *it1 - 1);
                    update(1, 0, n - 1, i + 1, k, -1);
                }
                else
                {
                    update(1, 0, n - 1, i, i, 1);
                }
            }
            s2.insert(i);
        }
        s[i] = a;
        funct();
    }
    return 0;
}