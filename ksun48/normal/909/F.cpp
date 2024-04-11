#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve1(int n){ // 0
    if(n % 2 == 1){
        cout << "NO" << endl; return;
    }
    int ans[n+1];
    int cur = n;
    while(cur){
        int f = 1;
        while(f <= cur) f *= 2;
        f--;
        for(int i = cur; i > f-cur; i--){
            ans[i] = f-i;
            ans[f-i] = i;
        }
        cur = f-cur - 1;
    }
    cout << "YES" << endl;
    for(int i = 1; i <= n; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return;
}
void solve2(int n){ // nonzero
    if(n <= 5 || __builtin_popcount(n) == 1){
        cout << "NO" << endl; return;
    }
    int ans[n+1];
    ans[2] = 6; ans[6] = 2;
    ans[1] = 3; ans[3] = 1;
    vector<int> g[30];
    for(int j = 1; j <= n; j++){
        if(6 % j == 0) continue;
        for(int r = 0; r < 25; r++){
            if(j >= (1<<r) && j < (1 << (r+1))){
                g[r].push_back(j);
            }
        }
    }
    for(int r = 0; r < 25; r++){
        for(int i = 0; i < g[r].size(); i++){
            ans[g[r][i]] = g[r][(i+1) % g[r].size()];
        }
    }
    cout << "YES" << endl;
    for(int i = 1; i <= n; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return;    
}
int main(){
    int n;
    cin >> n;
    solve1(n);
    solve2(n);
}