#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    LL n;
    cin >> n;
    LL v[n];
    LL t[n];
    for(LL i = 0; i < n; i++){
        cin >> v[i];
    }
    LL sum = 0;
    for(LL i = 0; i < n; i++){
        v[i] += sum;
        cin >> t[i];
        sum += t[i];
    }
    LL diff[n];
    for(LL i = 0; i < n; i++){
        diff[i] = t[i] *(n-1-i);
    }
    sort(v, v+n);
    LL ans[n];

    LL csum = 0;
    LL tpsum = 0;

    LL firstv = 0;
    for(LL i = 0; i < n; i++){
        tpsum += t[i];
        // sum min(v, tpsum);
        while(firstv < n && v[firstv] <= tpsum){
            csum += v[firstv];
            firstv++;
        }
        ans[i] = csum + (n-firstv) * tpsum;
    }
    for(LL i = n-1; i > 0; i--){
        ans[i] -= ans[i-1];
    }
    for(LL i = 0; i < n; i++){
        cout << ans[i] - diff[i] << " ";
    }
    cout << '\n';
}