#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxN = 305;
const int L = 0;
const int R = 1;
int cur_sum = 0;
int new_sum = 0;
vector < pair < int, int > > logs;
bool know[maxN];
int val[maxN];
int n;
int ask(int l, int r) {
    cout << "? " << l << " " << r << endl;
    cin >> new_sum;
    if (new_sum == -1) assert(false);
    int dif = abs(new_sum - cur_sum) % 2;
    if ((dif % 2) == ((n - l + 1) % 2)) {
        for (int i = l; i <= n; i++) {
            if (know[i]) val[i] ^= 1;
        }
        logs.push_back(make_pair(l, n));
        return L;
    }
    else {
        for (int i = 1; i <= r; i++) {
            if (know[i]) val[i] ^= 1;
        }
        logs.push_back(make_pair(1, r));
        return R;
    }
}
void bactrack() {
    while (!logs.empty()) {
        auto t = logs.back();
        logs.pop_back();
        for (int i = t.first; i <= t.second; i++) val[i] ^= 1;
    }
}
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(239);
    int rem;
    cin >> n >> cur_sum;
    rem = cur_sum;
    if (n == 1) {
        cout << "! " << cur_sum << endl;
        return 0;
    }
    // l, n - l
    for (int i = 1; i <= n - i; i++) {
        int l = i;
        int r = n - i;
        while (true) {
            int tp = ask(l, r);
            if (tp == R) {
                int now = 0;
                for (int  j = r + 2; j <= n; j++) {
                    now += val[j];
                }
                int a = (new_sum + cur_sum - 2 * now - r) / 2;
                val[r + 1] = a;
                know[r + 1] = true;
                cur_sum = new_sum;
                break;
            }
            else {
                cur_sum = new_sum;
                continue;
            }
        }
    }
    for (int i = 2; i <= n + 2 - i; i++) {
        int l = i;
        int r = n + 2 - i;
        while (true) {
            int tp = ask(l, r);
            if (tp == L) {
                int now = 0;
                for (int j = 1; j < l - 1; j++) {
                    now += val[j];
                }
                int a = (new_sum + cur_sum - (n - l + 1) - 2 * now) / 2;
                val[l - 1] = a;
                know[l - 1] = true;
                cur_sum = new_sum;
                break;
            }
            else {
                cur_sum = new_sum;
                continue;
            }
        }
    }
    bactrack();
    int all_sum = rem;
    if (n % 2 == 1) {
        for (int i = 1; i <= n; i++) {
            if (i == (n + 1) / 2) continue;
            all_sum -= val[i];
        }
        val[(n + 1) / 2] = all_sum;
    }
    cout << "! ";
    for (int i = 1; i <= n; i++) cout << val[i];
    cout << endl;
    return 0;
}