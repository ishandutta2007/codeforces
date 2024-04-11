#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 2005;

int n, m;
int P[Maxn];
vector <ii> pw;
int A[Maxn], B[Maxn];
int mypar[Maxn];
bool tk[Maxn];
int t;
int lft;

int Get()
{
    int x; scanf("%d", &x);
    tk[x] = true;
    return x;
}

void Select(int ind)
{
    tk[ind] = true;
    printf("%d\n", ind); fflush(stdout);
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= 2 * n; i++) {
        scanf("%d", &P[i]);
        pw.push_back(ii(P[i], i));
    }
    sort(pw.rbegin(), pw.rend());
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &A[i], &B[i]);
        if (P[A[i]] < P[B[i]]) swap(A[i], B[i]);
        mypar[A[i]] = B[i];
        mypar[B[i]] = A[i];
    }
    scanf("%d", &t);
    lft = 2 * n;
    int lst = 0;
    while (lft--) {
        if (t == 1) {
            bool made = false;
            if (mypar[lst] != 0) {
                int x = mypar[lst];
                if (!tk[x]) {
                    Select(x);
                    made = true;
                }
            }
            for (int i = 1; i <= m && !made; i++)
                if (!tk[A[i]]) {
                    Select(A[i]);
                    made = true;
                }
            for (int i = 0; i < pw.size() && !made; i++)
                if (!tk[pw[i].second]) {
                    Select(pw[i].second);
                    made = true;
                }
        } else lst = Get();
        t = 3 - t;
    }
    return 0;
}