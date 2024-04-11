#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;

int T;
int n, x, y;
priority_queue <ii> Q;
vector <int> inds[Maxn];
int oth;
int A[Maxn], B[Maxn];

bool Solve()
{
    while (x--) {
        ii p = Q.top(); Q.pop();
        B[inds[p.second].back()] = p.second;
        inds[p.second].pop_back();
        if (--p.first > 0)
            Q.push(p);
    }
    if (Q.empty()) return true;
    vector <int> seq;
    for (int i = 1; i <= n + 1; i++)
        for (int j = 0; j < inds[i].size(); j++)
            seq.push_back(inds[i][j]);
    ii p = Q.top();
    int has = n - y;
    if (max(2 * p.first - int(seq.size()), 0) > has) return false;
    for (int i = 0; i < seq.size(); i++) {
        int ni = (i + p.first) % int(seq.size());
        B[seq[ni]] = A[seq[i]];
    }
    for (int i = 0; i < seq.size(); i++)
        if (A[seq[i]] == B[seq[i]]) {
            B[seq[i]] = oth;
            has--;
        }
    for (int i = 0; i < seq.size(); i++)
        if (B[seq[i]] != oth && has > 0) {
            B[seq[i]] = oth; has--;
        }
    return true;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &n, &x, &y);
        while (!Q.empty()) Q.pop();
        for (int i = 1; i <= n + 1; i++)
            inds[i].clear();
        for (int i = 1; i <= n; i++) {
            scanf("%d", &A[i]);
            inds[A[i]].push_back(i);
        }
        for (int i = 1; i <= n + 1; i++)
            if (inds[i].empty()) oth = i;
            else Q.push(ii(int(inds[i].size()), i));
        if (Solve()) {
            printf("YES\n");
            for (int i = 1; i <= n; i++)
                printf("%d%c", B[i], i + 1 <= n? ' ': '\n');
        } else printf("NO\n");
    }
    return 0;
}