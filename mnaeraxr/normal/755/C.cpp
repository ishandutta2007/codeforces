#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100010;

int ds[maxn];

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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    int total = n;

    memset(ds, -1, sizeof ds);

    for (int i = 1; i <= n; ++i){
        int v; cin >> v;

        if (join(v, i)){
            total--;
        }
    }

    cout << total << endl;

    return 0;
}