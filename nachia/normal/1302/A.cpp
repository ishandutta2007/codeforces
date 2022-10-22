#include<bits/stdc++.h>
using namespace std;
using UL = unsigned long;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

    void Loop() {
        UL N; cin >> N;
        vector<pair<UL, UL>> C;
        {
            UL buf = N;
            for (UL i = 2; i * i <= buf; i++) {
                if (buf % i == 0) {
                    C.push_back({ i, 0 });
                    while (buf % i == 0) {
                        C.back().second++;
                        buf /= i;
                    }
                }
            }
            if (buf != 1) C.push_back({ buf, 1 });
        }

        for (auto c : C) {
            if (c.second >= 3) {
                UL a[3] = { c.first , (c.first * c.first), N / (c.first * c.first * c.first) };
                if (a[2] == 1 || a[2] == a[0] || a[2] == a[1]) {
                    cout << "NO" << endl; return;
                }
                cout << "YES" << endl;
                cout << a[0] << " " << a[1] << " " << a[2] << endl;
                return;
            }
        }
        if (C.size() == 1) { cout << "NO" << endl; return; }
        if (C.size() == 2) {
            if (C[0].second + C[1].second != 4) { cout << "NO" << endl; return; }
            cout << "YES" << endl;
            cout << C[0].first << " " << C[1].first << " " <<
                C[0].first * C[1].first << endl;
            return;
        }
        cout << "YES" << endl;
        cout << C[0].first << " " << C[1].first << " " <<
            (N / C[0].first / C[1].first) << endl;
    }

    void Solve() {
        UL T; cin >> T;
        while (T--) Loop();
    }
};
int main() {
    unique_ptr<Problem> p(new Problem());
    cout << fixed << setprecision(10);
    p->Solve();
    return 0;
}