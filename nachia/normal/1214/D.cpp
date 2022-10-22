#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

    bool C[1000000] = {};
    bool rC[1000000] = {};
    bool G[1000000];
    UL S[1000000] = {};

    void Solve() {
        UL H, W; cin >> H >> W;
        rep(i, H * W) {
            char c; cin >> c;
            G[i] = c == '.';
        }
        C[0] = rC[H * W - 1] = 1;
        for (UL i = 1; i < H * W; i++) {
            if (i % W) if (G[i - 1]) C[i] = C[i] || C[i - 1];
            if (i >= W) if (G[i - W]) C[i] = C[i] || C[i - W];
        }
        if (!C[H * W - 1]) { cout << 0 << endl; return; }
        for (UL i = H * W - 1; i != 0; i--) {
            if (i % W) if (G[i - 1]) rC[i - 1] = rC[i] || rC[i - 1];
            if (i >= W) if (G[i - W]) rC[i - W] = rC[i] || rC[i - W];
        }
        UL i = 0;
        rep(y, H) rep(x, W) {
            if (C[i]) if (rC[i]) S[x + y]++;
            i++;
        }
        for (UL j = 1; j < H + W - 2; j++) {
            if (S[j] == 1) { cout << 1 << endl; return; }
        }
        cout << 2 << endl;
    }
};
int main() {
    unique_ptr<Problem> p(new Problem());
    //cout << fixed << setprecision(10);
    p->Solve();
    return 0;
}