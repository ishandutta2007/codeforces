#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int N; cin >> N;
    vector<string> S(N);
    for (auto&s:S) cin >> s;
    for (int x = 0; x < N; ++x) {
        for (int y = 0; y < N; ++y) {
            bool even = true;
            even ^= x>0&&S[x-1][y] == 'o';
            even ^= x<N-1&&S[x+1][y] == 'o';
            even ^= y>0&&S[x][y-1] == 'o';
            even ^= y<N-1&&S[x][y+1] == 'o';
            if (!even) {
                cout << "NO\n";
                return 0;
            }
        }
    }
    cout << "YES\n";
}