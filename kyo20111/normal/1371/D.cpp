#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int tc, n, k, a[333][333];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> tc;
    while(tc--){
        cin >> n >> k;
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) a[i][j] = 0;
        // int cnt = 0;
        // while(k--){
        //     x++, y++;
        //     if(y > n){
        //         y = l, x = l+1;
        //         l++;
        //     }
        //     if(x > n){
        //         x = 1;
        //     }
        //     cout << x << ' ' << y << '\n';
        //     a[x][y] = 1;
        // }
        for(int i=0;i<k;i++){
            a[(i+i/n)%n][i%n] = 1;
        }

        int mxr = 0, mnr = 1e9, mxc = 0, mnc = 1e9;
        for(int i=0;i<n;i++){
            int r = 0, c = 0;
            for(int j=0;j<n;j++) r += a[i][j], c += a[j][i];
            mxr = max(mxr, r);
            mnr = min(mnr, r);
            mxc = max(mxc, r);
            mnc = min(mnc, r);
        }

        cout << (mxr - mnr) * (mxr - mnr) + (mxc - mnc) * (mxc - mnc) << '\n';
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout << a[i][j];
            }
            cout << '\n';
        }
    }
}