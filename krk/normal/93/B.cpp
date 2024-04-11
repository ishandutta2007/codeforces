#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
using namespace std;

const int Maxn = 55;
const int Maxm = 55;
const double sm = 1e-9;

int n, w, m, np;
double need[Maxm];
double have[Maxn];
int tims[Maxn];
vector <pair <int, double> > res[Maxm];
bool ok = true;

int main()
{
    cin >> n >> w >> m;
    fill(need + 1, need + m + 1, double(n) / double(m));
    fill(have + 1, have + n + 1, 1.0);
    np = 1;
    for (int hp = 1; hp <= n && ok; hp++) {
        if (need[np] < sm) np++;
        double am = min(have[hp], need[np]);
        res[np].push_back(make_pair(hp, double(w) * am));
        need[np] -= am; have[hp] -= am;
        if (++tims[hp] > 2) ok = false;
        if (have[hp] >= sm) hp--;
    }
    if (ok) {
            cout << "YES\n";
            for (int i = 1; i <= m; i++)
               for (int j = 0; j < res[i].size(); j++) {
                   cout << res[i][j].first << " " << fixed << setprecision(10) << res[i][j].second;
                   if (j < res[i].size() - 1) cout << " ";
                   else cout << endl;
               }
    } else cout << "NO\n";
    return 0;
}