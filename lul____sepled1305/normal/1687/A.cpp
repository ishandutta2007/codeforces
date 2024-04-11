//
// Created by Nitit Jongsawatsataporn on 3/6/2022 AD.
//

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>

int main() {
    int T; cin>>T;
    while(T--) {
        int n,k; cin>>n>>k;
        int a[n];
        ll ans = 0;
        for(int i=0;i<n;i++) {
            cin>>a[i];
        }
        if(k >= n) {
            for(int i=0;i<n;i++)
                ans += a[i]+k-i-1;
        }
        else {
            for(int i=0;i<k;i++)
                ans -= (i+1);
            ll maxi = 0, cur = 0;
            for(int i=0;i<k;i++) {
                cur += a[i];
            }
            maxi = cur;
            for(int i=k;i<n;i++) {
                cur -= a[i-k];
                cur += a[i];
                maxi = max(maxi,cur);
            }
            ans += maxi;
            ans += 1LL*k*k;
        }
        cout<<ans<<'\n';
    }
    return 0;
}