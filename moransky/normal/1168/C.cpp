#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int N = 300005, L = 19, INF = 0x3f3f3f3f;
int n, q, a[N], go[N][L], last[L];
int main(){
    memset(go, 0x3f, sizeof go);
    scanf("%d%d", &n, &q);
    for(int i = 1; i <= n; i++)
        scanf("%d", a + i);
    for(int i = n; i; i--){
        int x = a[i];
        for(int j = 0; j < L; j++){
            if((x >> j) & 1) go[i][j] = i;
            else{
                for(int k = 0; k < L; k++){
                    if(((x >> k) & 1) && last[k]) {
                        go[i][j] = min(go[i][j], go[last[k]][j]);
                        //cout << i << " " << j << " " << k << " " << last[k] << endl;
                    }    
                }   
            }
        }
        for(int j = 0; j < L; j++)
            if((x >> j) & 1) last[j] = i;
        //puts("");
    }

    while(q--){
        int x, y; scanf("%d%d", &x, &y);
        //cout << x << " " << y << endl;
        bool ok = false;
        for(int i = 0; i < L; i++){
            if(((a[y] >> i) & 1) && go[x][i] <= y)
                ok = true;
        }
        if(ok) puts("Shi");
        else puts("Fou");
    }
    return 0;

}