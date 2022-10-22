#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

const int inf = 1e9;
const ll inf64 = 1e18;

set<int> q;

int f(int x) {
    x++;
    while (x % 10 == 0) x /= 10;
    return x;
}

void dfs(int n) {
    if (q.count(n)) return;
    q.insert(n);
    dfs(f(n));
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    dfs(n);

    cout << (int)q.size() << "\n";

    return 0;
}