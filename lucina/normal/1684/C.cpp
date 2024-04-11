#include<bits/stdc++.h>
using namespace std;
int n, m;

void solve() {
    cin >> n >> m;
    vector <vector <int>> a(n, vector <int>(m));
    for (int i = 0 ; i < n ; ++ i)
    for (int j = 0 ; j < m ; ++ j)
        cin >> a[i][j];
    map <pair <int, int>, int> cnt;
    vector <int> unsorted;
    for (int i = 0 ; i < n ; ++ i) {
        unsorted.clear();
        for (int j = 0 ; j + 1 < m ; ++ j) {
            if (a[i][j] > a[i][j + 1]) unsorted.push_back(j);
        }
        if (unsorted.size() == 1) {
            int x = unsorted[0];
            int y = x + 1;
            while (y < m && a[i][x] > a[i][y]) y += 1;    
            pair <int, int> sw1 = make_pair(unsorted[0], y - 1);
            x = unsorted[0] + 1;
            y = x - 1;
            while (y >= 0 && a[i][x] < a[i][y]) y -= 1;
            pair <int, int> sw2 = make_pair(y + 1, x);
            {
                swap(a[i][sw1.first], a[i][sw1.second]);
                if (is_sorted(a[i].begin(), a[i].end())) cnt[sw1] += 1;
                swap(a[i][sw1.first], a[i][sw1.second]);
            }
            if (sw2 != sw1) 
            {
                sw1 = sw2;
                swap(a[i][sw1.first], a[i][sw1.second]);
                if (is_sorted(a[i].begin(), a[i].end())) cnt[sw1] += 1;
                swap(a[i][sw1.first], a[i][sw1.second]);
            }
        }
        if (unsorted.size() == 2) {
            cnt[make_pair(unsorted[0], unsorted[1] + 1)] += 1;
        }
    }    

    pair <int, int> sw = make_pair(0, 0);
    int mx = 0;
    for (auto &[i, j] : cnt) if (j > mx) mx = j, sw = i;
    for (int i = 0 ; i < n ; ++ i)
        swap(a[i][sw.first], a[i][sw.second]);
    
    for (int i = 0 ; i < n ; ++ i)
        if (!is_sorted(a[i].begin(), a[i].end())) return cout << "-1\n", void();
    cout << sw.first + 1 << ' ' << sw.second + 1 << '\n'; 
}

int main() {
    int T;
    for (cin >> T ; T -- ;) {
        solve();
    }
}