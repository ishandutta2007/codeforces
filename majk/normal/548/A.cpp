#include <iostream>
#include <vector>

using namespace std;

int main() {
    string S; cin >> S;
    int K; cin >> K;
    int N = S.size();
    if (N%K) { cout << "NO\n"; return 0; }
    for (int i = 0; i < N; i += N/K) {
        for (int j = 0; j < N/K; ++j) {
            if (S[i+j] != S[i+N/K-j-1]) {
                cout << "NO\n"; return 0;
            }
        }
    }
    cout << "YES\n";
}