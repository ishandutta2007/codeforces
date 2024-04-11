#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxn = 500, Maxm = 500;

int n, m, x[Maxn], y[Maxn], seq[Maxm];

bool canGet(int from)
{
     bool taken[Maxm] = {};
     vector <int> ans;
     for (int i = 0; i < n; i++)
        if ((i - from) % 2) ans.push_back(-1);
        else {
             int prv = (i - 1 + n) % n;
             int nxt = (i + 1) % n;
             int need = 0;
             if (x[prv] == x[i]) need += abs(y[prv] - y[i]);
             else need += abs(x[prv] - x[i]);
             if (x[i] == x[nxt]) need += abs(y[i] - y[nxt]);
             else need += abs(x[i] - x[nxt]);
             int j;
             for (j = 0; j < m; j++) 
                if (!taken[j] && seq[j] == need) break;
             if (j == m) return false;
             ans.push_back(j+1);
             taken[j] = true;
        }
     cout << "YES\n";
     for (int i = 0; i < ans.size(); i++) {
         if (i) cout << " ";
         cout << ans[i];
     }
     cout << endl;
     return true;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
    for (int i = 0; i < m; i++) cin >> seq[i];
    if (!canGet(0)) if (!canGet(1)) cout << "NO\n";
    return 0;
}