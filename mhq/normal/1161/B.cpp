#pragma optimize "-O3"
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, m;
const int maxN = (int)1e5 + 100;
vector < pair < int, int > > all;
void solve(int shift) {
    vector < pair < int, int > > nall;
    for (auto t : all) {
        int nx = (t.first + shift) % n;
        int ny = (t.second + shift) % n;
        if (nx > ny) swap(nx, ny);
        nall.emplace_back(nx, ny);
    }
    sort(nall.begin(), nall.end());
    for (int i = 0; i < nall.size(); i++) {
        if (all[i] != nall[i]) return ;
    }
    cout << "Yes";
    exit(0);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    int copn = n;
    vector < int > pr;
    for (int i = 2; i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) {
                n /= i;
            }
            pr.push_back(i);
        }
    }
    assert(n == 1);
    n = copn;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if (a > b) swap(a, b);
        all.emplace_back(a, b);
    }
    sort(all.begin(), all.end());
    for (int v : pr) {
        solve(n / v);
    }
    cout << "No";
    return 0;
}