#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define pb push_back
#define dbg(x) cerr << #x << " " << x << "\n"
const int N = 2e4, M = 1e5;
int x[1 + M], y[1 + M], d[1 + M];
int n, m;

vector <int> gr[1 + N];
int gagic[1 + N], pereche[1 + N];

bool viz[1 + N];


bool bkt_opt (int baiat) {
  if (viz[baiat] == true)
    return false;
  viz[baiat] = true;
  for (auto fata : gr[baiat])
    if (gagic[fata] == false || bkt_opt (gagic[fata]) == true) {
      pereche[baiat] = fata;
      gagic[fata] = baiat;
      return true;
    }
  return false;
}

bool check (int dMax) {
    for (int i = 1; i <= n; i++)
        gr[i].clear (), gagic[i] = 0, pereche[i] = 0;
    for (int i = 1; i <= m; i++)
        if (d[i] <= dMax)
            gr[x[i]].pb (y[i]);
    int nr;
    do {
        memset (viz, false, sizeof (viz));
        nr = 0;
        for (int i = 1; i <= n; i++)
            if (pereche[i] == 0)
                nr += bkt_opt (i);
    } while (nr);
    nr = 0;
    for (int i = 1; i <= n; i++)
        if (pereche[i])
            nr++;
    return (nr == n);
}
int main () {
    ios::sync_with_stdio (false);
    cin.tie (0); cout.tie (0);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> x[i] >> y[i] >> d[i];
    }
    const int INF = 1e9;
    int lb = 0, rb = INF;
    int best = -1;
    while (lb <= rb) {
        int mid = (lb + rb) / 2;
        if (check (mid))
            rb = mid - 1, best = mid;
        else
            lb = mid + 1;
    }
    cout << best << "\n";
    return 0;
}