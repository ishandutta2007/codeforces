#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;

const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 4e5 + 5;

int pr[N];

int main() {

    fill(pr, pr + N, 1);
    pr[0] = pr[1] = 0;
    for (int i = 2; i * i < N; i++) {
        if (!pr[i]) continue;
        for (int j = i * i; j < N; j += i) {
            pr[j] = 0;
        }
    }

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    int cnt[3] = {0, 0, 0};

    for (int x, i = 0; i < n; i++) {
        cin >> x;
        cnt[x]++;
    }

    if (cnt[2] == 0) {
        for (int i = 0; i < n; i++) {
            cout << "1 ";
        }
        cout << "\n";
        return 0;
    }

    cout << "2 ";
    cnt[2]--;

    int cur = 2;

    while (cnt[1] + cnt[2] > 0) {
        if (cnt[1] && pr[cur + 1]) {
            cur++;
            cout << "1 ";
            cnt[1]--;
            continue;
        }
        if (cnt[1] == 0) {
            cout << "2 ";
            cnt[2]--;
            continue;
        }
        if (cnt[2]) {
            cout << "2 ";
            cnt[2]--;
        } else {
            cout << "1 ";
            cnt[1]--;
        }
    }

    cout << "\n";

    return 0;
}