#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1005;

int n, m;
int f[MAXN];
int best = 1e9;

int main() {
    scanf("%d %d", &n, &m);
    for (int i=0; i<m; i++) scanf("%d", &f[i]);
    sort(f, f+m);
    for (int i=0; i+n-1<m; i++) best=min(best, f[i+n-1]-f[i]);
    printf("%d\n", best);
}