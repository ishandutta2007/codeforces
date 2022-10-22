#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef pair <ii, int> iii;

const int Inf = 1000000000;
const int Maxn = 100005;
const int Maxm = 20;

int n;
ii A[Maxn], B[Maxn];
vector <iii> seq;
int L[Maxn][Maxm], R[Maxn][Maxm];

bool Less(const iii &a, const iii &b)
{
    return a.first.second < b.first.second;
}

ii Get(int ind, int en)
{
    ii res = ii(Inf, -Inf);
    for (int i = Maxm - 1; i >= 0; i--) if (1 << i <= ind)
        if (en <= seq[ind - (1 << i)].first.second) {
            res.first = min(res.first, L[ind - (1 << i) + 1][i]);
            res.second = max(res.second, R[ind - (1 << i) + 1][i]);
            ind -= 1 << i;
        }
    res.first = min(res.first, L[ind][0]);
    res.second = max(res.second, R[ind][0]);
    return res;
}

bool Solve()
{
    seq.clear();
    for (int i = 0; i < n; i++)
        seq.push_back(iii(A[i], i));
    sort(seq.begin(), seq.end(), Less);
    for (int i = 0; i < n; i++) {
        int ind = seq[i].second;
        L[i][0] = B[ind].second;
        R[i][0] = B[ind].first;
    }
    for (int j = 1; j < Maxm; j++)
        for (int i = 0; i + (1 << j) <= n; i++) {
            int ni = i + (1 << j - 1);
            L[i][j] = min(L[i][j - 1], L[ni][j - 1]);
            R[i][j] = max(R[i][j - 1], R[ni][j - 1]);
        }
    for (int i = 0; i < n; i++) {
        int ind = seq[i].second;
        ii g = Get(i, A[ind].first);
        if (B[ind].first <= g.first && g.second <= B[ind].second) ;
        else return true;
    }
    return false;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d %d %d %d", &A[i].first, &A[i].second, &B[i].first, &B[i].second);
    if (Solve()) { printf("NO\n"); return 0; }
    for (int i = 0; i < n; i++)
        swap(A[i], B[i]);
    if (Solve()) { printf("NO\n"); return 0; }
    printf("YES\n");
    return 0;
}