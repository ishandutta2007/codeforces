
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

const int N = 1005;
int n, a[N];
map<int, int> ma;
set<pii> ss;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    rep(i, 0, n) {
        cin >> a[i];
        ma[a[i]]++;
    }
    int ans = 0;
    rep(i, 0, n) rep(j, 0, n) {
        if(i == j || ss.count({a[i], a[j]})) continue;
        vi ve;
        ve.push_back(a[i]);
        ma[a[i]]--;
        ve.push_back(a[j]);
        ma[a[j]]--;
        while(ma[ve[sz(ve) - 1] + ve[sz(ve) - 2]] > 0) {
            int val = ve[sz(ve) - 1] + ve[sz(ve) - 2];
            ma[val]--;
            ve.push_back(val);
        }
        ans = max(ans, sz(ve));
        for(int x : ve) {
            ma[x]++;
        }
        ss.emplace(a[i], a[j]);
    }
    cout << ans << '\n';
}