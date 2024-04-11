#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <ios>

using namespace std;

#define A first
#define B second

typedef pair<int, int> pii;

const int maxn = 100100;

int n, a[maxn], f[maxn];

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    int l = 0; f[a[l]]++;
    int cnt = 1, ans = 1;
    for (int i = 1; i < n; i++) {
        if (!f[a[i]] && cnt == 2) {
            while (cnt == 2) {
                f[a[l]]--;
                if (!f[a[l]]) cnt--;
                l++;
            }
        }

        f[a[i]]++;
        if (f[a[i]] == 1) cnt++;
        ans = max(ans, i - l + 1);
    }

    cout << ans << '\n';
}