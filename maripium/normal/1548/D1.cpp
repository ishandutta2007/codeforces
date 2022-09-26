#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
    int N; cin >> N;
    array<int, 4> F{};
    for (int i = 0; i < N; ++i) {
        int x, y; cin >> x >> y;
        x = abs(x / 2) & 1, y = abs(y / 2) & 1;
        F[x << 1 | y] ++;
    }   

    auto C2 = [&](int x) {
        return int64_t(x) * (x - 1) / 2;
    };

    auto C3 = [&](int x) {
        return int64_t(x) * (x - 1) * (x - 2) / 6;
    };

    int64_t ans = 0;
    for (int a = 0; a < 4; ++a) {
        ans += C3(F[a]);
        ans += C2(F[a]) * (N - F[a]);
    } 
    cout << ans << '\n';
	return 0;
}