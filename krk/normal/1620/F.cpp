#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 1000005;
const int Inf = 1000000000;

int T;
int n;
int p[Maxn];
int L[Maxn], R[Maxn];
int seq[Maxn], slen;
int root;
vector <ii> fromlef[Maxn], fromrig[Maxn];
vector <ii> mylef[Maxn], myrig[Maxn];
int res[Maxn];

vector <ii> joinLeft(const vector <ii> &A, const vector <ii> &B)
{
    vector <ii> C;
    for (int i = 0; i < A.size(); i++) {
        int pnt = 0;
        while (pnt < B.size() && A[i].second > B[pnt].first) pnt++;
        int got = pnt < B.size()? B[pnt].second: Inf;
        C.push_back(ii(A[i].first, got));
    }
    return C;
}

int nextLeft(int cur, const vector <ii> &A)
{
    if (A.empty()) return cur;
    if (cur < A[0].first) return A[0].second;
    if (cur < A[1].first) return A[1].second;
    return Inf;
}

vector <ii> joinRight(const vector <ii> &A, const vector <ii> &B)
{
    vector <ii> C;
    for (int i = 0; i < B.size(); i++) {
        int pnt = 0;
        while (pnt < A.size() && B[i].second < A[pnt].first) pnt++;
        int got = pnt < A.size()? A[pnt].second: -Inf;
        C.push_back(ii(B[i].first, got));
    }
    return C;
}

int nextRight(int cur, const vector <ii> &A)
{
    if (A.empty()) return cur;
    if (cur > A[0].first) return A[0].second;
    if (cur > A[1].first) return A[1].second;
    return -Inf;
}

void Left(int v)
{
    mylef[v].clear();
    mylef[v].push_back(ii(-p[v], -p[v]));
    mylef[v].push_back(ii(p[v], p[v]));
    fromlef[v] = mylef[v];
    if (L[v]) {
        Left(L[v]);
        fromlef[v] = joinLeft(fromlef[L[v]], fromlef[v]);
    }
    if (R[v]) {
        Left(R[v]);
        fromlef[v] = joinLeft(fromlef[v], fromlef[R[v]]);
    }
}

void Right(int v)
{
    myrig[v].clear();
    myrig[v].push_back(ii(p[v], p[v]));
    myrig[v].push_back(ii(-p[v], -p[v]));
    fromrig[v] = myrig[v];
    if (R[v]) {
        Right(R[v]);
        fromrig[v] = joinRight(fromrig[v], fromrig[R[v]]);
    }
    if (L[v]) {
        Right(L[v]);
        fromrig[v] = joinRight(fromrig[L[v]], fromrig[v]);
    }
}

void writeLeft(int v, int &cur)
{
    if (v == 0) return;
    writeLeft(L[v], cur);
    res[v] = cur = nextLeft(cur, mylef[v]);
    writeLeft(R[v], cur);
}

void writeRight(int v, int &cur)
{
    if (v == 0) return;
    writeRight(R[v], cur);
    res[v] = cur = nextRight(cur, myrig[v]);
    writeRight(L[v], cur);
}

bool Solve(int v, int mx, int mn)
{
    if (mx >= Inf || mn <= -Inf) return false;
    if (v == 0) return true;
    if ((mx < p[v] || p[v] < nextRight(mn, fromrig[R[v]])) && Solve(L[v], mx, min(p[v], nextRight(mn, fromrig[R[v]])))) {
        writeRight(R[v], mn);
        res[v] = p[v];
        return true;
    }
    if ((nextLeft(mx, fromlef[L[v]]) < -p[v] || -p[v] < mn) && Solve(R[v], max(-p[v], nextLeft(mx, fromlef[L[v]])), mn)) {
        writeLeft(L[v], mx);
        res[v] = -p[v];
        return true;
    }
    return false;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &p[i]);
        fill(L + 1, L + n + 1, 0);
        fill(R + 1, R + n + 1, 0);
        slen = 0;
        seq[slen++] = 1;
        for (int i = 2; i <= n; i++) {
            while (slen >= 2 && p[i] > p[seq[slen - 2]]) {
                R[seq[slen - 2]] = seq[slen - 1];
                slen--;
            }
            if (slen > 0 && p[i] > p[seq[slen - 1]]) {
                L[i] = seq[slen - 1];
                slen--;
            }
            seq[slen++] = i;
        }
        while (slen >= 2) {
            R[seq[slen - 2]] = seq[slen - 1];
            slen--;
        }
        root = seq[0];
        Left(root);
        Right(root);
        if (Solve(root, -Inf, Inf)) {
            printf("YES\n");
            for (int i = 1; i <= n; i++)
                printf("%d%c", res[i], i + 1 <= n? ' ': '\n');
        } else printf("NO\n");
    }
    return 0;
}