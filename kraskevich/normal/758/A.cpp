#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); 
    int n;
    cin >> n;
    int tot = 0;
    int best = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        tot += x;
        best = max(best, x);
    }
    cout << best * n - tot << endl;
}