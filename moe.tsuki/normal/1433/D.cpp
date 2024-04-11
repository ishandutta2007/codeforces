#include<bits/stdc++.h>
using namespace std;
#define F(i,n) for (int i = 0; i < n; ++i)
#define F1(i,n) for (int i = 1; i <= n; ++i)
#define int long long
const int maxn = 5678;
int a[maxn];
//vector<int> v[maxn];
//map<int, vector<int> > app;
main()
{
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while (t --> 0)
  {
    int n; cin >> n;
    F1 (i, n) cin >> a[i];
    vector<pair<int, int> > fu;
    F1 (i, n) fu.push_back(make_pair(a[i], i));
    sort(fu.begin(), fu.end());
    int last = fu[0].first, con = 0, mn = 1234567, pos = -1;
    fu.push_back(make_pair(12345678913456ll, 0));
    F (i, n + 1)
    {
      if (fu[i].first == last)
      {
        ++con;
      } else
      {
        if (mn > con) mn = con, pos = i - 1;
        con = 1;
      }
      last = fu[i].first;
    }
    vector<int> vv, dv;
    for (auto x : fu) 
      if (x.first == fu[pos].first)
        vv.push_back(x.second);
      else if (x.second) dv.push_back(x.second);
    if (dv.size()== 0) { cout << "NO\n"; continue; }
    cout << "YES\n";
    /*if (app.size() == 1) { cout << "NO\n"; continue; }
    cout << "YES\n";
    int cur = 0;
    for (auto x : app) v[cur++] = x.second;
    vector<int> vv;
    int mn = 12345678, at = 0;
    F (i, app.size()) if (v[i].size() < mn) { mn = v[i].size(); at = i; }
    F (i, app.size()) if (i != at) for (auto x : app[i]) vv.push_back(x);
    cout << at << ' ' << app.size() << " at size\n";
    for (auto x : app) cout << x.first << '\n';
    cout << "stop\n";
    F (i, app.size())
    {
      for (auto x : app[i]) cout << x << ' ';
      cout << '\n';
    }
    for (auto x : vv)
      cout << x << ' ';
    cout << "vv\n";
    for (auto x : dv)
      cout << x << ' ';
    cout << "dv\n";*/
    F (i, vv.size() - 1)
    {
      cout << vv[i] << ' ' << dv[i] << '\n';
      cout << vv[i + 1] << ' ' << dv[i] << '\n';
    }
    for (int i = vv.size() - 1; i < dv.size(); ++i)
      cout << vv[0] << ' ' << dv[i] << '\n';
  }
}