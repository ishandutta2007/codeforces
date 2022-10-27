
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int dsu[N];
int rang[N];
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
bool connected(int a, int b)
{
    return pred(a) == pred(b);
}
bool used[N];
int color;
int t;
int p[N];
vector <int> colors[N];
void dfs(int v)
{
    used[v] = 1;
    colors[t].push_back(v);
    if(!used[p[v]])
    {
        dfs(p[v]);
    }
}
signed main() {
  //  ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //cout.tie(NULL);
    int n, s;
    cin >> n >> s;
    for(int i = 0; i < n; i++)
    {
        dsu[i] = i;
        rang[i] = 1;
    }
    vector <int> a(n);
    vector <pair <int, int> > b;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        b.push_back({a[i], i});
    }
    vector <int> ind(n);
    sort(b.begin(), b.end());
    for(int i = 0; i < n; i++)
    {
        p[b[i].second] = i;
    }
    for(int i = 0; i < n; i++)
    {
        if(a[i] == b[i].first && p[i] != i)
        {
            p[b[i].second] = p[i];
            b[p[i]].second = b[i].second;
            p[i] = i;
            b[i].second = i;
        }
    }
    for(int i = 0; i < n; i++)
    {
        unite(p[i], i);
    }
    int it = -1;
    for(int i = 0; i < n; i++)
    {
        if(p[b[i].second] == b[i].second)
        {
            continue;
        }
        if(it >= 0 && a[it] == a[b[i].second])
        {
            int x = it;
            int y = b[i].second;
            if(!connected(x, y))
            {
                unite(x, y);
                swap(p[x], p[y]);
            }
        }
        it = b[i].second;
    }
    t = 0;
    for(int i = 0; i < n; i++)
    {
        if(!used[i] && p[i] != i)
        {
            dfs(i);
            t++;
        }
    }
    int cnt =0;
    for(int i = 0; i < t; i++)
    {
        cnt += colors[i].size();
    }
    if(cnt > s)
    {
        cout << -1;
        return 0;
    }
    s -= cnt;
    s = min(s, t);
    if(s <= 1)
    {
        cout << t << "\n";
        for(int i = 0; i < t; i++)
        {
            cout << colors[i].size() << "\n";
            for(int j = 0; j < colors[i].size(); j++)
            {
                cout << colors[i][j] + 1 << " ";
            }
            cout << "\n";
        }
        return 0;
    }
    cout << (t - s + 2) << "\n";
    for(int i = 0; i < t - s; i++)
    {
        cout << colors[i + s].size() <<"\n";
        for(int j = 0; j < colors[i + s].size(); j++)
        {
            cout << colors[i + s][j] + 1 << " ";
        }
        cout << "\n";
        cnt -= colors[i + s].size();
    }
    cout << cnt << "\n";
    for(int i = 0; i < s; i++)
    {
        for(int j = 0; j < colors[i].size(); j++)
        {
            cout << colors[i][j] + 1 << " ";
        }
    }
    cout << "\n";
    cout << s << "\n";
    for(int i = s - 1; i >= 0; i--)
    {
        cout << colors[i][0] + 1 << " ";
    }
    return 0;
}