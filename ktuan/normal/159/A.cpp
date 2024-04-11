#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
using namespace std;

#define Rep(i,n) for(int i=0;i<(n);++i)
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Fit(i,v) for(typeof(v.begin()) i=v.begin();i!=v.end();++i)

int main() {
  int n, d;
  cin >> n >> d;
  vector<pair<int, pair<string, string> > > vv;
  map<pair<string, string>, int> ma;
  set<pair<string, string> > se;
  Rep(i, n) {
    int t;
    string u, v;
    cin >> u >> v >> t;
    vv.push_back(make_pair(t, make_pair(u, v)));
  }
  for (int i = 0; i < vv.size(); ++i) {
    int j = i;
    while (j < vv.size() && vv[j].first == vv[i].first) ++j;
    For (k, i, j - 1) {
      int t = vv[k].first;
      string u = vv[k].second.first;
      string v = vv[k].second.second;
      if (ma.count(make_pair(v, u))) {
        int r = ma[make_pair(v, u)];
        if (abs(t - r) <= d) {
          se.insert(make_pair(u, v));
          se.insert(make_pair(v, u));
        }
      }
    }
    For (k, i, j - 1) {
      int t = vv[k].first;
      string u = vv[k].second.first;
      string v = vv[k].second.second;
      ma[make_pair(u, v)] = t;
    }
    i = j - 1;
  }
  cout << se.size() / 2 << endl;
  Fit(i, se) {
    pair<string, string> p = *i;
    if (p.first < p.second) cout << p.first << " " << p.second << endl;
  }
  return 0;
}