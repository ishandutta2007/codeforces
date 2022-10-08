
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 5e5 + 5;
int n, l[N], r[N], arr[2 * N], nxt[2 * N], prv[2 * N], dsu[N];

int trace(int x) {
    return dsu[x] < 0 ? x : dsu[x] = trace(dsu[x]);
}

void join(int x, int y) {
    if((x = trace(x)) == (y = trace(y))) return;
    if(dsu[x] > dsu[y]) swap(x, y);
    dsu[x] += dsu[y];
    dsu[y] = x;
}

void del(int x) {
    int a = prv[x], b = nxt[x];
    nxt[a] = b;
    prv[b] = a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    fill(dsu, dsu + n, -1);
    vector<pair<int, int>> v;
    for(int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i];
        arr[l[i]] = arr[r[i]] = i;
        v.emplace_back(r[i] - l[i], i);
    }
    for(int i = 0; i <= 2 * n + 1; i++) {
        nxt[i] = i + 1;
        prv[i] = i - 1;
    }
    sort(v.begin(), v.end());
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        int L = l[v[i].second], R = r[v[i].second];
        int p = L;
        while(nxt[p] < R) {
            p = nxt[p];
            if(trace(v[i].second) == trace(arr[p])) {
                cout << "NO" << endl;
                return 0;
            }else {
                join(v[i].second, arr[p]);
                cnt++;
            }
        }
        del(L);
        del(R);
    }
    cout << (cnt == n - 1 ? "YES" : "NO") << endl;
}