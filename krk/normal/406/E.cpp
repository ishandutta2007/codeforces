#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m;
int best;
ll ways;
vector <int> V[2];

void Update(int val, ll myways)
{
    if (val > best) { best = val; ways = 0; }
    if (val == best) ways += myways;
}

void Take3(const vector <int> &V)
{
    if (V.empty()) return;
    int fir = 1;
    while (fir < V.size() && V[fir] == V[0]) fir++;
    if (fir == V.size()) { Update(0, ll(fir) * (fir - 1) * (fir - 2) / 6); return; }
    int lst = 1;
    while (lst < V.size() && V.back() == V[int(V.size()) - 1 - lst]) lst++;
    Update(V.back() - V[0], ll(fir) * (fir - 1) / 2 * lst);
    Update(V.back() - V[0], ll(fir) * lst * (lst - 1) / 2);
    Update(V.back() - V[0], ll(fir) * lst * (int(V.size()) - fir - lst));
}

void Take1and2(const vector <int> &A, const vector <int> &B)
{
    int pnt = B.size();
    int sam = 0;
    for (int i = int(A.size()) - 1; i >= 0; i--) {
        while (pnt - 1 >= 0 && A[i] <= B[pnt - 1]) {
            pnt--;
            if (pnt + 1 >= B.size() || B[pnt] != B[pnt + 1]) sam = 1;
            else sam++;
        }
        if (sam > 0) {
            Update(A[i] + n - B[pnt], ll(sam) * (sam - 1) / 2 + ll(sam) * (int(B.size()) - pnt - sam));
            if (pnt > 0) Update(n, ll(int(B.size()) - pnt) * pnt);
        }
    }
    pnt = -1;
    sam = 0;
    for (int i = 0; i < A.size(); i++) {
        while (pnt + 1 < B.size() && B[pnt + 1] < A[i]) {
            pnt++;
            if (pnt == 0 || B[pnt] != B[pnt - 1]) sam = 1;
            else sam++;
        }
        if (sam > 0)
            Update(n - (A[i] - B[pnt]), ll(sam) * (sam - 1) / 2 + ll(sam) * (pnt + 1 - sam));
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int s, f; scanf("%d %d", &s, &f);
        V[s].push_back(f);
    }
    sort(V[0].begin(), V[0].end());
    sort(V[1].begin(), V[1].end());
    Take3(V[0]);
    Take3(V[1]);
    Take1and2(V[0], V[1]);
    Take1and2(V[1], V[0]);
    printf("%I64d\n", ways);
    return 0;
}