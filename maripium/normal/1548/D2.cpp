#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    auto CCW = [&](pair<int, int> A, pair<int, int> B) {
        return A.first * B.second - A.second * B.first;
    };

    auto AREA = [&](pair<int, int> A, pair<int, int> B, pair<int, int> C) {
        B.first -= A.first;
        B.second -= A.second;
        C.first -= A.first;
        C.second -= A.second;
        return CCW(B, C);
    };

    auto C2 = [&](int x) {
        return int64_t(x) * (x - 1) / 2;
    };

    auto C3 = [&](int x) {
        return int64_t(x) * (x - 1) * (x - 2) / 6;
    };

    auto solve = [&](vector<pair<int, int>> P) {
        int N = int(P.size());
        array<int, 4> F{};
        for (auto [x, y] : P) {
            if (x & 1) x++;
            if (y & 1) y++;
            assert(x % 2 == 0);
            assert(y % 2 == 0);
            x /= 2, y /= 2;
            int px = x % 2; if (px < 0) px += 2;
            int py = y % 2; if (py < 0) py += 2;
            assert(0 <= px && px < 2);
            assert(0 <= py && py < 2);
            F[px * 2 + py] ++;
        }

        int64_t ans = 0;
        for (int i = 0; i < 4; ++i) {
            ans += C3(F[i]);
            ans += C2(F[i]) * (N - F[i]);
        }
        return ans;
    };

    int N; cin >> N;
    vector<pair<int, int>> P(N);
    for (auto &[x, y] : P) cin >> x >> y;

    int64_t ans = 0;
    // both even
    for (int a = 0; a < 2; ++a) {
        for (int b = 0; b < 2; ++b) {
            vector<pair<int, int>> P0;
            for (auto [x, y] : P) {
                if ((x + a) & 1) continue;
                if ((y + b) & 1) continue;
                P0.push_back({x, y});
            }
            ans += solve(P0);
        }
    }

    // 1 even 2 odds;

    for (int i = 0; i < N; ++i) {
        array<int, 64> F{};
        for (int j = 0; j < N; ++j) {
            if ((P[i].first + P[j].first) % 2 == 0 && (P[i].second + P[j].second) % 2 == 0) continue;
            int dg = __gcd(abs(P[i].first - P[j].first), abs(P[i].second - P[j].second)) % 4;
            int dx = P[j].first % 4; if (dx < 0) dx += 4;
            int dy = P[j].second % 4; if (dy < 0) dy += 4;
            assert(dg % 2);
            F[16 * dg + 4 * dx + dy] ++;
        }

        int dx0 = P[i].first % 4; if (dx0 < 0) dx0 += 4;
        int dy0 = P[i].second % 4; if (dy0 < 0) dy0 += 4;

        for (int c0 = 0; c0 < 64; ++c0) if (F[c0]) {
            for (int c1 = c0; c1 < 64; ++c1) if (F[c1]) {
                int dg0 = c0 / 16;
                int dx1 = (c0 % 16) / 4;
                int dy1 = (c0 % 4);
                int dg1 = c1 / 16;
                int dx2 = (c1 % 16) / 4;
                int dy2 = c1 % 4;
                int b = dg0 + dg1;
                if (dx1 + dx2 & 1) continue;
                if (dy2 + dy2 & 1) continue;
                if ((dx1 - dx2) % 4 == 0 && (dy1 - dy2) % 4 == 0) {
                } else {
                    b += 2;
                }
                assert(b % 2 == 0);
                b /= 2;
                int A = AREA({dx0, dy0}, {dx1, dy1}, {dx2, dy2});
                if (A & 1) continue;
                A /= 2;
                if ((A + b) & 1) continue;
                if (c0 == c1) ans += C2(F[c0]);
                else ans += F[c0] * F[c1];
            }
        }
    }

    cout << ans << '\n';
	return 0;
}