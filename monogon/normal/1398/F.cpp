
#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

const int N = 1e6 + 5;
int n;
string s;
int ans[N];
int val0[N], val1[N], val[N];
int par[N];

int trace(int x) {
    return par[x] == x ? x : par[x] = trace(par[x]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> s;
    for(int i = n - 1; i >= 0; i--) {
        if(s[i] == '0') {
            val1[i] = 0;
            val0[i] = 1 + val0[i + 1];
        }else if(s[i] == '1') {
            val1[i] = 1 + val1[i + 1];
            val0[i] = 0;
        }else {
            val0[i] = 1 + val0[i + 1];
            val1[i] = 1 + val1[i + 1];
        }
        val[i] = max(val0[i], val1[i]);
    }
    vector<pii> ve;
    rep(i, 0, n + 1) ve.emplace_back(val[i], i);
    sort(all(ve));
    int idx = 0;
    rep(i, 0, n + 1) par[i] = i;
    rep(k, 1, n + 1) {
        int i = 0;
        while(idx < sz(ve) && ve[idx].first < k) {
            // se.erase(ve[idx].second);
            if(ve[idx].second < n) par[ve[idx].second] = trace(ve[idx].second + 1);
            idx++;
        }
        while(i < n) {
            int j = trace(i);
            // auto it = se.lower_bound(i);
            if(j == n) break;
            i = j + k;
            ans[k]++;
        }
    }

    rep(i, 1, n + 1) {
        cout << ans[i] << ' ';
    }
    cout << endl;
}