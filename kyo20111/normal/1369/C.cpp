#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll t, n, k, a[200200], w[200200];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i=1;i<=n;i++) cin >> a[i];
        int o = 0;
        for(int i=1;i<=k;i++){
            cin >> w[i];
            if(w[i] == 1) o++;
        }
        sort(a+1, a+1+n), sort(w+1, w+1+k, greater<ll>());

        ll sum = 0;
        int l = 1, r = n;
        while(o){
            sum += a[r] + a[r];
            r--;
            o--;
        }
        for(int i=1;i<=k;i++){
            if(w[i] == 1){
                break;
            }else{
                sum += a[r] + a[l];
                r--;
                l += w[i]-1;
            }
        }
        cout << sum << '\n';
    }
}