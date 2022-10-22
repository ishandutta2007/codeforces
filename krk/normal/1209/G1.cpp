#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int n, q;
int a[Maxn];
vector <int> inds[Maxn];
int delt[Maxn];
map <int, int> M;
int res;

int main()
{
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        inds[a[i]].push_back(i);
    }
    for (int i = 0; i < Maxn; i++) if (!inds[i].empty()) {
        delt[inds[i][0]]++;
        delt[inds[i].back()]--;
    }
    int lst = -1, cur = 0;
    for (int i = 0; i < n; i++) {
        cur += delt[i];
        if (cur == 0) {
            M.clear();
            while (lst < i) {
                lst++;
                M[a[lst]]++;
            }
            int mx = 0;
            for (map <int, int>::iterator it = M.begin(); it != M.end(); it++)
                mx = max(mx, it->second);
            res += mx;
        }
    }
    printf("%d\n", n - res);
    return 0;
}