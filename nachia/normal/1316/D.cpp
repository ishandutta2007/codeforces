#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem{
    UL N;
    char C[1001][1001] = {};
    pair<int, int> A[1000][1000];
    bool F[1000][1000] = {};

    void Solve() {
        scanf("%d", &N);
        rep(y, N) rep(x, N) {
            scanf("%d%d", &A[x][y].second, &A[x][y].first);
            A[x][y].first--; A[x][y].second--;
        }

        const auto lp = make_pair(-2, -2);

        queue<pair<int, int>> Q;
        rep(x, N) rep(y, N) {
            if (A[x][y] == make_pair((int)x, (int)y)) {
                C[x][y] = 'X'; Q.push(make_pair((int)x, (int)y));
                F[x][y] = true;
            }
            if (A[x][y] == lp) {
                if (x != 0) if (A[x - 1][y] == lp) C[x][y] = 'L';
                if (x != N - 1) if (A[x + 1][y] == lp) C[x][y] = 'R';
                if (y != 0) if (A[x][y - 1] == lp) C[x][y] = 'U';
                if (y != N - 1) if (A[x][y + 1] == lp) C[x][y] = 'D';
                if (C[x][y] == 0) { printf("INVALID\n"); return; }
                F[x][y] = true;
            }
        }
        while (Q.size()) {
            int x = Q.front().first, y = Q.front().second; Q.pop();
            if (x != 0) if (!F[x - 1][y]) if (A[x - 1][y] == A[x][y]) {
                C[x - 1][y] = 'R'; Q.push(make_pair(x - 1, y));
                F[x - 1][y] = true;
            }
            if (x != N - 1) if (!F[x + 1][y]) if (A[x + 1][y] == A[x][y]) {
                C[x + 1][y] = 'L'; Q.push(make_pair(x + 1, y));
                F[x + 1][y] = true;
            }
            if (y != 0) if (!F[x][y - 1]) if (A[x][y - 1] == A[x][y]) {
                C[x][y - 1] = 'D'; Q.push(make_pair(x, y - 1));
                F[x][y - 1] = true;
            }
            if (y != N - 1) if (!F[x][y + 1]) if (A[x][y + 1] == A[x][y]) {
                C[x][y + 1] = 'U'; Q.push(make_pair(x, y + 1));
                F[x][y + 1] = true;
            }
        }
        rep(x, N) rep(y, N) if (!F[x][y]) { printf("INVALID\n"); return; }
        printf("VALID\n");
        rep(y, N) {
            rep(x, N) printf("%c", C[x][y]);
            printf("\n");
        }
    }
};
int main() {
    unique_ptr<Problem> p(new Problem());
    p->Solve();
    return 0;
}