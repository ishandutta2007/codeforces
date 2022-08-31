#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 111, inf = 1000111222;

multiset<int> v[max_n];
int ans[max_n][max_n];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        multiset<pair<int, int>> ms;
        for (int i = 0; i < n; ++i) {
            v[i].clear();
            for (int j = 0; j < m; ++j) {
                int a;
                cin >> a;
                v[i].insert(a);
                ms.insert(MP(a, i));
            }
            //sort(v[i].begin(), v[i].end());
        }
        for (int i = 0; i < m; ++i) {
            int res = ms.begin()->first;
            int pos = ms.begin()->second;
            for (int j = 0; j < n; ++j) {
                if (j == pos) {
                    ans[i][j] = res;
                } else {
                    ans[i][j] = *(--v[j].end());
                }
                v[j].erase(v[j].find(ans[i][j]));
                ms.erase(ms.find(MP(ans[i][j], j)));
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << ans[j][i] << ' ';
            }
            cout << "\n";
        }
    }

    return 0;
}