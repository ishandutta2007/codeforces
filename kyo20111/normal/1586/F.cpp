#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, d, c[1010][1010], cnt;

void solve(int l, int r, int k){
    if(r - l + 1 <= d) return;
    int m = (r - l + 1) / d + 1;
    int f = 1;

    cnt = max(cnt, k);

    for(int i=l;i<=r;i+=m){
        if(f && (r - l + 1) % d == 0) m--, f--;
        for(int j=i;j<=min(r, i+m-1);j++) c[j][k] = i;
        solve(i, min(r, i+m-1), k+1);
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> d;

    solve(1, n, 0);

    for(int i=1;i<=n;i++) c[i][cnt+1] = i;

    cout << cnt+2 << "\n";

    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=0;k<=cnt+1;k++) if(c[i][k] != c[j][k]){
                cout << k+1 << " ";
                break;
            }
        }
    }
}