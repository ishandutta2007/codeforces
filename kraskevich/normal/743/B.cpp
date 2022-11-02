#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<int, int> pii;

const ll INF = (ll)1e18;
const int N = 200 * 1000 + 100;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    ll n, k;
    cin >> n >> k;
    ll res = 1;
    while (k % 2 == 0) {
        k /= 2;
        res++;
    }
    cout << res << endl;    
}