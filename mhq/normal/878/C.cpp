#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int n, k;
const int maxN = 5 * (int)1e4 + 10;
const int maxK = 12;
int s[maxN][maxK];
set < pair < int, int > > all_max[maxK];
set < pair < int, int > > all_min[maxK];
int num[2 * maxN];
int val_min[2 * maxN][maxK];
int val_max[2 * maxN][maxK];
int sz = 0;
void make_new(int v) {
    sz++;
    num[sz] = 1;
    for (int j = 1; j <= k; j++) {
        val_max[sz][j] = val_min[sz][j] = s[v][j];
        all_max[j].insert(make_pair(val_max[sz][j], sz));
        all_min[j].insert(make_pair(val_min[sz][j], sz));
    }
}
void unite(int a, int b) {
    for (int j = 1; j <= k; j++) {
        all_max[j].erase(make_pair(val_max[a][j], a));
        all_max[j].erase(make_pair(val_max[b][j], b));
        all_min[j].erase(make_pair(val_min[a][j], a));
        all_min[j].erase(make_pair(val_min[b][j], b));
        val_max[a][j] = max(val_max[a][j], val_max[b][j]);
        val_min[a][j] = min(val_min[a][j], val_min[b][j]);
        all_max[j].insert(make_pair(val_max[a][j], a));
        all_min[j].insert(make_pair(val_min[a][j], a));
    }
    num[a] += num[b];
}
void print() {
    auto it = --(all_max[1].end());
    int t = (it -> second);
    cout << num[t] << '\n';
}
bool cmp(int a, int b) {
    return val_min[a][1] < val_min[b][1];
}
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(239);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            cin >> s[i][j];
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            make_new(i);
            print();
            continue;
        }
        int mn_big = -1;
        int mx_small = -1;
        for (int j = 1; j <= k; j++) {
            int val = s[i][j];
            auto it1 = all_max[j].lower_bound(make_pair(val, -1));
            if (it1 != all_max[j].end()) {
                int num_comp = it1 -> second;
                if (mn_big != -1) {
                    if (cmp(num_comp, mn_big)) {
                        mn_big = num_comp;
                    }
                }
                else {
                    mn_big = num_comp;
                }
            }
            auto it2 = all_min[j].lower_bound(make_pair(val, -1));
            if (it2 != all_min[j].begin()) {
                --it2;
                int num_comp = it2 -> second;
                if (mx_small != -1) {
                    if (cmp(mx_small, num_comp)) {
                        mx_small = num_comp;
                    }
                }
                else {
                    mx_small = num_comp;
                }
            }
        }
      //  cout << mx_small << " " << mn_big << " " << i << endl;
        if ((mx_small == -1) || (mn_big == -1) || (cmp(mx_small, mn_big)))  {
            make_new(i);
        }
        else {
            vector < int > all_to_unite;
            auto it = all_min[1].lower_bound(make_pair(val_min[mn_big][1], mn_big));
            while (true) {
                all_to_unite.push_back((it -> second));
                if ((it -> second) == mx_small) break;
                ++it;
            }
            make_new(i);
            for (int v : all_to_unite) {
                unite(sz, v);
            }
        }
        print();
    }
    return 0;
}