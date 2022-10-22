#include <bits/stdc++.h>
using namespace std;

const int Maxn = 2005;

int T;
int n;
bool spec[Maxn];

vector <int> Construct(int l, int r)
{
    vector <int> res(r - l + 1);
    for (int i = 0; i < res.size(); i++)
        res[i] = i + l;
    return res;
}

int Ask(const vector <int> &A, const vector <int> &B)
{
    printf("? %d %d\n", int(A.size()), int(B.size()));
    for (int i = 0; i < A.size(); i++)
        printf("%d%c", A[i], i + 1 < A.size()? ' ': '\n');
    for (int i = 0; i < B.size(); i++)
        printf("%d%c", B[i], i + 1 < B.size()? ' ': '\n');
    fflush(stdout);
    int res; scanf("%d", &res);
    return res;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int pnt = 1;
        int g;
        while (pnt < n) {
            g = Ask(Construct(pnt, pnt), Construct(pnt + 1, n));
            if (g) break;
            spec[pnt] = false;
            pnt++;
        }
        spec[pnt] = true;
        for (int i = pnt + 1; i < n; i++) {
            int cur = Ask(Construct(pnt, pnt), Construct(i, i));
            g -= cur;
            spec[i] = cur;
        }
        spec[n] = g;
        int lef = 1, rig = pnt - 1;
        while (lef <= rig) {
            int mid = lef + rig >> 1;
            if (Ask(Construct(1, mid), Construct(pnt, pnt))) rig = mid - 1;
            else lef = mid + 1;
        }
        spec[lef] = true;
        vector <int> res;
        for (int i = 1; i <= n; i++) if (!spec[i])
            res.push_back(i);
        printf("! %d", int(res.size()));
        for (int i = 0; i < res.size(); i++)
            printf(" %d", res[i]);
        printf("\n"); fflush(stdout);
    }
    return 0;
}