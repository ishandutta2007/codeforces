#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int dx[8] = {1, 1, 1, 0, 0, -1, -1, -1}, dy[8] = {1, 0, -1, 1, -1, 1, 0, -1};
int n, m, a[22][22];

void solve(){
    memset(a, 0, sizeof a);
    cin >> n >> m;

    for(int i=1;i<=m;i+=2) a[1][i] = 1;

    for(int i=2;i<n;i++){
        for(int j : {1, m}){
            int flag = 1;
            for(int d=0;d<8;d++) if(a[i+dx[d]][j+dy[d]]) flag = 0;
            a[i][j] = flag;
        }
    }
    for(int j=1;j<=m;j++){
        int flag = 1;
        for(int d=0;d<8;d++) if(a[n+dx[d]][j+dy[d]]) flag = 0;
        a[n][j] = flag;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) cout << a[i][j];
        cout << "\n";
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int tc = 1; cin >> tc;
    while(tc--) solve(), cout << "\n";
}