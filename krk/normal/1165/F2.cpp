#include <bits/stdc++.h>
using namespace std;

const int Maxm = 400005;

int n, m;
int A[Maxm], B[Maxm];
vector <int> my[Maxm];

bool Okay(int d)
{
    fill(B, B + Maxm, 0);
    int b = 0;
    int has = d;
    for (int i = d; i > 0; i--) {
        has = min(has, i);
        for (int j = 0; j < my[i].size(); j++) {
            int ind = my[i][j];
            int tk = min(has, A[ind] - B[ind]);
            b += tk; has -= tk; B[ind] += tk;
        }
    }
    int lft = d - b;
    for (int i = 0; i < n; i++)
        lft -= 2 * (A[i] - B[i]);
    return lft >= 0;
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);
    for (int i = 0; i < m; i++) {
        int d, t; scanf("%d %d", &d, &t); t--;
        my[d].push_back(t);
    }
    int lef = 0, rig = Maxm - 1;
    while (lef <= rig) {
        int mid = lef + rig >> 1;
        if (Okay(mid)) rig = mid - 1;
        else lef = mid + 1;
    }
    printf("%d\n", rig + 1);
    return 0;
}