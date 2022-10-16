#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100010;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<int> degree(n + 1);

    for (int i = 0; i < n - 1; ++i){
        int u, v; cin >> u >> v;
        degree[u]++;
        degree[v]++;
    }

    int64 ans = 0;

    for (int i = 1; i <= n; ++i){
        ans += 1LL * degree[i] * (degree[i] - 1) / 2;
    }

    cout << ans << endl;

    return 0;
}