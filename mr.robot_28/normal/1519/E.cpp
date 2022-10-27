#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define int long long
#define sz(a) (int)a.size()
#define int long long
const int N = 5e5;
vector <pair <int, int> > g[N];
vector <pair <int, int> > ans;
int used[N];
bool dfs(int v, int p)
{
    used[v] = 1;
    vector <int> t2;
    for(auto to : g[v])
    {
        if(used[to.X] == 0)
        {
            if(used[to.X] == 0 && dfs(to.X, to.Y))
        {
            t2.push_back(to.Y);
        }
        }
        else if(used[to.X] == 2)
        {
            t2.push_back(to.Y);
        }
    }
    while(sz(t2) > 1)
    {
        ans.push_back({t2.back(), t2[sz(t2) - 2]});
        t2.pop_back();
        t2.pop_back();
    }
    used[v] = 2;
    if(p != -1 && sz(t2) != 0)
    {
        ans.push_back({t2.back(), p});
    }
    return (sz(t2) ==  0);
}
signed main()
{
  //  ifstream cin("input1.txt.4c");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector <pair <int, int> > vec;
    vector <vector <int> > ver(n);
    for(int i = 0; i < n; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int x1 = c * b;
        int y1 = d * (a + b);
        int t = __gcd(x1, y1);
        x1 /= t;
        y1 /= t;
      //  cout << x1 << " " << y1 << "\n";
        vec.push_back({x1, y1});
        int x2 = (c + d) * b;
        int y2 = d * a;
        t = __gcd(x2, y2);
        x2 /= t;
        y2 /= t;
        //cout << x2 << " " << y2 << "\n";
        vec.push_back({x2, y2});
        ver[i] = {x1, y1, x2, y2};
    }
    sort(vec.begin(), vec.end());
    vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
    for(int i = 0; i < n; i++)
    {
        int t1 = lower_bound(vec.begin(), vec.end(), make_pair(ver[i][0], ver[i][1])) - vec.begin();
        int t2 = lower_bound(vec.begin(), vec.end(), make_pair(ver[i][2], ver[i][3])) - vec.begin();
  //      cout << t1 << " " << t2 << " " << i << "\n";
        g[t1].push_back({t2, i});
        g[t2].push_back({t1, i});
    }
    for(int i = 0; i < sz(vec); i++)
    {
        if(!used[i])
        {
            dfs(i, -1);
        }
    }
    cout << sz(ans) << "\n";
    for(auto p : ans)
    {
        cout << p.X + 1 << " " << p.Y + 1 << "\n";
    }
    return 0;
}