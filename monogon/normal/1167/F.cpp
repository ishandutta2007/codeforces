
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

const int MAX_N = 5e5 + 5;
const int M = 1e9 + 7;

int n;
ll a[MAX_N], tree1[MAX_N], tree2[MAX_N];
int place[MAX_N];

ll sum(int k, ll *tree) {
    ll s = 0;
    while(k >= 1) {
        s += tree[k];
        s %= M;
        k -= k & -k;
    }
    return s;
}
void add(int k, ll x, ll *tree) {
    while(k <= n) {
        tree[k] += x;
        tree[k] %= M;
        k += k & -k;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin >> n;
    vector<pair<ll, int> > v(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        v[i] = {a[i], i};
    }
    sort(all(v));
    for(int i = 1; i <= n; i++) {
        place[v[i].second] = i;
    }
    fill(tree1, tree1 + n + 1, 0);
    fill(tree2, tree2 + n + 1, 0);
    ll s = 0;
    for(int i = 1; i <= n; i++) {
        add(place[i], i, tree1);
        add(place[i], i * a[i], tree2);
        s += ((sum(place[i], tree1) * (n - i + 1)) % M) * a[i];
        s %= M;
        s += ((sum(n, tree2) - sum(place[i], tree2) % M + M) % M) * (n - i + 1);
        s %= M;
    }
    cout << s << endl;
}