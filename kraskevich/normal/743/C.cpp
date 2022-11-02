#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<int, int> pii;

const ll INF = (ll)1e18;
const int N = 200 * 1000 + 100;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin >> n;
    if (n == 1) {
        cout << -1 << endl;
        return 0;
    }
    cout << n << " " << n + 1 << " " << n * (n + 1) << endl;       
}