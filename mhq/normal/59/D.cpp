#include <bits/stdc++.h>
using namespace std;
const int maxN = 3 * (int)1e5 + 10;
int n, k;
int r[maxN];
int a[maxN];
int b[maxN];
bool used[maxN];
vector < int > prv;
vector < int > aft;
vector < int > cur;
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("log.in", "r", stdin);
    //freopen("log.out", "w", stdout);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= 3 * n; i++) {
        cin >> a[i];
        r[a[i]] = i;
    }
    bool ok = false;
    for (int i = 0; i < n; i++) {
        cin >> b[3 * i] >> b[3 * i + 1] >> b[3 * i + 2];
    }
    cin >> k;
    for (int i = 0; i < n; i++) {
        int x, y, z;
        x = b[3 * i];
        y = b[3 * i + 1];
        z = b[3 * i + 2];
        //cin >> x >> y >> z;
        if (!ok) {
            if (r[x] > r[y]) swap(x, y);
            if (r[x] > r[z]) swap(x, z);
            if (y == k || z == k) {
                for (int j = 1; j <= 3 * n; j++) {
                    if (j == k) continue;
                    cout << j << " ";
                }
                return 0;
            }
            if (x == k) {
                cur.push_back(y);
                cur.push_back(z);
                ok = true;
            }
            else {
                prv.push_back(x);
                prv.push_back(y);
                prv.push_back(z);
            }
        }
        else {
            aft.push_back(x);
            aft.push_back(y);
            aft.push_back(z);
        }
    }
    sort(cur.begin(), cur.end());
    sort(prv.begin(), prv.end());
    sort(aft.begin(), aft.end());
    for (int i = 0; i < aft.size(); i++) cur.push_back(aft[i]);
    int ind = 0;
    int pos = 0;
    for (int i = 0; i < prv.size(); i++) {
        while (ind < cur.size() && cur[ind] < prv[i]) {
            cout << cur[ind] << " ";
            ind++;
        }
        cout << prv[i] << " ";
    }
    for (int i = ind; i < cur.size(); i++) cout << cur[i] << " ";
    return 0;
}