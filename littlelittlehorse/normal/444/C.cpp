#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

long long f[400001], a[400001];
int n, m, xiao[400001], da[400001], key[400001];

inline void buildtree(int k, int Left, int Right){
    f[k] = 0; xiao[k] = Left; da[k] = Right; key[k] = 0; a[k] = 0;
    if (Left == Right) return;
    int i = (Left + Right) >> 1;
    buildtree(k + k, Left, i);
    buildtree(k + k + 1, i + 1, Right);
}

inline void update(int k, int Left, int Right, long long value, int x){
        f[k] += (long long)value * (Right - Left + 1);
        key[k] = x; xiao[k] = x; da[k] = x; a[k] += value;
}
    
inline void xiaoqu(int k, int Left, int Right){
    int i = (Left + Right) >> 1;
    if (key[k]) update(k + k, Left, i, a[k], key[k]), update(k + k + 1, i + 1, Right, a[k], key[k]), key[k] = 0, a[k] = 0;
}

inline void change(int k, int Left, int Right, int s, int t, int x){
    if (Left == s && Right == t && xiao[k] == da[k])
    {
        f[k] += (long long)abs(x - da[k]) * (Right - Left + 1);
        a[k] += abs(x - da[k]);
        key[k] = x; xiao[k] = x; da[k] = x;
        return;
    }
    int i = (Left + Right) >> 1;
    xiaoqu(k, Left, Right);
    if (t <= i) change(k + k, Left, i, s, t, x);
    else if (s > i) change(k + k + 1, i + 1, Right, s, t, x);
    else change(k + k, Left, i, s, i, x), change(k + k + 1, i + 1, Right, i + 1, t, x);
    f[k] = f[k + k] + f[k + k + 1]; xiao[k] = min(xiao[k + k], xiao[k + k + 1]); da[k] = max(da[k + k], da[k + k + 1]);
}

long long calc(int k, int Left, int Right, int s, int t){
    //printf("calc %d %d %d %d %d\n", k, Left, Right, s, t);
    if (Left == s && Right == t) return f[k];
    int i = (Left + Right) >> 1;
    xiaoqu(k, Left, Right);
    if (t <= i) return calc(k + k, Left, i, s, t);
    else if (s > i) return calc(k + k + 1, i + 1, Right, s, t);
    else return calc(k + k, Left, i, s, i) + calc(k + k + 1, i + 1, Right, i + 1, t);
}

int main(){
    scanf("%d%d", &n, &m);
    buildtree(1, 1, n);
    for (int i = 1; i <= m; i++)
    {       
        int type, L, R;
        scanf("%d%d%d", &type, &L, &R);
        if (type == 1)
        {
            int x;
            scanf("%d", &x);
            change(1, 1, n, L, R, x);
        }
        else printf("%I64d\n", calc(1, 1, n, L, R));
    }
}