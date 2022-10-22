#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 1005;
const int Inf = 1000000000;

int n;
int a[Maxn];
int b[Maxn];

void Solve(int &cur, int l, int r)
{
    if (cur < r) {
        printf("A");
        while (cur + 1 < r) {
            printf("R"); cur++;
            printf("A");
        }
    }
    while (cur > l - 2) {
        printf("L"); cur--;
    }
    printf("A");
}

void prepareB(int i)
{
    for (int j = 1; j <= n; j++)
        b[j] = j < i? a[j]: max(a[j] - 1, 0);
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    while (a[n] == 0) n--;
    int res = Inf, wth = 0;
    for (int i = 1; i <= n; i++) {
        int cand = 3 * n - i + 3;
        prepareB(i);
        int st = 0;
        for (int j = 1; j <= n; j++) {
            cand += 3 * b[j];
            cand += abs(st - b[j]);
            st = b[j];
        }
        cand += abs(st);
        if (cand < res) {
            res = cand;
            wth = i;
        }
    }
    prepareB(wth);
    vector <int> L, R;
    int st = 0;
    for (int j = 1; j <= n; j++) {
        while (st < b[j]) {
            L.push_back(j);
            st++;
        }
        while (st > b[j]) {
            R.push_back(j - 1);
            st--;
        }
    }
    while (st > 0) {
        R.push_back(n);
        st--;
    }
    int pnt = 0;
    int cur = -1;
    while (cur + 1 < n) {
        while (pnt < L.size() && L[pnt] - 2 == cur) {
            Solve(cur, L[pnt], R[pnt]);
            pnt++;
        }
        printf("AR");
        cur++;
    }
    printf("A");
    while (cur > wth - 2) {
        printf("L");
        cur--;
    }
    printf("A\n");
    return 0;
}