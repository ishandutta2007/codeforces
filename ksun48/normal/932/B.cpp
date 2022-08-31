#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int psums[1100000][10];
LL g[1100000];
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    for(int i = 0; i < 10; i++){
        psums[0][i] = 0;
    }

    for(int n = 1; n < 1100000; n++){
        if(n < 10){
            g[n] = n;
        } else {
            int d = 1;
            int c = n;
            while(c){
                if(c % 10 != 0){
                    d *= (c % 10);
                }
                c /= 10;
            }
            g[n] = g[d];
        }
        for(int j = 0; j < 10; j++){
            psums[n][j] = psums[n-1][j];
        }
        psums[n][g[n]]++;
    }
    int Q;
    cin >> Q;
    for(int i = 0; i < Q; i++){
        int l, r, k;
        cin >> l >> r >> k;
        cout << psums[r][k] - psums[l-1][k] << '\n';
    }
}