#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int tc, n, a[111], b[111], c[111], p[111];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> tc;
    while(tc--){
        cin >> n;
        for(int i=1;i<=n;i++) cin >> a[i];
        for(int i=1;i<=n;i++) cin >> b[i];
        for(int i=1;i<=n;i++) cin >> c[i];

        for(int i=1;i<n;i++){
            if(a[i] != p[i-1]) p[i] = a[i];
            if(b[i] != p[i-1]) p[i] = b[i];
            if(c[i] != p[i-1]) p[i] = c[i];
        }

        if(a[n] != p[n-1] && a[n] != p[1]) p[n] = a[n];
        if(b[n] != p[n-1] && b[n] != p[1]) p[n] = b[n];
        if(c[n] != p[n-1] && c[n] != p[1]) p[n] = c[n];

        for(int i=1;i<=n;i++) cout << p[i] << " ";
        cout << "\n";

        for(int i=1;i<=n;i++) p[i] = 0;
    }
}