#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 1005;

int n, edge[MAXN][2], par[MAXN], rem[MAXN][2], add[MAXN][2], cnt, t;

int getpar(int a) { return par[a] == a ? a : par[a] = getpar(par[a]); }
void merge(int a, int b) { par[getpar(a)] = getpar(b); }

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    scanf("%d", &n);
    for (int i=0; i<n; i++) par[i] = i;
    for (int i=0; i<n-1; i++) {
        scanf("%d %d", &edge[i][0], &edge[i][1]);
        edge[i][0]--; edge[i][1]--;
        if (getpar(edge[i][0]) == getpar(edge[i][1])) {
            rem[cnt][0] = edge[i][0]; rem[cnt][1] = edge[i][1];
            cnt++;
        } else {
            merge(edge[i][0], edge[i][1]);
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (getpar(i) != getpar(j)) {
                add[t][0] = i; add[t][1] = j;
                t++;
                merge(i, j);
            }
        }
    }
    printf("%d\n", t);
    for (int i=0; i<t; i++) printf("%d %d %d %d\n", rem[i][0]+1, rem[i][1]+1, add[i][0]+1, add[i][1]+1);
    return 0;
}