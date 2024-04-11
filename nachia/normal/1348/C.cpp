#include <algorithm>
#include <iostream>
using namespace std;
using UL = unsigned int;
#define rep(i, n) for(UL i = 0; i < (n); i++)

int main() {
    UL T; cin >> T;
    while (T--) {
        UL N, K; cin >> N >> K;
        string S; cin >> S;
        sort(S.begin(), S.end());
        if (N == K) { cout << S.back() << endl; continue; }
        if (K == 1) { cout << S << endl; continue; }
        if (S[K - 1] != S[0]) { cout << S[K - 1] << endl; continue; }
        if (S[K] != S.back()) { cout << S.substr(K - 1) << endl; continue; }
        for (UL i = 0; i < N; i += K) cout << S[i]; cout << endl;
    }
    return 0;
}