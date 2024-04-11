#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 1010;

int ds[maxn];
bool cg[maxn];

int root(int a){
    return ds[a] < 0 ? a : ds[a] = root(ds[a]);
}

bool join(int a, int b){
    a = root(a), b = root(b);
    if (a == b) return false;
    if (ds[a] < ds[b]) swap(a, b);
    ds[b] += ds[a];
    ds[a] = b;
    return true;
}

int64 tri(int64 v){
    return v * (v - 1) / 2;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

#ifdef MARX
    freopen("test.in", "r", stdin);
#endif

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> gov(k);

    for (int i = 1; i <= n; ++i)
        ds[i] = -1;

    for (int i = 0; i < k; ++i)
        cin >> gov[i];

    for (int i = 0; i < m; ++i){
        int u, v; cin >> u >> v;
        join(u, v);
    }

    for (int i = 0; i < k; ++i)
        cg[ root(gov[i]) ] = true;

    int sum = 0;
    int ml = 0;
    vector<int> other;

    for (int i = 1; i <= n; ++i){
        if (root(i) != i) continue;

        if (cg[i]){
            other.push_back(-ds[i]);
            ml = max(ml, -ds[i]);
        }
        else sum -= ds[i];
    }

    int64 answer = 0;

    answer += tri(sum + ml);

    for (auto u : other)
        answer += tri(u);

    answer -= tri(ml);

    cout << answer - m << endl;


    return 0;
}