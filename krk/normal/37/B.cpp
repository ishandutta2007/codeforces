#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int Maxn = 1005;

int n, mx, reg;
pair <int, int> scroll[Maxn];
bool used[Maxn];
int health, dam, tim;
vector <pair <int, int> > us;

int main()
{
    cin >> n >> mx >> reg;
    for (int i = 0; i < n; i++) cin >> scroll[i].first >> scroll[i].second;
    health = mx;
    while (true) {
          health -= dam;
          health = min(health + reg, mx);
          if (health <= 0) break;
          int nw = -1;
          for (int i = 0; i < n; i++) if (!used[i])
             if (mx * scroll[i].first >= 100 * health &&
                 (nw == -1 || scroll[i].second > scroll[nw].second))
                nw = i;
          tim++;
          if (nw == -1 && reg >= dam) break;
          if (nw == -1) continue;
          used[nw] = true;
          dam += scroll[nw].second;
          us.push_back(make_pair(tim-1, nw+1));
    }
    if (health > 0) cout << "NO\n";
    else {
         cout << "YES\n";
         cout << tim << " " << us.size() << endl;
         for (int i = 0; i < us.size(); i++)
            cout << us[i].first << " " << us[i].second << endl;
    }
    return 0;
}