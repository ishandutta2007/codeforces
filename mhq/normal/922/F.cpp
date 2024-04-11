#include <bits/stdc++.h>
using namespace std;
const int maxN = 3 * (int)1e5 + 10;
int n, k;
int d[maxN];
int lp[maxN];
bool used[maxN];
bool A[1000][3000];
vector < int > pr;
vector < pair < int, int > > divisors;
void calc() {
    d[1] = 1;
    for (int i = 2; i < maxN; i++) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; j < pr.size() && pr[j] <= lp[i] && pr[j] * i < maxN; j++) {
            lp[i * pr[j]] = pr[j];
        }
        int t = i;
        int prv = lp[t];
        int exp = 0;
        while (t > 1) {
            if (lp[t] != prv) {
                d[i] = d[t] * (exp + 1);
                break;
            }
            exp++;
            t = t / lp[t];
        }
        if (t == 1) d[i] = exp + 1;
    }
}
int check(int n) {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += (n / i);
    }
    return ans - n;
}
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    calc();
    cin >> n >> k;
    if (k <= check(18)) n = min(18, n);
    if (n <= 18) {
        for (int mask = 0; mask < (1 << n); mask++) {
            int ans = 0;
            for (int i1 = 0; i1 < n; i1++) {
                if (mask & (1 << i1)) {
                    for (int i2 = i1 + 1; i2 < n; i2++) {
                        if (mask & (1 << i2)) {
                            if ((i2 + 1) % (i1 + 1) == 0) ans++;
                        }
                    }
                }
            }
            if (ans == k) {
                cout << "Yes" << '\n';
            }
            else continue;
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) cnt++;
            }
            cout << cnt << '\n';
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) cout << i + 1 << " ";
            }
            return 0;
        }
        cout << "No";
        return 0;
    }
    int l = 1;
    int r = n;
    if (check(r) < k) {
        cout << "No";
        return 0;
    }
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (check(mid) >= k) r = mid;
        else l = mid;
    }
    int t = check(r);
    if (t == k) {
        cout << "Yes" << '\n';
        cout << r << endl;
        for (int i = 1; i <= r; i++) {
            cout << i << " ";
        }
        return 0;
    }
    int ne = t - k;
    for (int i = r; 2 * i > r; i--) {
        divisors.push_back(make_pair(d[i] - 1, i));
    }
    sort(divisors.begin(), divisors.end());
    A[0][0] = true;
    int ind = -1;
    for (int i = 0; i < min((int)divisors.size(), 999); i++) {
        int t = divisors[i].first;
        for (int j = 0; j <= ne; j++) {
            A[i + 1][j + t] |= A[i][j + t];
            A[i + 1][j + t] |= A[i][j];
        }
        if (A[i + 1][ne]) {
            ind = i + 1;
            break;
        }
    }
    int cur = ne;
    while (cur > 0) {
        if (cur >= divisors[ind - 1].first && A[ind - 1][cur - divisors[ind - 1].first]) {
            used[divisors[ind - 1].second] = true;
            cur = cur - divisors[ind - 1].first;
            ind--;
        }
        else ind--;
    }
    int re = 0;
    for (int i = 1; i <= r; i++) if (!used[i]) re++;
    cout << "Yes" << '\n';
    cout << re << '\n';
    for (int i = 1; i <= r; i++) if (!used[i]) cout << i << " ";
    return 0;
}