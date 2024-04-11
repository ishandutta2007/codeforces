#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 100100;

int n, k, ar[maxn];

vector<int> vd;
int numd[maxn][30];
int totd[30];

void fact() {
    int x = k;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) vd.push_back(i);
        while (x % i == 0) x /= i, numd[n][vd.size() - 1]++;
    }
    if (x > 1) {
        vd.push_back(x);
        numd[n][vd.size() - 1]++;
    }
}

bool good() {
    for (int i = 0; i < vd.size(); i++)
        if (totd[i] < numd[n][i])
            return 0;
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n >> k;
    if (k == 1) {
        cout << ll(n + 1) * n / 2 << '\n';
        return 0;
    }

    fact();

    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        for (int j = 0; j < vd.size(); j++) {
            while (ar[i] % vd[j] == 0) ar[i] /= vd[j], numd[i][j]++;
        }
    }
/*
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < vd.size(); j++) cout << numd[i][j] << ' ';
        cout << '\n';
    }
*/
    ll ans = 0;
    
    int y = 0;
    for (int i = 0; i < n; i++) {
        while (y < n && !good()) {
            for (int j = 0; j < vd.size(); j++) totd[j] += numd[y][j];
            y++;
        }
        if (y == n && !good()) break;

        ans += n - y + 1;

        for (int j = 0; j < vd.size(); j++) totd[j] -= numd[i][j];
    }

    cout << ans << '\n';
}