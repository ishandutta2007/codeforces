#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int n;
string s;
int cnt[Maxn];
int res;

int main()
{
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        int cur = s[i] - '0';
        cnt[0] += cur;
        cnt[b] -= cur;
        for (int j = b; j + a < Maxn; j += a) {
            cur = 1 - cur;
            cnt[j] += cur;
            cnt[j + a] -= cur;
        }
    }
    int cur = 0;
    for (int i = 0; i < Maxn; i++) {
        cur += cnt[i];
        res = max(res, cur);
    }
    printf("%d\n", res);
    return 0;
}