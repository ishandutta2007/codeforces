#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int tc, n, k, a[111];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> tc;
    while(tc--){
        cin >> n >> k;
        for(int i=1;i<=n;i++) cin >> a[i];

        int flag = 0;
        for(int i=2;i<=n;i++) if(a[i] != a[1]) flag = 1;

        if(flag && k == 1){
            cout << "-1\n";
            continue;
        }
        if(k == 1 || !flag){
            cout << "1\n";
            continue;
        }


        
        int cnt = 0;
        a[0] = -1;
        for(int i=1;i<=n;i++) if(a[i] != a[i-1]) cnt++;

        cnt--;
        cout << cnt / (k-1) + (cnt % (k-1) > 0) << "\n";
    }
}