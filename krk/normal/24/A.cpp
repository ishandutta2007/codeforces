#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxn = 101;

int n;
vector <pair <int, int> > neigh[Maxn];

int main()
{
    int a, b, c;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        neigh[a].push_back(make_pair(b, -c));
        neigh[b].push_back(make_pair(a, c));
    }
    int ans;
    for (int i = 0; i < 2; i++) {
        int v = 1, prev = neigh[1][i].first, sum = 0;
        if (neigh[1][i].second < 0) sum = -neigh[1][i].second;
        while (v != neigh[1][i].first) {
              int j = prev == neigh[v][0].first;
              if (neigh[v][j].second > 0) sum += neigh[v][j].second;
              prev = v; v = neigh[v][j].first;
        }
        if (i == 0) ans = sum;
        else ans = min(ans, sum);
    }
    cout << ans << endl;
    return 0;
}