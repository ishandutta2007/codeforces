#include <iostream>
#include <cstdio>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n;
map <int, int> M;
priority_queue <pair <int, int> > Q;
vector <int> V[3];

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        M[tmp]++;
    }
    for (map <int, int>::iterator it = M.begin(); it != M.end(); it++)
        Q.push(make_pair(it->second, it->first));
    while (!Q.empty()) {
          vector <int> tk;
          for (int i = 0; i < 3 && !Q.empty(); i++) {
              int v = Q.top().second, cnt = Q.top().first; Q.pop();
              if (cnt == 0) break;
              if (M[v] != cnt) i--;
              else {
                   M[v]--;
                   tk.push_back(v);
              }
          }
          if (tk.size() < 3) break;
          sort(tk.begin(), tk.end());
          V[0].push_back(tk[2]); V[1].push_back(tk[1]); V[2].push_back(tk[0]);
          for (int i = 0; i < tk.size(); i++) Q.push(make_pair(M[tk[i]], tk[i]));
    }
    cout << V[0].size() << endl;
    for (int i = 0; i < V[0].size(); i++)
        cout << V[0][i] << " " << V[1][i] << " " << V[2][i] << endl;
    return 0;
}