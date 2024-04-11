#include <bits/stdc++.h>

using namespace std;

int sum[10005];

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);
    int n; cin >> n;
    for (int i=0, cur=0; i<=n+1; i++, cur += i) sum[i] = cur;
    for (int i=1; i<=n+1; i++) {
        long long cur = 0;
        for (int j=1; j<=i; j++)
            cur += sum[j];
        if (cur > n) {
            cout << i-1;
            return 0;
        }
    }
}