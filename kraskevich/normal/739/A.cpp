#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int min_len = n;
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        min_len = min(min_len, r - l + 1);
    }
    cout << min_len << endl;
    for (int i = 0; i < n; i++)
        cout << i % min_len << " ";
    cout << endl;
}