#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

struct node{
    long long A, B, value;
} f[3000001];
int n, m;
long long v[300001][3][3], a[3][3], Q[300001][3][3], w[300001];
const int P = 1000000009;
long long ans;

inline void buildtree(int k, int Left, int Right){
    f[k].A = f[k].B = 0;
    if (Left == Right)
    {
        f[k].value = w[Left];
        return;
    }
    int i = (Left + Right) >> 1;
    buildtree(k + k, Left, i);
    buildtree(k + k + 1, i + 1, Right);
    f[k].value = f[k + k].value + f[k + k + 1].value;
    f[k].value %= P;
}

long long check(long long A, long long B, long long Left, long long Right){
    long long e[3][3];
    for (int i = 1; i <= 2; i++)
        for (int j = 1; j <= 2; j++)
        {
            if (Left) e[i][j] = Q[Right][i][j] - Q[Left - 1][i][j];
            else e[i][j] = Q[Right][i][j];
            if (e[i][j] < 0) e[i][j] += P;
        }
    return (A * e[1][1] + B * e[2][1]) % P;
}

inline void update(int k, int Left, int i, int Right){
    f[k + k].A += f[k].A; f[k + k].A %= P;
    f[k + k].B += f[k].B; f[k + k].B %= P;
    f[k + k + 1].A += check(f[k].A, f[k].B, i - Left + 1, i - Left + 1); 
    f[k + k + 1].A %= P;
    f[k + k + 1].B += check(f[k].A, f[k].B, i - Left + 2, i - Left + 2); 
    f[k + k + 1].B %= P;
    f[k].A = f[k].B = 0;
}

inline void insert(int k, int Left, int Right, int s, int t, int num){
    //printf("%d %d %d %d %d\n", k, Left, Right, s, t);
    if (Left == s && Right == t)
    {
        f[k].A += check(0, 1, num - 1, num - 1); f[k].A %= P;
        f[k].B += check(0, 1, num, num); f[k].B %= P;
        return;
    }
    int i = (Left + Right) >> 1;
    update(k, Left, i, Right);
    if (t <= i) insert(k + k, Left, i, s, t, num);
    else if (s > i) insert(k + k + 1, i + 1, Right, s, t, num);
    else insert(k + k, Left, i, s, i, num), insert(k + k + 1, i + 1, Right, i + 1, t, i + 1 - s + num);
    f[k].value = (f[k + k].value + check(f[k + k].A, f[k + k].B, 1, i - Left + 1)) % P;
    f[k].value += (f[k + k + 1].value + check(f[k + k + 1].A, f[k + k + 1].B, 1, Right - i)) % P;
    f[k].value %= P;
    /*f[k].value = (f[k + k].value + check(f[k + k].A, f[k + k].B, 0, i - Left)) % P;
    f[k].value += (f[k + k + 1].value + check(f[k + k + 1].A, f[k + k + 1].B, 0, Right - i - 1)) % P;
    f[k].value %= P;*/
}

inline void calc(int k, int Left, int Right, int s, int t){
    if (Left == s && Right == t)
    {
        ans += f[k].value + check(f[k].A, f[k].B, 1, Right - Left + 1);
        //printf("T_T %d %d %lld %lld %lld %lld\n", Left, Right, f[k].value, f[k].A, f[k].B, check(f[k].A, f[k].B, 1, Right - Left + 1));
        ans %= P;
        return;
    }
    int i = (Left + Right) >> 1;
    update(k, Left, i, Right);
    if (t <= i) calc(k + k, Left, i, s, t);
    else if (s > i) calc(k + k + 1, i + 1, Right, s, t);
    else calc(k + k, Left, i, s, i), calc(k + k + 1, i + 1, Right, i + 1, t);
    f[k].value = (f[k + k].value + check(f[k + k].A, f[k + k].B, 1, i - Left + 1)) % P;
    f[k].value += (f[k + k + 1].value + check(f[k + k + 1].A, f[k + k + 1].B, 1, Right - i)) % P;
    f[k].value %= P;
    
    /*f[k].value = (f[k + k].value + check(f[k + k].A, f[k + k].B, 0, i - Left)) % P;
    f[k].value += (f[k + k + 1].value + check(f[k + k + 1].A, f[k + k + 1].B, 0, Right - i - 1)) % P;
    f[k].value %= P;*/
}

int main(){
    scanf("%d%d", &n, &m);
    v[0][1][1] = 1; v[0][1][2] = 0;
    v[0][2][1] = 0; v[0][2][2] = 1;
    a[1][2] = a[2][1] = a[2][2] = 1;
    a[1][1] = 0;
    memset(Q, 0, sizeof(Q));
    Q[0][1][1] = 1; Q[0][1][2] = 0;
    Q[0][2][1] = 0; Q[0][2][2] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 2; j++)
            for (int k = 1; k <= 2; k++)
                for (int l = 1; l <= 2; l++)
                    v[i][j][k] += v[i - 1][j][l] * a[l][k] % P,  
                    v[i][j][k] %= P;
        for (int j = 1; j <= 2; j++)
            for (int k = 1; k <= 2; k++) 
                Q[i][j][k] = (Q[i - 1][j][k] + v[i][j][k]) % P;
    }
    for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
    buildtree(1, 1, n);
    for (;m--;)
    {
        int type, x, y;
        scanf("%d%d%d", &type, &x, &y);
        if (type == 1) insert(1, 1, n, x, y, 1);
        else 
        {
            ans = 0;
            calc(1, 1, n, x, y);
            printf("%d\n", ans);
        }
    }
}