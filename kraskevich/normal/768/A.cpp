#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int mx = *max_element(a.begin(), a.end());
    int mn = *min_element(a.begin(), a.end());
    int res = 0;
    for (int x : a)
        if (mn < x && x < mx)
            res++;
    cout << res << endl;
}