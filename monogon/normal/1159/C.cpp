
#include <bits/stdc++.h>

#define FOR(i, n) for(int i = 0; i < n; i++)
#define FORK(i, k, n) for(int i = k; i < n; i++)
#define FORr(i, n) for(int i = n - 1; i >= 0; i--)
#define FORKr(i, k, n) for(int i = n - 1; i >= k; i--)
#define PRINT(a, b) copy((a), (b), ostream_iterator<int>(cout, " "))
#define all(a) a.begin(), a.end()
#define in(a, b) ((b).find(a) != (b).end())
#define sz(a) ((int) (a).size())
#define Mp make_pair
#define PII pair<int, int>
#define ll long long
#define VI vector<int>

using namespace std;

// b[i] = minimum given
// g[j] = maximum received

// The ith boy gives at least b[i] candies to each girl
// Therefore, min g >= max b. If so, it's possible. Otherwise, impossible

const int MAX_N = 1e5 + 5;

int n, m;

ll b[MAX_N], g[MAX_N];

int main() {
    std::ios_base::sync_with_stdio(false);
    cin >> n >> m;
    ll sum = 0;
    FOR(i, n) {
        cin >> b[i];
        sum += b[i];
    }
    sum *= m;
    FOR(i, m) {
        cin >> g[i];
    }

    sort(b, b + n);
    sort(g, g + m);
    if(b[n - 1] > g[0]) {
        cout << -1 << endl;
        return 0;
    }

    for(int i = m - 1; i > 0; i--) {
        sum += g[i] - b[n - 1];
    }
    if(b[n - 1] == g[0]) {
        sum += g[0] - b[n - 1];
    }else {
        sum += g[0] - b[n - 2];
    }

    cout << sum << endl;
}