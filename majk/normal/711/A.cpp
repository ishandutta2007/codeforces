#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int N; cin >> N;
    vector<string> S(N);
    for (string&s:S) cin >> s;
    bool ans = false;
    for (int i = 0; i < N; ++i) {
        if (!ans && S[i][0] == 'O' && S[i][1] == 'O') {
            S[i][0] = '+';
            S[i][1] = '+';
            ans = true;
        }
        if (!ans && S[i][3] == 'O' && S[i][4] == 'O') {
            S[i][3] = '+';
            S[i][4] = '+';
            ans = true;
        }
    }

    if (ans) {
        cout << "YES\n";
        for (string &s:S) cout << s << '\n';
    } else {
        cout << "NO\n";
    }
}