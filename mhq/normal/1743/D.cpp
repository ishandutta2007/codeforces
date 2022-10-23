#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxN = 1e6 + 10;
int val[maxN];
const int BUBEN = 50;
int cur_opt[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
        val[i] = (s[i] - '0');
    }
    for (int pref1 = n; pref1 >= 1 && pref1 >= n - BUBEN; pref1--) {
        for (int pref2 = pref1; pref2 >= 1 && pref2 >= n - BUBEN; pref2--) {
            int C = 0;
            for (int x = 0; x < n; x++) {
                int we = 0;
                if (x >= n - pref1) {
                    we |= (val[x - (n - pref1)]);
                }
                if (x >= n - pref2) {
                    we |= (val[x - (n - pref2)]);
                }
                if (we != cur_opt[x]) {
                    if (we < cur_opt[x]) {
                        C = 1;
                        break;
                    }
                    else {
                        C = -1;
                        break;
                    }
                }
            }
            if (C == -1) {
                for (int x = 0; x < n; x++) {
                    int we = 0;
                    if (x >= n - pref1) {
                        we |= (val[x - (n - pref1)]);
                    }
                    if (x >= n - pref2) {
                        we |= (val[x - (n - pref2)]);
                    }
                    cur_opt[x] = we;
                }
            }
        }
    }
    int ptr = 0;
    while (ptr < n && cur_opt[ptr] == 0) ptr++;
    if (ptr == n) {
        cout << 0;
    }
    else {
        for (int c = ptr; c < n; c++) cout << cur_opt[c];
    }
    return 0;
}