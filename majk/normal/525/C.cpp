#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
int main() {
    int N; cin >> N;
    vector<int> L(N);
    for (int&l:L) cin >> l;
    sort(L.begin(),L.end());
    reverse(L.begin(),L.end());

    vector<int> H;
    for (int i = 0; i < N-1; ++i) {
        if (L[i+1] >= L[i] - 1) {
            H.push_back(L[i+1]);
            ++i;
        }
    }

    ll ans = 0;
    for (int i = 0; i+1 < H.size(); i+=2) {
        ans += ll(H[i]) * ll(H[i+1]);
    }
    cout << ans << endl;
}