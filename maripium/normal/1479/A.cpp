#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    int low = 1, high = N;
    auto get_val = [&](int i) {
        if (i == 0 || i == N+1) return N+1;
        cout << "? " << i << '\n';
        cout << flush;
        int ans; cin >> ans;
        return ans;
    };
    while (low <= high) {
        int mid = (low + high) >> 1;
        int prv = get_val(mid-1);
        int cur = get_val(mid);
        int nxt = get_val(mid+1);
        if (cur < prv  && cur < nxt) {
            cout << "! " << mid << '\n';
            return 0;
        } else if (cur > prv) {
            high = mid - 1;
        } else {
            assert(cur > nxt);
            low = mid+1;
        }
    }
    assert(false);
}