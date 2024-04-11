#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100111, inf = 1000111222;

pair<int, int> m[max_n];
vector<vector<int> > ans;
int p[max_n];
bool vis[max_n];

int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> m[i].F;
        m[i].S = i;
    }
    sort(m, m + n);
    for (int i = 0; i < n; ++i) {
        p[m[i].S] = i;
    }

    for (int i = 0; i < n; ++i) {
        if (vis[i]) continue;
        int start = i;
        int cur = p[i];
        vector<int> v;
        v.PB(start + 1);
        while (cur != start) {
            vis[cur] = 1;
            v.PB(cur + 1);
            cur = p[cur];
        }
        ans.PB(v);
    }

    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i].size() << ' ';
        for (int j = 0; j < ans[i].size(); ++j) {
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}