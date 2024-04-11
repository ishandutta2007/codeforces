
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 4e5 + 5;
int n, a[N];

ll cnt(int l, int r, int L, int R, int d) {
    int j = R - 1;
    ll ans = 0;
    ll D = (1LL << d);
    for(int i = l; i < r; i++) {
        while(j >= L && (a[i] % D) + (a[j] % D) >= D) j--;
        ans += j - L + 1;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    srand(time(NULL));
    cin >> n;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum ^= (a[i] + a[i]);
    }
    for(int d = 0; d < 25; d++) {
        int k = stable_partition(a, a + n, [d](int x) { return ((x >> d) & 1) == 0; }) - a;
        ll c1 = k * k - cnt(0, k, 0, k, d);
        ll D = (1LL << d);
        for(int i = 0; i < k; i++) {
            if((a[i] % D) + (a[i] % D) >= D) c1++;
        }
        ll c2 = (n - k) * (n - k) - cnt(k, n, k, n, d);
        for(int i = k; i < n; i++) {
            if((a[i] % D) + (a[i] % D) >= D) c2++;
        }
        c1 /= 2;
        c2 /= 2;
        ll c3 = cnt(0, k, k, n, d);
        if((c1 + c2 + c3) % 2) {
            sum ^= (1 << d);
        }
    }
    cout << sum << endl;
}