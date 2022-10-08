
// #pragma GCC optimize ("Ofast")
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

// find subarray maximizing (sum - max)
// fix max of subarray, and find max sum subarray that
// contains one or more of these anchor points
// split into val (not val segment) val (not val segment) ...
// for each segment, find sum, max prefix sum, max suffix sum.
// I hate this, stupid implementation

// split into segments, where all values <= V
// on each segment find max sum subarray

const int N = 1e5 + 5;
int n, a[N], ans = 0;

int process(vi &ve) {
    int best = -1e8;
    int sum = 0, i = 0;
    rep(j, 0, sz(ve)) {
        sum += ve[j];
        if(sum < 0) {
            i = j + 1;
            sum = 0;
        }
        if(i <= j) {
            best = max(best, sum);
        }
    }
    return best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    rep(i, 0, n) {
        cin >> a[i];
    }
    rep(v, -30, 31) {
        vi ve;
        rep(i, 0, n) {
            if(a[i] <= v) {
                ve.push_back(a[i]);
            }else {
                if(!ve.empty()) {
                    ans = max(ans, process(ve) - v);
                    ve.clear();
                }
            }
        }
        if(!ve.empty()) {
            ans = max(ans, process(ve) - v);
            ve.clear();
        }
    }
    cout << ans << '\n';
}