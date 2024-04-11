#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int t, n, m, a[33][33], chk[33][33];
queue<int> qx, qy, qc;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        vector<pair<int, int>> v[n+m+1];
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%d",a[i]+j), chk[i][j] = 0;

        int mx = 0;
        qx.push(1), qy.push(1), qc.push(0), chk[1][1] = 1;
        while(!qx.empty()){
            int x = qx.front(), y = qy.front(), c = qc.front(); qx.pop(), qy.pop(), qc.pop();
            mx = c;
            v[c].push_back({x, y});
            if(x < n && !chk[x+1][y]) qx.push(x+1), qy.push(y), qc.push(c+1), chk[x+1][y] = 1;
            if(y < m && !chk[x][y+1]) qx.push(x), qy.push(y+1), qc.push(c+1), chk[x][y+1] = 1;
        }

        int ans = 0;
        for(int i=0;i<(mx+1)/2;i++){
            int c[2] = {0, 0};
            for(auto [x, y] : v[i]) c[a[x][y]]++;
            for(auto [x, y] : v[mx-i]) c[a[x][y]]++;
            ans += min(c[0], c[1]);
        }
        printf("%d\n",ans);
    }
}