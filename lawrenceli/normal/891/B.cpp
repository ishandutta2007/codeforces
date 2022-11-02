#include <bits/stdc++.h>

using namespace std;

int n;
pair<int, int> a[30];
int ans[30];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++)
        ans[a[(i + 1) % n].second] = a[i].first;

    for (int i = 0; i < n; i++) cout << ans[i] << ' ';
}