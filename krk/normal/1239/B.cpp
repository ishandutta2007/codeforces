#include <bits/stdc++.h>
using namespace std;

const int Maxn = 300005;

int n;
char str[Maxn];
int st[Maxn];
int mn;
int A[Maxn], B[Maxn], C[Maxn];
int best, bi, bj;

int Get(int X[], int l, int r)
{
    if (r < 0) return 0;
    int res = X[r];
    if (l > 0) res -= X[l - 1];
    return res;
}

int main()
{
    scanf("%d", &n);
    scanf("%s", str);
    for (int i = 0; i < n; i++) {
        st[i] = str[i] == '('? 1: -1;
        if (i) st[i] += st[i - 1];
    }
    if (st[n - 1] != 0) {
        printf("0\n");
        printf("1 1\n");
        return 0;
    }
    mn = Maxn;
    for (int i = 0; i < n; i++)
        mn = min(mn, st[i]);
    for (int i = 0; i < n; i++) {
        A[i] = mn == st[i];
        B[i] = mn + 1 == st[i];
        C[i] = mn + 2 == st[i];
        if (i) {
            A[i] += A[i - 1];
            B[i] += B[i - 1];
            C[i] += C[i - 1];
        }
    }
    best = A[n - 1];
    bi = bj = 0;
    // mn -> mn + 2, targ = mn + 1
    int l = 0;
    while (st[l] != mn) l++;
    int r = n - 1;
    while (st[r] != mn) r--;
    r++;
    if (r < n) {
        int got = B[n - 1] - Get(B, l, r - 1);
        if (got > best) {
            best = got;
            bi = l; bj = r;
        }
    }
    // mn -> mn + 2, targ = mn + 2
    l = 0;
    while (st[l] != mn && st[l] != mn + 1) l++;
    r = n - 1;
    while (st[r] != mn && st[r] != mn + 1) r--;
    r++;
    if (r < n) {
        int got = C[n - 1] - Get(C, l, r - 1) + A[n - 1];
        if (got > best) {
            best = got;
            bi = l; bj = r;
        }
    }
    // mn + 1 -> mn - 1
    l = 0, r = 0;
    while (l < n && r < n)
        if (str[l] == ')') l++;
        else if (r <= l || str[r] == '(') r++;
        else if (Get(A, l, r - 1) > 0) l++;
        else {
            int got = Get(B, l, r - 1);
            if (got > best) {
                best = got;
                bi = l; bj = r;
            }
            r++;
        }
    // mn + 2 -> mn
    l = 0, r = 0;
    while (l < n && r < n)
        if (str[l] == ')') l++;
        else if (r <= l && str[r] == '(') r++;
        else if (Get(A, l, r - 1) > 0 || Get(B, l, r - 1) > 0) l++;
        else {
            int got = Get(C, l, r - 1) + A[n - 1];
            if (got > best) {
                best = got;
                bi = l; bj = r;
            }
            r++;
        }
    printf("%d\n", best);
    printf("%d %d\n", bi + 1, bj + 1);
    return 0;
}