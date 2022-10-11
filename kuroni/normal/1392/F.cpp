#include <bits/stdc++.h>
using namespace std;

const int N = 1E6 + 5;

int n;
long long a, ans[N], lst;
vector<int> pos;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> a;
    pos = {1};
    for (int i = 2; i <= n; i++) {
        lst = a;
        cin >> a;
        while (a - 2 >= lst) {
            int l = pos.back();
            if (l == 1) {
                long long tim = (a - lst - 2) / i;
                a -= tim * (i - 1); lst += tim;
            }
            long long dif = a - lst - 1;
            int r = min(i - 1LL, l + dif - 1);
            dif = r - l + 1;
            a -= dif;
            if (r == i - 1) {
                lst++;
                if (l > 1) {
                    pos.pop_back();
                }
            } else {
                if (l > 1) {
                    pos.back() = r + 1;
                } else {
                    pos.push_back(r + 1);
                }
            }
        }
        if (lst == a) {
            pos.push_back(i);
        }
    }
    for (int i = n; i >= 1; i--) {
        ans[i] = a--;
        if (pos.back() == i) {
            pos.pop_back();
            a++;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
}