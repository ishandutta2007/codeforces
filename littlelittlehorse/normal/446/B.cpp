#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

struct node{
    long long value, key, position;
} f[10001], v[10001];
long long ans, Q[1000011], W[1000011];
int n, m, k, p, a[1001][1001], A[1001], B[1001];

inline void insert(node *f, int k, int Left, int Right, int x, int y){
    if (Left == Right)
    {
        f[k].key += y;
        return;
    }
    int i = (Left + Right) >> 1;
    if (x <= i) insert(f, k + k, Left, i, x, y);
    else insert(f, k + k + 1, i + 1, Right, x, y);
    if (f[k + k].value + f[k + k].key > f[k + k + 1].value + f[k + k + 1].key)
    f[k].value = f[k + k].value + f[k + k].key, f[k].position = f[k + k].position;
    else
    f[k].value = f[k + k + 1].value + f[k + k + 1].key, f[k].position = f[k + k + 1].position;
}

inline void buildtree(node *f, int k, int Left, int Right){
    f[k].position = Left;
    f[k].value = f[k].key = 0;
    if (Left == Right) return;
    int i = (Left + Right) >> 1;
    buildtree(f, k + k, Left, i);
    buildtree(f, k + k + 1, i + 1, Right);
}

int main(){
    scanf("%d%d%d%d", &n, &m, &k, &p);
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= m; j++) scanf("%d", &a[i][j]);
    buildtree(f, 1, 1, n);
    buildtree(v, 1, 1, m);
    for (int i = 1; i <= n; i++)
    {
        int cnt = 0;
        for (int j = 1; j <= m; j++) cnt += a[i][j];
        A[i] = cnt;
        insert(f, 1, 1, n, i, cnt);
    }
    for (int i = 1; i <= m; i++)
    {
        int cnt = 0;
        for (int j = 1; j <= n; j++) cnt += a[j][i];
        B[i] = cnt;
        insert(v, 1, 1, m, i, cnt);
    }
    ans = -1LL<<60LL; 
    Q[0] = 0;
    for (int i = 1; i <= k; i++)
    {
        Q[i] = Q[i - 1] + f[1].key + f[1].value;
        insert(f, 1, 1, n, f[1].position, -p * m);
    }
    W[0] = 0;
    for (int i = 1; i <= k; i++)
    {
        W[i] = W[i - 1] + v[1].key + v[1].value;
        insert(v, 1, 1, m, v[1].position, -p * n);
    }
    for (int i = 0; i <= k; i++)
    {
        //printf("%I64d %I64d\n", Q[i], W[k - i]);
        long long now = Q[i] + W[k - i] - (long long)(k - i) * i * p;
        ans = max(ans, now);
    }
    cout << ans << endl;
}