#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;

int N, M, flag;
int a[105][105];
int b[105][105];
int row[105], col[105];
vector <pair <int, int> > steps;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    if (N > M) flag = 1, swap(N, M);
    if (!flag) ff(i, 1, N) ff(j, 1, M) cin >> a[i][j];
    else ff(j, 1, M) ff(i, 1, N) cin >> a[i][j];
    ff(i, 1, N) ff(j, 1, M) b[i][j] = a[i][j] - a[i][1];
    ff(i, 1, N) ff(k, i + 1, N) ff(j, 1, M) if (b[i][j] != b[k][j]) return cout << -1 << endl, 0;
    int ans = 0;
    ff(i, 1, N) {
        int mn = a[i][1];
        ff(j, 2, M) mn = min(mn, a[i][j]);
        ff(j, 1, M) a[i][j] -= mn;
        row[i] += mn, ans += mn;
    }
    ff(i, 1, M) col[i] += a[1][i], ans += a[1][i];
    cout << ans << endl;
    if (!flag) {
        ff(i, 1, N) ff(rep, 1, row[i]) steps.push_back(make_pair(0, i));
        ff(i, 1, M) ff(rep, 1, col[i]) steps.push_back(make_pair(1, i));
    }
    else {
        ff(i, 1, M) ff(rep, 1, col[i]) steps.push_back(make_pair(0, i));
        ff(i, 1, N) ff(rep, 1, row[i]) steps.push_back(make_pair(1, i));
    }
    sort(steps.begin(), steps.end());
    for (int i = 0; i < steps.size(); ++i) cout << (steps[i].first ? "col" : "row") << ' ' << steps[i].second << endl;
    return 0;
}