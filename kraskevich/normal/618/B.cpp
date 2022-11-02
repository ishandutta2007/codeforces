#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> m(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> m[i][j];
    set<int> f;
    vector<int> res(n);
    for (int i = 0; i < n; i++)
        f.insert(i);
    for (int i = 0; i < n - 2; i++) {
        int v = -1;
        for (int pos : f) {
            int cnt = 0;
            for (int p2 : f)
                if(m[pos][p2] - 1 == i)
                    cnt++;
            if (cnt >= 2) {
                v = pos;
                break;
            }
        }
        assert (v >= 0);
        res[v] = i;
        f.erase(v);
    }
    res[*f.begin()] = n - 2;
    f.erase(f.begin());
    res[*f.begin()] = n - 1;
    for (int x : res)
        cout << x + 1 << " ";
    cout << endl;
}