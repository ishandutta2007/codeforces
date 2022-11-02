#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, a[1001], v[1001], pre[1001];
double r[1001][1001], f[1001];
bool b[1001];

bool check(double now){
    memset(f, 127, sizeof(f)); f[0] = 0; pre[0] = 0;
    for (int i = 1; i <= n; i++) 
    {
        for (int j = 0; j < i; j++)
            if (f[j] + r[j][i] < f[i]) 
            f[i] = f[j] + r[j][i], pre[i] = j;
        f[i] -= now * v[i];
    }
    return f[n] < 1e-9;
}

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d%d", &a[i], &v[i]);
    a[0] = 0;
    for (int i = 0; i <= n; i++)
        for (int j = i + 1; j <= n; j++) 
            r[i][j] = sqrt( abs(a[j] - a[i] - m) );
    double Left = 0.0, Right = 1e9, Mid = (Left + Right) / 2.0;
    for (int i = 1; i <= 100; i++, Mid = (Left + Right) / 2.0)
        if (check(Mid)) Right = Mid;
        else Left = Mid;
    check(Right);
    for (int now = n; now; now = pre[now]) b[now] = true;
    for (int i = 1; i < n; i++)
        if (b[i]) printf("%d ", i);
    printf("%d\n", n);
}