#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 55;

int n;
ll k;
ll num[MAXN];
int ans[MAXN];

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);
    cin >> n >> k;
    num[0] = num[1] = 1;
    for (int i=2; i<MAXN; i++) num[i] = num[i-1] + num[i-2];

    int cur = 0;
    while (cur < n) {
        if (num[n-cur-1] >= k) ans[cur] = cur, cur++;
        else {
            k -= num[n-cur-1];
            ans[cur] = cur+1, ans[cur+1] = cur, cur += 2;
        }
    }

    for (int i=0; i<n; i++) cout << ans[i]+1 << ' ';
}