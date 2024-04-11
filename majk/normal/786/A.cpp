#include <iostream>
#include <vector>

using namespace std;

typedef pair<int,int> pii;
#define x first
#define y second

int main() {
    int N; cin >> N;
    vector<vector<int>> S(2);
    
    int K1; cin >> K1;
    S[0].resize(K1);
    for (int&s:S[0]) cin >> s;
    int K2; cin >> K2;
    S[1].resize(K2);
    for (int&s:S[1]) cin >> s;

    vector<vector<int>> A(2, vector<int>(N, 2));
    vector<vector<int>> W{vector<int>(N, K1), vector<int>(N, K2)};
    vector<pii> Q{{0,0},{1,0}};
    A[0][0] = 0;
    A[1][0] = 0;
    for (int q = 0; q < Q.size(); ++q) {
        pii u = Q[q];
        if (A[u.x][u.y] == 1) {
            for (int s:S[!u.x]) {
                int d = (N+u.y-s)%N;
                if (A[!u.x][d] == 2 && !--W[!u.x][d]) {
                    A[!u.x][d] = 0;
                    Q.push_back({!u.x,d});
                }
            }
        } else {
            for (int s:S[!u.x]) {
                int d = (N+u.y-s)%N;
                if (A[!u.x][d] == 2) {
                    A[!u.x][d] = 1;
                    Q.push_back({!u.x,d});
                }
            }
        }
    }

    vector<string> Ans{"Lose", "Win", "Loop"};
    for (int i = 0; i < 2; ++i) {
        for (int j = 1; j < N; ++j) {
            cout << Ans[A[i][j]] << " \n"[j==N-1];
        }
    }
}