#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

const int Maxn = 200005;

int n, s;
int cnt[Maxn];
bool taken[Maxn];
priority_queue <pair <int, int> > Q;
vector <pair <int, int> > res;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin >> n >> s;
    for (int i = 1; i <= n; i++) {
        cin >> cnt[i];
        Q.push(make_pair(cnt[i], i));
    }
    int val;
    while (!Q.empty()) {
          val = Q.top().first;
          int v = Q.top().second; Q.pop();
          if (taken[v] || cnt[v] != val) continue;
          taken[v] = true;
          queue <int> tmp;
          while (val && !Q.empty()) {
                int uval = Q.top().first, u = Q.top().second; Q.pop();
                if (taken[u] || cnt[u] != uval) continue;
                if (!uval) break;
                res.push_back(make_pair(v, u));
                cnt[u]--;
                tmp.push(u);
                val--;
          }
          if (val) break;
          while (tmp.size()) {
                int u = tmp.front();
                Q.push(make_pair(cnt[u], u));
                tmp.pop();
          }
    }
    if (!val) {
          cout << "Yes\n";
          cout << res.size() << endl;
          for (int i = 0; i < res.size(); i++)
              cout << res[i].first << " " << res[i].second << endl;
    } else cout << "No\n";
    return 0;
}