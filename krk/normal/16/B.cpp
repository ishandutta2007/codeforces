#include <iostream>
#include <algorithm>
using namespace std;

const int Maxm = 20;

int n, m, ans;
pair <int, int> cont[Maxm];

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
       cin >> cont[i].second >> cont[i].first;
    sort(cont, cont + m);
    for (int i = m - 1; i >= 0 && n; i--) {
        ans += min(n, cont[i].second) * cont[i].first;
        n -= min(n, cont[i].second);
    }
    cout << ans << endl;
    return 0;
}