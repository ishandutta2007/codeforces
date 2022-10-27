#include<bits/stdc++.h>
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long
using namespace std;
const int N = 1e6 + 100;
int val[N];
const int M =  2e5;
int dsu[M], rang[M];
int p[N];
int pred(int a)
{
    if(a == dsu[a]) return a;
    return dsu[a] = pred(dsu[a]);
}
void unite(int a, int b)
{
    a = pred(a);
    b = pred(b);
    if(a == b)
    {
        return;
    }
    if(rang[a] > rang[b])
    {
        swap(a, b);
    }
    dsu[a] = b;
    rang[b] += rang[a];
}
int idx[N];
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    fill(idx, idx + N, -1);
    fill(val, val + N, -1);
    vector <int> a(n);
    for(int i = 0; i < n; i++)
    {
        dsu[i] = i;
        rang[i] = 1;
        cin >> a[i];
        val[a[i]] = i;
    }
    fill(p, p + N, -1);
    for(int i = 2; i < N; i++)
    {
        if(p[i] != -1)
        {
            continue;
        }
        for(int j = i; j < N; j += i)
        {
            p[j] = i;
        }
    }
    for(int i = 2; i < N; i++)
    {  
        int lst = -1;
        for(int j = i; j < N; j += i)
        {
            if(val[j] != -1)
            {
                if(lst != -1)
                {
                    unite(lst, val[j]);
                }
                lst = val[j];
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        int s = a[i];
        while(s != 1)
        {
            int pt = p[s];
            s /= pt;
            assert(idx[pt] == -1 || idx[pt] == pred(i));
            idx[pt] = pred(i);
        }
    }
    map <pair <int, int>, int> mp;
    for(int i = 0; i < n; i++)
    {
        int s = a[i] + 1;
        int k1 = pred(i);
     //   cout << k1 << "\n";
        vector <int> v;
        while(s != 1)
        {
            int pt = p[s];
            int k2 = idx[pt];
            v.push_back(k2);
       //     cout << pt << " " << idx[pt] << "\n";
            mp[{k1, k2}] = mp[{k2, k1}] = 1;
            s /= pt;
        }
        for(auto x1 : v)
        {
            for(auto x2 : v)
            {
                mp[{x1, x2}] = 1;
            }
        }
    }

    vector <int> ans(q, 2);
    for(int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        a = pred(a);
        b = pred(b);
        if(a == b)
        {
            cout << 0 << "\n";
        }
        else if(mp[{a, b}])
        {
            cout << 1 << "\n";
        }
        else
        {
            cout << 2 << "\n";
        }
    }
    return 0;
}