#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int n, tmp;
vector <int> A;
int m;
vector <int> B;
int res;

void Solve(const vector <int> &A, const vector <int> &B)
{
    if (A.empty() || B.empty()) return;
    if (A.size() == 1 && B.size() == 1) { res = max(res, 2); return; }
    int sta = 0, stb = 0;
    vector <int> eA, eB;
    vector <int> oA, oB;
    for (int i = 0; i < A.size(); i++)
        if (A[i] % 2) { sta++; oA.push_back(A[i] / 2); }
        else { stb++; eA.push_back(A[i] / 2); }
    for (int i = 0; i < B.size(); i++)
        if (B[i] % 2) { stb++; oB.push_back(B[i] / 2); }
        else { sta++; eB.push_back(B[i] / 2); }
    res = max(res, max(sta, stb));
    Solve(eA, eB); Solve(oA, oB);
}

int main()
{
    scanf("%d %d", &n, &tmp);
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        A.push_back(a);
    }
    scanf("%d %d", &m, &tmp);
    for (int i = 0; i < m; i++) {
        int a; scanf("%d", &a);
        B.push_back(a);
    }
    Solve(A, B);
    printf("%d\n", res);
    return 0;
}