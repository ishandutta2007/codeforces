
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

// requirement: all(a[i]) <= all(b[i]) on the interval. Otherwise, max(a[i]) > min(b[i])
// at any point where a[i] > b[i], an interval cannot contain this i.
// for each L, how many R?
// we can increment R as long as max(a[i]) <= min(b[i])
// store the first occurrences of max(a[i]) and of min(b[i])
// the max of the first occurrences, up to R, is the range of valid R values for this L.

const int N = 2e5 + 5;
int n;
ll a[N], b[N];

deque<ll> qa, qb;
int l = 0, r = -1;

void left() {
    if(!qa.empty() && qa.front() == l) qa.pop_front();
    if(!qb.empty() && qb.front() == l) qb.pop_front();
    l++;
    r = max(r, l - 1);
}
void right() {
    r++;
    while(!qa.empty() && a[r] > a[qa.back()]) qa.pop_back();
    while(!qb.empty() && b[r] < /*f*/ b[qb.back()]) qb.pop_back();
    qa.push_back(r);
    qb.push_back(r);
}
int maxApos() {
    assert(!qa.empty());
    return qa.front();
}
int minBpos() {
    assert(!qb.empty());
    return qb.front();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> b[i];
    ll ans = 0;
    while(l < n) {
        while(r < n - 1 && ((l <= r && max(a[maxApos()], a[r + 1]) <= min(b[minBpos()], b[r + 1])) ||
                (r < l && a[r + 1] <= b[r + 1]))) {
            right();
        }
        if(l <= r && a[maxApos()] == b[minBpos()]) {
            ans += r - max(maxApos(), minBpos()) + 1;
        }
        left();
    }
    cout << ans << '\n';
}