#include <bits/stdc++.h>    
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

int mabs(int x) {
    return x > 0 ? x : -x;
}
    
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    m--;
    int ans = n * 10;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        if (a[i] && a[i] <= k)
            ans = min(ans, mabs(i - m) * 10);
    cout << ans << endl;
}