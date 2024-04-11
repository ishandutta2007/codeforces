#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
         int n, k;
         cin >> n >> k;
         string s;
         cin >> s;
         int cw = 0;
         vector<int> blocks1, blocks2;
         int cur = 0;
         for (int i = 0; i < n; i++) {
             if (s[i] != 'W')
                 continue;
             int j = i;
             while (j < n && s[j] == 'W')
                 j++;
             j--;
             cur++;
             i = j;
         }
         if (cur == 0) {
             cout << max(0, 2 * k - 1) << "\n";
             continue;
         }
         for (int i = 0; i < n; i++) {
             if (s[i] == 'W') {
                 cw++;
                 continue;
             }
             int j = i;
             while (j < n && s[j] == 'L')
                 j++;
             j--;
             // [i, j]
             int len = j - i + 1;
             if (0 < i && j + 1 < n)
                 blocks2.push_back(len);
             else
                 blocks1.push_back(len);
             i = j;
         }
         sort(blocks2.begin(), blocks2.end());
         cw = min(n, cw + k);
         for (int x : blocks2) {
             if (x > k)
                 break;
             k -= x;
             cur--;
         }
         cout << 2 * cw - cur << "\n";
    }

    return 0;
}