#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1002;
const int Maxm = 500005;

int T;
vector <int> H, V;
vector <int> A, B, C, D;
bool dp[Maxn][Maxm];
int len[Maxn];

void Read(vector <int> &seq)
{
    int cnt; scanf("%d", &cnt);
    seq.resize(cnt);
    for (int i = 0; i < seq.size(); i++)
        scanf("%d", &seq[i]);
}

bool Solve(vector <int> &seq, vector <int> &res1, vector <int> &res2)
{
    sort(seq.begin(), seq.end());
    int sum = 0;
    for (int i = 0; i < seq.size(); i++)
        sum += seq[i];
    if (sum % 2) return false;
    res1.clear(); res2.clear();
    sum /= 2;
    dp[0][0] = true; len[0] = 0;
    for (int i = 0; i < seq.size(); i++) {
        len[i + 1] = min(sum, len[i] + seq[i]);
        for (int j = 0; j <= len[i + 1]; j++)
            dp[i + 1][j] = j <= len[i] && dp[i][j] || seq[i] <= j && dp[i][j - seq[i]];
    }
    int curj = sum;
    if (!dp[seq.size()][curj]) return false;
    for (int i = int(seq.size()) - 1; i >= 0; i--)
        if (seq[i] <= curj && dp[i][curj - seq[i]]) {
            res1.push_back(seq[i]);
            curj -= seq[i];
        } else res2.push_back(seq[i]);
    return true;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        Read(H);
        Read(V);
        if (H.size() != V.size()) { printf("No\n"); continue; }
        if (Solve(H, A, B) && Solve(V, C, D)) {
            if (A.size() < B.size()) swap(A, B);
            if (C.size() > D.size()) swap(C, D);
            sort(A.begin(), A.end());
            sort(B.rbegin(), B.rend());
            sort(C.rbegin(), C.rend());
            sort(D.begin(), D.end());
            printf("Yes\n");
            int curx = 0, cury = 0;
            int tk1 = min(A.size(), C.size());
            int tk2 = min(B.size(), D.size());
            for (int i = 0; i < tk1; i++) {
                cury += C[i];
                printf("%d %d\n", curx, cury);
                curx += A[i];
                printf("%d %d\n", curx, cury);
            }
            for (int i = 0; i < D.size() - tk2; i++) {
                cury -= D[tk2 + i];
                printf("%d %d\n", curx, cury);
                curx += A[tk1 + i];
                printf("%d %d\n", curx, cury);
            }
            for (int i = tk2 - 1; i >= 0; i--) {
                cury -= D[i];
                printf("%d %d\n", curx, cury);
                curx -= B[i];
                printf("%d %d\n", curx, cury);
            }
            continue;
        }
        printf("No\n");
    }
    return 0;
}