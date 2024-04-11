#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define F first
#define S second

const int N = 200 * 1000 + 10;
const int K = 6;

int n, k;
vector<int> g[N];
ll res = 0;

struct Data {
    ll sum_at[K];
    ll cnt_at[K];

    Data() {
        fill(sum_at, sum_at + K, 0);
        fill(cnt_at, cnt_at + K, 0);
    }

    Data shift() const {
        Data new_data;
        for (int i = 0; i < k; i++) {
            new_data.sum_at[i] = sum_at[(i - 1 + k) % k];
            new_data.cnt_at[i] = cnt_at[(i - 1 + k) % k];
        }
        if (k > 1)
            new_data.sum_at[1] += new_data.cnt_at[1];
        else
            new_data.sum_at[0] += new_data.cnt_at[0];
        return new_data;
    }

    void unite(Data rhs) {
        rhs = rhs.shift();
        //print();
        //rhs.print();
        for (int m1 = 0; m1 < k; m1++)
            for (int m2 = 0; m2 < k; m2++) {
                res += sum_at[m1] * rhs.cnt_at[m2] + cnt_at[m1] * rhs.sum_at[m2];
                if (k > 1 && m1 && m2 && m1 + m2 <= k)
                    res -= cnt_at[m1] * rhs.cnt_at[m2];
            }
        for (int i = 0; i < k; i++) {
            sum_at[i] += rhs.sum_at[i];
            cnt_at[i] += rhs.cnt_at[i];
        }
    }

    void print() {
        for (int i = 0; i < k; i++)
            cerr << cnt_at[i] << " " << sum_at[i] << endl;
        cerr << endl;
    }
};

Data dfs(int v, int par) {
    Data res;
    res.cnt_at[0]++;
    for (int to : g[v])
        if (to != par) {
            res.unite(dfs(to, v));
            //res.print();
        }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0, 0);
    cout << res << endl;
}