#include<bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k, p;
    cin >> n >> k >> p;
    int last[k][p];
    int inf = 10000000;
    for(int i = 0; i<k; i++){
        for(int j = 0; j<p; j++){
            last[i][j] = -inf;
            last[i][j] = -inf;
        }
    }
    int zz;
    cin >> zz;
    last[0][zz%p] = 0;
    for(int z = 1; z<n; z++){
        int x;
        cin >> x;
        int now[k][p];
        for(int i = 0; i<k; i++){
            for(int j = 0; j<p; j++){
                now[i][j] = -inf;
            }
        }
        for(int i = 0; i<k; i++){
            for(int j = 0; j<p; j++){
                if(i+1<k){
                    now[i+1][x%p] = max(now[i+1][x%p],last[i][j]+j);
                }
                now[i][(j+x)%p] = max(now[i][(j+x)%p],last[i][j]);
            }
        }
        for(int i = 0; i<k; i++){
            for(int j = 0; j<p; j++){
                last[i][j] = now[i][j];
            }
        }
        
    }
    int ans = -inf;
    for(int i = 0; i<k; i++){
        for(int j = 0; j<p; j++){
            ans = max(ans,last[i][j]+j);
        }
    }
    cout << ans << endl;
}