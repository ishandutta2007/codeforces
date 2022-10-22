#include <bits/stdc++.h>
using namespace std;

struct pos {
    int x, y, z;
    int ind;
};

map <int, map <int, map <int, int> > > M;
int n;

void Insert(int x, int y, int z, int ind)
{
    M[x][y][z] = ind;
}

void Remove(int x, int y, int z)
{
    M[x][y].erase(z);
    if (M[x][y].size() == 0) {
        M[x].erase(y);
        if (M[x].size() == 0)
            M.erase(x);
    }
}

pos getFirst()
{
    auto itx = M.begin();
    auto ity = itx->second.begin();
    auto itz = ity->second.begin();
    return pos{itx->first, ity->first, itz->first, itz->second};
}

pos Get(int x, int y, int z)
{
    auto itx = M.lower_bound(x);
    if (itx == M.end()) itx--;
    auto ity = itx->second.lower_bound(y);
    if (ity == itx->second.end()) ity--;
    auto itz = ity->second.lower_bound(z);
    if (itz == ity->second.end()) itz--;
    return pos{itx->first, ity->first, itz->first, itz->second};
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x, y, z; scanf("%d %d %d", &x, &y, &z);
        Insert(x, y, z, i);
    }
    for (int i = 0; i < n / 2; i++) {
        pos A = getFirst(); Remove(A.x, A.y, A.z);
        pos B = Get(A.x, A.y, A.z); Remove(B.x, B.y, B.z);
        printf("%d %d\n", A.ind, B.ind);
    }
    return 0;
}