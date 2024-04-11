#include <iostream>
#include <string>

using namespace std;

int main() {
    int N, Q; cin >> N >> Q;
    string S; cin >> S;
    int C = 0;
    for (int i = 0; i < N-1; ++i) C += S[i]=='.' && S[i+1]=='.';
    for (int i = 0; i < Q; ++i) {
        int x; char c; cin >> x >> c;
        --x;
        C -= x>0 && S[x] == '.' && S[x-1] == '.';
        C -= x != N-1 && S[x] == '.' && S[x+1] == '.';
        S[x] = c;
        C += x>0 && S[x] == '.' && S[x-1] == '.';
        C += x != N-1 && S[x] == '.' && S[x+1] == '.';
        cout << C << '\n';
    }
}