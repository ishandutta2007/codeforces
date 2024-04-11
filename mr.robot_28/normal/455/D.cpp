#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <bitset>
#include <cmath>
#include <algorithm>
 
using namespace std;
 
//Constants
const int MaxN = 100100;
const int block = 317;
const int cBlocks = MaxN / block + 5;
const int C = 317;
 
//DATA
int n, q, cntBlocks;
short met[cBlocks][MaxN];
int vals[cBlocks][block + C + 5], wasVals[cBlocks][block + C + 5], szVals[cBlocks], szWasVals[cBlocks];
int a[MaxN], b[MaxN];
 
//Methods
inline void Build() {
    for (int i = 1; i <= n; i += block) {
        int r = min(n, i + block - 1);
        for (int j = i; j <= r; j++) {
            vals[cntBlocks][szVals[cntBlocks]++] = a[j];
            //vals[cntBlocks].push_back(a[j]);
            wasVals[cntBlocks][szWasVals[cntBlocks]++] = a[j];
            //wasVals[cntBlocks].push_back(a[j]);
            met[cntBlocks][a[j]]++;
        }
        cntBlocks++;
    }
}
 
inline void reBuild() {
    int blen = 0;
    for (int i = 0; i < cntBlocks; i++) {
        for (int j = 0; j < szVals[i]; j++)
            b[++blen] = vals[i][j];
        szVals[i] = 0;
        //vals[i].resize(0);
        for (int j = 0; j < szWasVals[i]; j++)
            met[i][wasVals[i][j]] = 0;
        szWasVals[i] = 0;
        //wasVals[i].resize(0);
    }
    cntBlocks = 0;
    for (int i = 1; i <= n; i++)
        a[i] = b[i];
    Build();
}
 
inline int myErase(int idx) {
    int sum = 0;
    for (int i = 0; i < cntBlocks; i++) {
        sum += szVals[i];
        if (sum >= idx) {
            int pos = szVals[i] - (sum - idx) - 1;
            met[i][vals[i][pos]]--;
            int res = vals[i][pos];
            for (int it = pos; it < szVals[i]; it++)
                vals[i][it] = vals[i][it + 1];
            szVals[i]--;
            return res;
        }
    }
    return 0;
}
 
inline void myInsert(int idx, int x) {
    int sum = 0;
    for (int i = 0; i < cntBlocks; i++) {
        sum += szVals[i];
        if (sum >= idx) {
            wasVals[i][szWasVals[i]++] = x;
            //wasVals[i].push_back(x);
            met[i][x]++;
            int pos = idx - (sum - szVals[i]);
            for (int it = szVals[i]; it > pos; it--)
                vals[i][it] = vals[i][it - 1];
            vals[i][pos] = x;
            szVals[i]++;
            //vals[i].insert(vals[i].begin() + pos, x);
            break;
        }
    }
}
 
inline void doShiftQuery(int l, int r) {
    if (l == r) return;
    int x = myErase(r);
    myInsert(l - 1, x);
}
 
inline int doQueryCount(int r, int k) {
    int sum = 0, res = 0;
    for (int i = 0; i < cntBlocks; i++) {
        sum += szVals[i];
        if (sum <= r) {
            res += met[i][k];
        }
        else {
            sum -= szVals[i];
            int it = 0;
            while (sum < r) {
                if (vals[i][it] == k) ++res;
                ++sum; ++it;
            }
            break;
        }
    }
    return res;
}
 
inline int doQueryCount(int l, int r, int k) {
    return doQueryCount(r, k) - doQueryCount(l - 1, k);
}
 
int main()
{
    //freopen("1.in", "r", stdin);
    //freopen("output.txt", "w", stdout);
 
    scanf("%d", &n);
 
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
 
    Build();
 
    scanf("%d", &q);
 
    int z = 1;
 
    int last_ans = 0;
    for (int i = 1; i <= q; i++) {
        int comm, l, r, k;
        scanf("%d", &comm);
 
        if (comm == 1) {
            scanf("%d%d", &l, &r);
            l = ((l + last_ans - 1 + n) % n) + 1;
            r = ((r + last_ans - 1 + n) % n) + 1;
            if (l > r) swap(l, r);
            doShiftQuery(l, r);
            z++;
        }
        else {
            scanf("%d%d%d", &l, &r, &k);
            l = ((l + last_ans - 1 + n) % n) + 1;
            r = ((r + last_ans - 1 + n) % n) + 1;
            k = ((k + last_ans - 1 + n) % n) + 1;
            if (l > r) swap(l, r);
            last_ans = doQueryCount(l, r, k);
            printf("%d\n", last_ans);
        }
 
        if (z % C == 0) reBuild(), z++;
    }
 
    return 0;
}