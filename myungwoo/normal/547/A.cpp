#include <bits/stdc++.h>
using namespace std;

typedef long long lld;

int M;
int H1, A1, H2, A2;
int X1, Y1, X2, Y2;
int C1, C2, K1, K2;

void calc(int h, int a, int x, int y, int &c, int &k)
{
    vector <int> vis(M, -1);
    k = -1; c = 0;
    for (int i=0;;i++){
        if (vis[h] >= 0){
            if (k >= vis[h])
                c = i - vis[h];
            break;
        }
        if (h == a) k = i;
        vis[h] = i;
        h = ((lld)h * x + y) % M;
    }
}

int main()
{
    cin >> M >> H1 >> A1 >> X1 >> Y1 >> H2 >> A2 >> X2 >> Y2;
    calc(H1, A1, X1, Y1, C1, K1);
    calc(H2, A2, X2, Y2, C2, K2);
    if (K1 < 0 || K2 < 0){ puts("-1"); return 0; }
    if (K1 > K2){
        swap(H1, H2);
        swap(A1, A2);
        swap(X1, X2);
        swap(Y1, Y2);
        swap(C1, C2);
        swap(K1, K2);
    }
    for (int i=0;i<K1;i++) H2 = ((lld)H2 * X2 + Y2) % M;
    calc(H2, A2, X2, Y2, C2, K2);
    if (!K2){ printf("%d\n", K1); return 0; }
    if (K2 < 0 || !C1){ puts("-1"); return 0; }
    vector <int> vis(C1, 0);
    for (lld i=K2%C1,t=K2;;){
        if (!i){
            printf("%lld\n", K1 + t);
            return 0;
        }
        if (vis[i]) break;
        vis[i] = 1;
        i = (i+C2) % C1;
        t += C2;
    }
    puts("-1");
}