#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;
const ll Inf = 4000000000000000000ll;

int T;
int n[3];
vector <int> V[3];
ll res;

void Solve(const vector <int> &A, const vector <int> &B, const vector <int> &C)
{
    for (int i = 0; i < A.size(); i++) {
        int ind = lower_bound(B.begin(), B.end(), A[i]) - B.begin();
        vector <int> seq1;
        if (ind < B.size()) seq1.push_back(B[ind]);
        if (ind > 0) seq1.push_back(B[ind - 1]);
        ind = lower_bound(C.begin(), C.end(), A[i]) - C.begin();
        vector <int> seq2;
        if (ind < C.size()) seq2.push_back(C[ind]);
        if (ind > 0) seq2.push_back(C[ind - 1]);
        for (int a = 0; a < seq1.size(); a++)
            for (int b = 0; b < seq2.size(); b++)
                res = min(res, ll(A[i] - seq1[a]) * (A[i] - seq1[a]) +
                               ll(A[i] - seq2[b]) * (A[i] - seq2[b]) +
                               ll(seq1[a] - seq2[b]) * (seq1[a] - seq2[b]));
    }
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &n[0], &n[1], &n[2]);
        for (int i = 0; i < 3; i++) {
            V[i].resize(n[i]);
            for (int j = 0; j < n[i]; j++)
                scanf("%d", &V[i][j]);
            sort(V[i].begin(), V[i].end());
        }
        res = Inf;
        Solve(V[0], V[1], V[2]);
        Solve(V[1], V[0], V[2]);
        Solve(V[2], V[0], V[1]);
        printf("%I64d\n", res);
    }
    return 0;
}