#include <bits/stdc++.h>    
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair
    
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<ll> a(n);
    for_each(a.begin(), a.end(), [](ll &x) { cin >> x; });
    sort(a.begin(), a.end());
    ll mn = a[1] - a[0];
    for (int i = 1; i < n; i++)
        mn = min(mn, a[i] - a[i - 1]);
    int cnt = 0;
    for (int i = 1; i < n; i++)
        if (a[i] - a[i - 1] == mn)
            cnt++;
    cout << mn << " " << cnt << endl;
}