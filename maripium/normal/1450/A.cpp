#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        string S; cin >> S;
        sort(S.rbegin(), S.rend());
        cout << S << '\n';
    }
}