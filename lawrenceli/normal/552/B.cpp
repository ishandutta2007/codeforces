#include <bits/stdc++.h>
using namespace std;

long long n;
long long ans = 0;

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    long long x = 1, last = 0;
    for (int i=1; i<=10; i++) {
        x *= 10;
        long long num = min(n, x-1);
        ans += (num-last)*i;
        last = num;
    }
    cout << ans;
}