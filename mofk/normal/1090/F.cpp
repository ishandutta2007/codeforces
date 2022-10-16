#include <bits/stdc++.h>

using namespace std;

int n;
long long a[1005];
long long b[1005];
long long ask(int x, int y, int z) {
    cout << "? " << x << ' ' << y << ' ' << z << endl;
    //return min(a[x], min(a[y], a[z])) + max(a[x], max(a[y], a[z]));
    long long ret;
    cin >> ret;
    return ret;
}

vector<pair<long long, vector<int>>> dat;
vector<long long> tot(6, 0);

bool cmp(int x, int y) {
    if (tot[x] != tot[y]) return tot[x] < tot[y];
    return x < y;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    //for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= 5; ++i) for (int j = i + 1; j <= 5; ++j) for (int k = j + 1; k <= 5; ++k) {
        long long ans = ask(i, j, k);
        dat.push_back({ans, {i, j, k}});
        tot[i] += ans;
        tot[j] += ans;
        tot[k] += ans;
    }
    vector<int> ord = {1, 2, 3, 4, 5};
    sort(ord.begin(), ord.end(), cmp);
    map<pair<int, int>, long long> memo;
    for (auto z: dat) {
        sort(z.second.begin(), z.second.end(), cmp);
        memo[{z.second[0], z.second[2]}] = z.first;
        memo[{z.second[2], z.second[0]}] = z.first;
    }
    long long tot_all = 0;
    for (int i = 0; i < 5; ++i) tot_all += memo[{ord[i], ord[(i + 2) % 5]}];
    tot_all /= 2;
    for (int i = 0; i < 5; ++i) b[ord[i]] = tot_all - memo[{ord[(i + 1) % 5], ord[(i + 3) % 5]}] - memo[{ord[(i + 2) % 5], ord[(i + 4) % 5]}];
    
    for (int i = 6; i <= n; ++i) {
        long long ans = ask(i, ord[1], ord[2]);
        long long target = b[ord[1]] + b[ord[2]];
        if (ans < target) b[i] = ans - b[ord[2]];
        else if (ans > target) b[i] = ans - b[ord[1]];
        else {
            ans = ask(i, ord[2], ord[3]);
            b[i] = ans - b[ord[3]];
        }
    }

    cout << "!";
    for (int i = 1; i <= n; ++i) cout << ' ' << b[i];
    cout << endl;
    return 0;
}