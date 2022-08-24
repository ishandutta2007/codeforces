#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxN = (int)1e5 + 10;
int a[maxN];
int n;
vector < pair < int, int > > ans;
int cop[maxN];
bool solve_stupid(int n) {
    for (int i = 1; i <= n; i++) cop[i] = a[i];
    vector < pair < int, int > > all;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int k = 2 * j - i;
            if (k <= n) all.emplace_back(i, j);
        }
    }
    int m = all.size();
    random_shuffle(all.begin(), all.end());
    vector < pair < int, int > > nall;
    for (int i = 0; i < min(m, 22); i++) nall.push_back(all[i]);
    all = nall;
    m = all.size();
    for (int mask = 0; mask < (1 << m); mask++) {
        bool ok = true;
        for (int i = 1; i <= n; i++) {
            a[i] = cop[i];
        }
        for (int bit = 0; bit < m; bit++) {
            if (mask & (1 << bit)) {
                int x = all[bit].first;
                int y = all[bit].second;
                int z = 2 * y - x;
                a[x] ^= 1;
                a[y] ^= 1;
                a[z] ^= 1;
            }
        }
        for (int i = 1; i <= n; i++) {
            if (a[i] != 0) {
                ok = false;
                break;
            }
        }
        if (ok) {
            for (int bit = 0; bit < m; bit++) {
                if (mask & (1 << bit)) ans.push_back(all[bit]);
            }
            return true;
        }
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    srand(time(0));
       cin >> n;
       //n = (int)1e5;
       for (int i = 1; i <= n; i++) {
           cin >> a[i];
           //a[i] = rand() % 2;
       }
       while (n > 13) {
           vector<pair<int, int> > possible;
           possible.emplace_back(0, 0);
           for (int i = n; i >= n - 5; i--) {
               for (int j = i - 1; j >= n - 5; j--) {
                   int k = 2 * j - i;
                   if (k <= 0) continue;
                   possible.emplace_back(k, j);
               }
           }
           for (int i = n; i >= n - 5; i--) {
               int j = n - 6;
               int k = 2 * j - i;
               if (k >= 1) {
                   possible.emplace_back(k, j);
               }
           }
           bool ok = false;
           int willi = -1;
           int willj = -1;
           for (int i = n - 5; i <= n; i++) {
               cop[i] = a[i];
           }
           for (int i = 0; i < possible.size(); i++) {
               if (ok) break;
               for (int j = i; j < possible.size(); j++) {
                   for (int q = n - 5; q <= n; q++) a[q] = cop[q];
                   int x = possible[i].first;
                   int y = possible[i].second;
                   int z = 2 * y - x;
                   if (x >= n - 5) a[x] ^= 1;
                   if (y >= n - 5) a[y] ^= 1;
                   if (z >= n - 5) a[z] ^= 1;
                   int xx = possible[j].first;
                   int yy = possible[j].second;
                   int zz = 2 * yy - xx;
                   if (xx >= n - 5) a[xx] ^= 1;
                   if (yy >= n - 5) a[yy] ^= 1;
                   if (zz >= n - 5) a[zz] ^= 1;
                   if (a[n - 5] == 0 && a[n - 4] == 0 && a[n - 3] == 0 && a[n - 2] == 0 && a[n - 1] == 0 && a[n] == 0) {
                       ok = true;
                       willi = i;
                       willj = j;
                       break;
                   }
               }
           }
           assert(ok == true);
           int x = possible[willi].first;
           int y = possible[willi].second;
           int z = 2 * y - x;
           if (x >= 1) a[x] ^= 1;
           if (y >= 1) a[y] ^= 1;
           if (z >= 1) a[z] ^= 1;
           if (x != 0) ans.push_back(possible[willi]);
           int xx = possible[willj].first;
           int yy = possible[willj].second;
           int zz = 2 * yy - xx;
           if (xx >= 1) a[xx] ^= 1;
           if (yy >= 1) a[yy] ^= 1;
           if (zz >= 1) a[zz] ^= 1;
           if (xx != 0) ans.push_back(possible[willj]);
           n -= 6;
       }
       if (solve_stupid(n)) {
           cout << "YES" << '\n';
           cout << ans.size() << '\n';
           for (auto t : ans) {
               cout << t.first << " " << t.second << " " << 2 * t.second - t.first << '\n';
           }
       } else {
           cout << "NO" << '\n';
       }
       return 0;
}