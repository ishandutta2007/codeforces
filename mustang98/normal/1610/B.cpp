#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 200111, inf = 1000111222;

int m[max_n];
int n;

bool check(int x) {
    int l = 0, r = n - 1;
    while(l < r) {
        if (m[l] == m[r]) {
            ++l, --r;
            continue;
        }
        if (m[l] != x && m[r] != x) {
            return false;
        }
        if (m[l] == x) ++l;
        if (m[r] == x) --r;
    }
    return true;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> m[i];
        }
        vector<int> cand;
        for (int i = 0; i < n / 2; ++i) {
            int a = m[i];
            int b = m[n - 1 - i];
            if (a != b) {
                cand.PB(a);
                cand.PB(b);
                break;
            }
        }
        if (cand.empty()) {
            puts("YES");
            continue;
        }
        if (check(cand[0]) || check(cand[1])) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    return 0;
}