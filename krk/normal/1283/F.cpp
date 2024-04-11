#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int n;
bool was[Maxn];
bool fir[Maxn];
int my[Maxn];
int mymx[Maxn];
map <int, int> M;
vector <int> A, B;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &my[i]);
        if (!was[my[i]]) { was[my[i]] = true; fir[i] = true; }
    }
    for (int i = 1; i <= n; i++) {
        mymx[i] = i;
        if (!was[i]) M[mymx[i]] = i;
    }
    for (int i = n - 2; i >= 0; i--) {
        auto it = M.begin();
        M.erase(mymx[my[i]]);
        A.push_back(my[i]); B.push_back(M.begin()->second);
        mymx[my[i]] = max(mymx[my[i]], M.begin()->first);
        M.erase(M.begin());
        if (fir[i]) M[mymx[my[i]]] = my[i];
    }
    printf("%d\n", my[0]);
    for (int i = 0; i < A.size(); i++)
        printf("%d %d\n", A[i], B[i]);
    return 0;
}