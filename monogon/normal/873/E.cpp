
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

const int N = 3005;
int n, a[N], b[N], mx[N][N], cons[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    vector<pii> ve;
    rep(i, 0, n) {
        cin >> a[i];
        ve.emplace_back(a[i], i);
    }
    sort(all(ve));
    int besti = 0, bestj = 0, bestk = 0;
    tuple<int, int, int> best = {-1, -1, -1};
    rep(len, 1, n + 1) {
        rep(i, 0, n - len + 1) {
            mx[i][i + len] = ve[i].first - (i == 0 ? 0 : ve[i - 1].first);
            cons[i][i + len] = i;
            if(len > 1 && mx[i + 1][i + len] > mx[i][i + len]) {
                mx[i][i + len] = mx[i + 1][i + len];
                cons[i][i + len] = cons[i + 1][i + len];
            }
        }
    }
    
    rep(i, 1, n) {
        rep(j, i + 1, n) {
            int cnt1 = n - j;
            int cnt2 = j - i;
            int cnt3min = max((cnt1 + 1) / 2, (cnt2 + 1) / 2);
            int cnt3max = min({2 * cnt1, 2 * cnt2, i});
            // max difference in ve in range [n - cnt1 - cnt2 - cnt3max, n - cnt1 - cnt2 - cnt3min]
            if(cnt3min > cnt3max) continue;
            int k = cons[n - cnt1 - cnt2 - cnt3max][n - cnt1 - cnt2 - cnt3min + 1];
            int cnt3 = n - cnt1 - cnt2 - k;
            if(cnt1 > 0 && cnt2 > 0 && cnt3 > 0 && max({cnt1, cnt2, cnt3}) <= 2 * min({cnt1, cnt2, cnt3}) &&
                    make_tuple(ve[j].first - ve[j - 1].first, ve[i].first - ve[i - 1].first, ve[k].first - (k == 0 ? 0 : ve[k - 1].first)) > best) {
                best = make_tuple(ve[j].first - ve[j - 1].first, ve[i].first - ve[i - 1].first, ve[k].first - (k == 0 ? 0 : ve[k - 1].first));
                besti = k;
                bestj = i;
                bestk = j;
            }
        }
    }
    
    rep(i, 0, besti) b[ve[i].second] = -1;
    rep(i, besti, bestj) b[ve[i].second] = 3;
    rep(i, bestj, bestk) b[ve[i].second] = 2;
    rep(i, bestk, n) b[ve[i].second] = 1;
    rep(i, 0, n) {
        cout << b[i] << ' ';
    }
    cout << '\n';
}