#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;

int n;
int a[nax];
int ans;
int64_t sum1[35];
int64_t sum2[35];
void solve(vector <int> &f, int x) {
    if (f.empty() || x < 0) return;
    vector <int> l;
    vector <int> r;
    int64_t all1 = 0;
    int64_t all2 = 0;
    int cnt_one1 = 0;
    int cnt_one2 = 0;

    for (int i : f) {
        if (!(i >> x & 1)) all1 += cnt_one1, cnt_one2 += 1, l.push_back(i);
        else cnt_one1 += 1, all2 += cnt_one2, r.push_back(i);
    }
    sum1[x] += all1;
    sum2[x] += all2;
    vector<int>().swap(f);

    solve(l, x - 1);
    solve(r, x - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    vector <int> b(n);
    for (int i = 0 ; i < n ; ++ i)
        cin >> b[i];
    solve(b, 30);

    int64_t total_inv = 0;

    for (int j = 0 ; j < 30 ; ++ j) {
        int64_t inv1 = sum1[j];
        int64_t inv2 = sum2[j];
 
        total_inv += min(inv1, inv2);
        if (inv1 > inv2) ans |= 1 << j;
    }

    cout << total_inv << ' ' << ans << '\n';
//

}
/*
    Good Luck
        -Lucina
*/