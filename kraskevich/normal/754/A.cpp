#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); 
    int n;
    cin >> n;
    vector<int> a(n);
    int last = -1;
    int tot = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        tot += a[i];
        if (a[i])
            last = i;
    }
    if (last == -1) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    if (tot) {
        cout << 1 << endl << 1 << " " << n << endl;
        return 0;
    }
    cout << 2 << endl;
    cout << 1 << " " << last << endl;
    cout << last + 1 << " " << n << endl;      
}