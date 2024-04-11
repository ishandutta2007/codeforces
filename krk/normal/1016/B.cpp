#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005;

int n, m, q;
string s;
string t;
int sum[Maxn];

int main()
{
    cin >> n >> m >> q;
    cin >> s;
    cin >> t;
    for (int i = 0; i + t.length() <= s.length(); i++)
        if (s.substr(i, t.length()) == t) {
            sum[i + 1]++;
        }
    for (int i = 1; i <= n; i++)
        sum[i] += sum[i - 1];
    while (q--) {
        int l, r; scanf("%d %d", &l, &r);
        r -= (int(t.length()) - 1);
        int res = l <= r? sum[r] - sum[l - 1]: 0;
        printf("%d\n", res);
    }
    return 0;
}