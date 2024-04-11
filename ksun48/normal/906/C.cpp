#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int dp[1<<22];
int main(){
    int n, m;
    cin >> n >> m;
    int ok[n][n];
    if(m == n*(n-1)/2){
        cout << 0 << endl;
        return 0;
    }
    int good[n];
    for(int i = 0; i < n; i++){
        good[i] = 0;
        for(int j = 0; j < n; j++){
            ok[i][j] = 0;
        }
    }
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        ok[u][v] = ok[v][u] = 1;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(ok[i][j]) good[i] |= (1<<j);
        }
    }

    int best = 10000000;
    vector<int> ans;
    for(int c = 0; c < n; c++){
        // c = start;
        for(int j = 0; j < (1<<n); j++){
            dp[j] = 1000000;
        }
        dp[(1<<n)-1] = 1;
        int st = (1<<c) | good[c];
        int bad = ((1<<n)-1) ^ st;
        for(int y = bad; y >= 0; y = (y-1) & bad){
            int z = y ^ st;
            for(int i = 0; i < n; i++){
                if(z & (1<<i)){
                    int newz = z | good[i];
                    dp[z] = min(dp[z], dp[newz] + 1);
                }
            }
            if(y == 0) break;
        }
        if(dp[st] < best){
            int z = st;
            vector<int> seq;
            while(z != ((1<<n) - 1)){
                for(int i = 0; i < n; i++){
                    if(z & (1<<i)){
                        int newz = z | good[i];
                        if(dp[z] == dp[newz] + 1){
                            seq.push_back(i);
                            z = newz;
                            break;
                        }
                    }
                }
            }
            seq.push_back(c);
            best = dp[st];
            ans = seq;
        }
    }
    cout << best << endl;
    for(int j = 0; j < ans.size(); j++){
        cout << ans[j] + 1 << " ";
    }
    cout << endl;

}