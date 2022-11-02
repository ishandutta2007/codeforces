#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, type, x, y, f[100001], a[100001], key, len, L, R;

inline void insert(int now, int delta){
    //printf("%d %d\n", now, delta);
    for (; now <= n; now += now & (-now)) f[now] += delta;
}

int calc(int now){
    int will = 0;
    for (; now; now -= now & (-now)) will += f[now];
    return will;
}

int main(){
    //freopen("a.in", "r", stdin);
    scanf("%d%d", &n, &m);
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= n; i++) a[i] = 1, insert(i, 1);
    key = 0; len = n; L = 1; R = n;
    for (; m--;)
    {
        scanf("%d", &type);//printf("%d %d %d %d %d %d\n", type, key, L, R, a[L], a[R]);
        if (type == 1)
        {
            scanf("%d", &x);//++x;
            if (!key)
            {
                if (x + x <= len) 
                {
                    for (int i = L + x - 1, j = 1, k = L + x; j <= x; j++, i--, k++)
                        insert(k, a[i]), insert(i, -a[i]), a[k] += a[i], a[i] = 0;
                    L += x;
                    len = R - L + 1;
                }
                else
                {
                    for (int i = L + x - 1, j = 1, k = L + x; j <= x && k <= R; j++, i--, k++)
                        insert(i, a[k]), insert(k, -a[k]), a[i] += a[k], a[k] = 0;
                    R = L + x - 1;
                    key ^= 1;
                    len = R - L + 1;
                }
            }
            else
            {
                if (x + x <= len) 
                {
                    for (int i = R - x + 1, j = 1, k = R - x; j <= x; j++, i++, k--)
                        insert(k, a[i]), insert(i, -a[i]), a[k] += a[i], a[i] = 0;
                    R -= x;
                    len = R - L + 1;
                }
                else
                {
                    //printf("! %d\n", x);
                    for (int i = R - x + 1, j = 1, k = R - x; j <= x && k >= L; j++, i++, k--)
                        //printf("%d %d\n", i, k), 
                        insert(i, a[k]), insert(k, -a[k]), a[i] += a[k], a[k] = 0;
                    //printf("!\n");
                    L = R - x + 1;
                    key ^= 1;
                    len = R - L + 1;
                }
            }
        }
        else
        {
            scanf("%d%d", &x, &y);
            //printf("%d %d\n", x, y);
            if (!key) 
            { 
                x += L; y += L - 1;
                printf("%d\n", calc(y) - calc(x - 1));
            }
            else 
            {
                int X = len - y, Y = len - x;
                X += L; Y += L - 1;
                printf("%d\n", calc(Y) - calc(X - 1));
            }
        }
    }
}