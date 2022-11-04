#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
 
#define fi first
#define se second
#define endl '\n'
#define MOD(n,k) (((n % k) + k ) % k)

int n, b[100005], c[100005], x;
ll m, w[100005];

bool comp (int a, int b) {
    return (100 - c[a]) * w[a] > (100 - c[b]) * w[b];
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> x;

        b[i] = x / 100;
        c[i] = x % 100;
    }
    for (int i = 0; i < n; i++)
        cin >> w[i];

    priority_queue<int, vi, decltype(&comp)> pq(&comp);

    ll res = 0;
    for (int i = 0; i < n; i++) {
        if (c[i]) {
            if (m >= c[i]) {
                m -= c[i];
                pq.push(i);
            } else {
                if (pq.size()) {
                    int u = pq.top();

                    if (comp(i, u)) {
                        pq.pop();

                        b[u]++;
                        m += 100;
                        res += (100 - c[u]) * w[u];
                        c[u] = 0;

                        m -= c[i];
                        pq.push(i);
                    } else {
                        b[i]++;
                        m += 100 - c[i];
                        res += (100 - c[i]) * w[i];
                        c[i] = 0;
                    }
                } else {
                    b[i]++;
                    m += 100 - c[i];
                    res += (100 - c[i]) * w[i];
                    c[i] = 0;
                }
            }
        }
    }

    cout << res << endl;
    for (int i = 0; i < n; i++)
        cout << b[i] << " " << c[i] << endl;

    return 0;
}