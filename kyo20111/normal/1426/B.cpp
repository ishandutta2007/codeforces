#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int tc, n, m, a[111][3][3];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> tc;
    while(tc--){
        cin >> n >> m;
        for(int i=1;i<=n;i++) for(int j=1;j<=2;j++) for(int k=1;k<=2;k++) cin >> a[i][j][k];
        if(m % 2){
            cout << "NO\n";
            continue;
        }
        int flag = 0;
        for(int i=1;i<=n;i++) if(a[i][1][2] == a[i][2][1]) flag = 1;
        cout << (flag ? "YES":"NO") << "\n";
    }
}