#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int N, M; cin >> N >> M;
    vector<string> S(N); 
    for (string&s:S) cin >> s;
    int ans = 0;
    int cnt = 0;
    vector<vector<int>> Left(N, vector<int>(M, -1));
    vector<vector<int>> Right(N, vector<int>(M, M));
    vector<vector<int>> Down(N, vector<int>(M, N));
    vector<vector<int>> Up(N, vector<int>(M, -1));
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < M; ++c) {
            if (S[r][c] == '.') { continue; }
            for (int i = 0; i < N; ++i) {
                int prev = -1;
                for (int j = 0; j < M; ++j) {
                    if (S[i][j] != '.') {
                        Left[i][j] = prev;
                        prev = j;
                    }
                }
            }

            for (int i = 0; i < N; ++i) {
                int prev = M;
                for (int j = M-1; j >= 0; --j) {
                    if (S[i][j] != '.') {
                        Right[i][j] = prev;
                        prev = j;
                    }
                }
            }
            
            for (int j = 0; j < M; ++j) {
                int prev = -1;
                for (int i = 0; i < N; ++i) {
                    if (S[i][j] != '.') {
                        Up[i][j] = prev;
                        prev = i;
                    }
                }
            }

            for (int j = 0; j < M; ++j) {
                int prev = N;
                for (int i = N-1; i >= 0; --i) {
                    if (S[i][j] != '.') {
                        Down[i][j] = prev;
                        prev = i;
                    }
                }
            }



            int len = 0;
            int a = r, b = c;
            while (0 <= a && a < N && 0 <= b && b < M) {
                len++;
                int l = Left[a][b];
                int r = Right[a][b];
                int u = Up[a][b];
                int d = Down[a][b];
                if (l != -1) Right[a][l] = r;
                if (r != M) Left[a][r] = l;
                if (u != -1) Down[u][b] = d;
                if (d != N) Up[d][b] = u;
                if (S[a][b] == 'L') b = l;
                else if (S[a][b] == 'R') b = r;
                else if (S[a][b] == 'U') a = u;
                else if (S[a][b] == 'D') a = d;
            }
            if (len > ans) { ans = len; cnt = 1; }
            else if (len == ans) cnt++;
        }
    }
    cout << ans << ' ' << cnt << endl;
}