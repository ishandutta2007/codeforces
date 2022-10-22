#include<bits/stdc++.h>
using namespace std;
using UL = unsigned long;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

    void Solve() {
        UL N, K; cin >> N >> K;
        vector<UL> output(K + 1);
        rep(i, K + 1) {
            cout << "?";
            rep(j, K + 1) if (i != j) cout << " " << (j + 1);
            cout << endl;
            UL res; cin >> res >> output[i];
        }
        sort(output.begin(), output.end());
        UL ans = 0;
        rep(i, K) if (output[i] != output[i + 1]) ans = K - i;
        cout << "! " << ans << endl;
    }
};
int main() {
    unique_ptr<Problem> p(new Problem());
    cout << fixed << setprecision(10);
    p->Solve();
    return 0;
}