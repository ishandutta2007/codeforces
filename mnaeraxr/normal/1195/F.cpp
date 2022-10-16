#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int64,int64> pii;
typedef vector<int> vi;

const double eps = 1e-9;
const int oo = 0x3f3f3f3f;
const int mod = 1000000007;
const int maxn = 100100;

int64 bit[maxn];

void update(int ix, int64 v){
    while (ix < maxn){
        bit[ix] += v;
        ix += ix & -ix;
    }
}

int64 sum(int ix){
    int64 answer = 0;

    while (ix){
        answer += bit[ix];
        ix -= ix & -ix;
    }

    return answer;
}

int64 gcd(int64 a, int64 b){
    while (b){
        int64 t = a % b;
        a = b;
        b = t;
    }

    return a;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    vector<vector<pii>> dirs(n);

    for (int i = 0; i < n; ++i){
        int m; cin >> m;

        vector<pii> a(m + 1);
        for (int j = 0; j < m; ++j){
            cin >> a[j].first >> a[j].second;
        }
        a[m] = a[0];

        for (int j = 0; j < m; ++j){
            int64 x = a[j + 1].first - a[j].first;
            int64 y = a[j + 1].second - a[j].second;

            int64 g = gcd(abs(x), abs(y));
            x /= g;
            y /= g;

            dirs[i].push_back(pii(x, y));
        }
    }

    int q; cin >> q;

    vector<pii> queries(q);

    for (int i = 0; i < q; ++i){
        cin >> queries[i].first >> queries[i].second;
        // cout << "query: " << queries[i].first << " " << queries[i].second << endl;
    }

    vector<int> order(q);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int u, int v){
        return queries[u].second < queries[v].second;
    });

    vector<int64> answer(q, -1);

    map<pii, int> last;

    for (int i = 1, j = 0; i <= n; ++i){
        for (auto d : dirs[i - 1]){
            if (last.find(d) != last.end())
                update(last[d], -1);
            update(i, +1);
            last[d] = i;

            // cout << d.first << " " << d.second << " " << i << endl;
        }

        for (;j < q && queries[order[j]].second == i; ++j){
            int u = order[j];
            int a = queries[u].first, b = queries[u].second;

            // cout << "Q: " << u << " " << a << " " << b << endl;
            // cout << last.size() << " " << a << " " << sum(a - 1) << endl;
            answer[u] = last.size() - sum(a - 1);
        }
    }

    for (int i = 0; i < q; ++i){
        assert(answer[i] != -1);
        cout << answer[i] << endl;
    }

    return 0;
}