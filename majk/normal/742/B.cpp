#include <iostream>
#include <vector>

typedef long long ll;
using namespace std;

int main() {
    vector<int> D(1<<18, 0);
    ll ans = 0;
    int N, X; cin >> N >> X;
    for (int i = 0; i < N; ++i) {
        int a; cin >> a;
        ans += D[a^X];
        D[a]++;
    }
    cout << ans << endl;
}