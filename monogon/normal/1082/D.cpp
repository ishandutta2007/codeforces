
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

const int N = 505;
int n, a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    vi ve, ve2;
    ll sum = 0;
    rep(i, 1, n + 1) {
        cin >> a[i];
        sum += a[i];
        if(a[i] == 1) {
            ve.push_back(i);
        }else {
            ve2.push_back(i);
        }
    }
    if(sum < 2 * (n - 1)) {
        cout << "NO\n";
        return 0;
    }
    int k = sz(ve2);
    int diam = k - 1;
    vector<pii> edges;
    for(int i = 1; i < k; i++) {
        edges.emplace_back(ve2[i - 1], ve2[i]);
        a[ve2[i - 1]]--;
        a[ve2[i]]--;
    }
    if(sz(ve) > 0) {
        int x = ve.back(); ve.pop_back();
        edges.emplace_back(ve2[0], x);
        a[ve2[0]]--;
        diam++;
    }
    if(sz(ve) > 0) {
        int x = ve.back(); ve.pop_back();
        edges.emplace_back(ve2[k - 1], x);
        a[ve2[k - 1]]--;
        diam++;
    }
    int j = 0;
    for(int x : ve) {
        while(a[ve2[j]] == 0) j++;
        edges.emplace_back(ve2[j], x);
        a[ve2[j]]--;
    }

    cout << "YES " << diam << '\n';
    cout << sz(edges) << '\n';
    for(auto &p : edges) {
        cout << p.first << ' ' << p.second << '\n';
    }
}