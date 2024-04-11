#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

vector<pii> ans;
int n;
vector<int> p, pos;

void do_swap(int i, int j) {
    int x = p[i];
    int y = p[j];
    swap(p[i], p[j]);
    swap(pos[x], pos[y]);
    ans.push_back({i, j});
}

void add_swap(int i, int j) {
    if (i == j) return;
    if (i > j) swap(i, j);
    if (j - i >= n / 2) {
        do_swap(i, j);
        return;
    }
    if (i >= n / 2) {
        do_swap(0, i);
        do_swap(0, j);
        do_swap(0, i);
    } else if (j < n / 2) {
        do_swap(j, n - 1);
        do_swap(i, n - 1);
        do_swap(j, n - 1);
    } else {
        do_swap(0, j);
        add_swap(0, i);
        do_swap(0, j);
    }
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    p.resize(n);
    pos.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
        pos[p[i]] = i;
    }

    ans.reserve(5 * n);

    for (int x = n - 1; x >= 0; x--) {
        add_swap(pos[x], x);
    }

    cout << (int)ans.size() << "\n";

    for (pii p : ans) {
        cout << p.first + 1 << " " << p.second + 1 << "\n";
    }

//    cout << "\n--\n";
//    for (int x : p) {
//        cout << x << " ";
//    }
//    cout << "\n";

    return 0;
}