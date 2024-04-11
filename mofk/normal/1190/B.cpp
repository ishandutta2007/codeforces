#include <bits/stdc++.h>

using namespace std;

int n;
int a[100005];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);
    int same = 0;
    for (int i = 1; i < n; ++i) if (a[i] == a[i+1]) {
        if (same) return cout << "cslnb" << endl, 0;
        same = i;
    }
    if (same) {
        if (a[same] == 0 || (same > 1 && a[same-1] == a[same] - 1))
            return cout << "cslnb" << endl, 0;
    }
    long long sum = 0, tar = 0;
    for (int i = 1; i <= n; ++i) sum += a[i], tar += i - 1;
    if (sum % 2 == tar % 2) cout << "cslnb" << endl;
    else cout << "sjfnb" << endl;
    return 0;
}