#include <bits/stdc++.h>    
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair
    
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, t, k, d;
    cin >> n >> t >> k >> d;
    int one = t * ((n + k - 1) / k);
    int cnt2 = k * ((one - 1) / t + (one - d - 1) / t);
    cout << (cnt2 >= n ? "YES": "NO") << endl;
}