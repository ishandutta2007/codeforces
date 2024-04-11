#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 100100;

int n, a[MAXN], b[MAXN], m;
int freq[MAXN], match, ans;

void init() {
    int l=0, r=n-1;
    while (l<=r && b[l] == b[r]) m++, l++, r--;
    if (l>r) {
        cout << ll(n)*(n+1)/2 << '\n';
        exit(0);
    }

    n = 0;
    for (int i=l; i<=r; i++) a[n++] = b[i];
}

bool check(int l) {
    memset(freq, 0, sizeof(freq));
    for (int i=0; i<=l; i++) freq[a[i]]++;
    for (int i=0; i<n-1-i; i++) {
        if (i<=l && n-1-i>l) {
            if (!freq[a[n-1-i]]) return 0;
            freq[a[n-1-i]]--;
        } else if (i>l) {
            if (a[i] != a[n-1-i]) return 0;
        }
    }

    int cnt = 0;
    for (int i=0; i<n; i++)
        if (freq[i]%2)
            cnt++;
    return cnt <= 1;
}

void go() {
    int lo = 0, hi = n;
    while (lo<hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) hi = mid;
        else lo = mid+1;
    }
    ans += n-lo;
}

int main() {
    ios_base::sync_with_stdio(0);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i=0; i<n; i++) cin >> b[i], b[i]--;
    init();

    go();
    reverse(a, a+n);
    go();

    if (ans == 0) cout << 0;
    else cout << ll(m+1)*(ans+m-1) << '\n';
    return 0;
}