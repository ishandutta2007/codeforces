#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 100 * 1000;

vector<int> g[N];
bool was[N];
set<int> capitals;
bool cap;
int size;

void dfs(int v) {
    was[v] = true;
    if (capitals.count(v))
        cap = true;
    size++;
    for (int to : g[v])
        if (!was[to]) 
            dfs(to);
}

int func(int n) {
    return n * (n - 1) / 2;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        x--;
        capitals.insert(x);
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
        g[b].push_back(a);    
    }
    vector<int> sizes;
    int other = 0;
    for (int i = 0; i < n; i++)
        if (!was[i]) {
            cap = false;
            size = 0;
            dfs(i);
            if (cap)
                sizes.push_back(size);
            else
                other += size;
        }
    sort(sizes.begin(), sizes.end());
    sizes.back() += other;
    int res = -m;
    for (int x : sizes)
        res += func(x);
    cout << res << endl;       
}