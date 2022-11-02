#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int per[6][3] = {{0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 0, 1}, {2, 1, 0}};
int a[9][3], v[9][3], len, e[9];
long long f[9][9];

long long sqr(long long x){
    return x * x;
}

bool calc(long long X1, long long Y1, long long Z1, long long X2, long long Y2, long long Z2){
    return X1 * X2 + Y1 * Y2 + Z1 * Z2;
}

bool check(){
    long long Min = 1LL << 60LL;
    for (int i = 1; i <= 8; i++)
        for (int j = i + 1; j <= 8; j++) 
            f[i][j] = f[j][i] = sqr(v[j][0] - v[i][0]) + sqr(v[j][1] - v[i][1]) +
                    sqr(v[j][2] - v[i][2]), Min = min(Min, f[i][j]);
    if (!Min) return false;
    for (int i = 1; i <= 8; i++) 
    {
        len = 0;
        for (int j = 1; j <= 8; j++)
            if (i != j && f[i][j] == Min) e[++len] = j;
        if (len != 3) return false;
        for (int j = 1; j <= 3; j++)
            for (int k = j + 1; k <= 3; k++)
            {
                if (calc(v[e[k]][0] - v[i][0], v[e[k]][1] - v[i][1], v[e[k]][2] - v[i][2],
                            v[e[j]][0] - v[i][0], v[e[j]][1] - v[i][1], v[e[j]][2] - v[i][2])) 
                    return false;
            }
    }   
    return true;
}
            
bool soso(int step){
    if (step == 9)
    {
        if (check())
        {
            printf("YES\n");
            for (int i = 1; i <= 8; i++) printf("%d %d %d\n", v[i][0], v[i][1], v[i][2]);
            return true;
        }
        return false;
    }
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 3; j++) v[step][j] = a[step][per[i][j]];
        if (soso(step + 1)) return true;
    }
    return false;
}

int main(){
    //freopen("b.in", "r", stdin);
    //freopen("b.out", "w", stdout);
    for (int i = 1; i <= 8; i++) scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
    if (!soso(1)) printf("NO\n");
}