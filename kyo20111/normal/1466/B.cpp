#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n, a[100100];

void solve_tc(){
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];

    a[0] = -10;
    int flag = 0, ans = 0;
    for(int i=1;i<=n;i++){
        if(a[i-1] == a[i]){
            if(flag) continue;
            ans++;
            flag = 1;
        }else{
            if(flag && a[i-1] + 1 == a[i]){
                ans++;
                continue;
            }
            ans++;
            flag = 0;
        }
    }
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);

    int tc = 1;
    cin >> tc;

    while(tc--){
        solve_tc();
        cout << "\n";
    }
}