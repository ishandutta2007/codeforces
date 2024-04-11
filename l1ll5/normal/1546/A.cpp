#include<bits/stdc++.h>
using namespace std;
const int N = 10000 + 5;
int a[N], b[N];
vector<pair<int, int> > ans;
void sp(int i, int j) {
    a[i] --;
    a[j] ++;
    ans.push_back(make_pair(i, j));
}
int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int n;
        ans.clear();
        cin >> n;
        int sum1 = 0, sum2 = 0;
        queue<int> v1, v2;
        for (int i = 1; i <= n; i += 1)
            cin >> a[i], sum1 += a[i];
        for (int i = 1; i <= n; i += 1)
            cin >> b[i], sum2 += b[i];
        if (sum1 != sum2) {
            cout << "-1\n";
            continue;
        }
        for (int i = 1; i <= n; i += 1) {
            if (a[i] > b[i]) v1.push(i);
            if (a[i] < b[i]) v2.push(i);
        }

        while (!v1.empty()) {
            int x = v1.front();
            while (a[x] > b[x]) {
                int y = v2.front();
                sp(x, y);
                if (a[y] == b[y]) v2.pop();
            }
            v1.pop();
        }
        cout << ans.size() << '\n';
        for (auto x : ans) {
            cout << x.first << ' ' << x.second << '\n';
        }
        for (int i = 1; i <= n; i += 1)
            assert(a[i] == b[i]);
    }
}