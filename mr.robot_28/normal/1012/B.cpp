
#include <bits/stdc++.h>
using namespace std;
//#define int long long
vector <int> dsu, rang;
int pred(int a)
{
    if(a == dsu[a]) return a;
    return dsu[a] = pred(dsu[a]);
}
void unite(int a, int b)
{
    a = pred(a);
    b = pred(b);
    if(a != b)
    {
        if(rang[a] < rang[b])
        {
            swap(a, b);
        }
        dsu[b] = a;
        rang[a] += rang[b];
    }
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, q;
    cin >> n >> m >> q;
    dsu.resize(q);
    rang.resize(q);
    for(int i = 0; i < q; i++)
    {
        dsu[i] = i;
        rang[i] = 1;
    }
    vector <int> used1(n), used2(m);
    int cnt1 = 0;
    int cnt2 = 0;
    vector <pair <int, int> > x;
    int fl = 0;
    vector <int> index1(n, -1), index2(m, -1);
    for(int i = 0; i < q; i++)
    {
        int r, c;
        cin >> r >> c;
        c--;
        r--;
        if(used1[r] == 0 && used2[c] == 0)
        {
            x.push_back({r, c});
        }
        else
        {
            fl = 1;
        }
        if(index1[r] != -1)
        {
            unite(index1[r], i);
        }
        if(index2[c] != -1)
        {
            unite(index2[c], i);
        }
        index1[r] = i;
        index2[c] = i;
        used1[r]++;
        used2[c]++;
    }
    int comp = 0;
    for(int i = 0; i < n; i++)
    {
        if(!used1[i])
        {
            cnt1++;
        }
    }
    for(int i = 0; i < m; i++)
    {
        if(!used2[i])
        {
            cnt1++;
        }
    }
    set <int> s;
    for(int i = 0; i < q; i++)
    {
        int a = pred(i);
        s.insert(a);
    }
    comp = s.size();
    cout << cnt1 + comp - 1;
    return 0;
}