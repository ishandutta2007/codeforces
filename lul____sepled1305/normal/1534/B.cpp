#include<bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin>>T;
    while(T--) {
        int n;
        long long ans = 0;
        cin>>n;
        int a[n+2];
        a[0] = 0, a[n+1] = 0;
        for(int i=0;i<n;i++)
            cin>>a[i+1];
        for(int i=1;i<=n;i++) {
            if(a[i] > a[i-1])
                ans += (a[i]-a[i-1]);
            if(a[i+1] < a[i])
                ans += (a[i]-a[i+1]);
        }
        for(int i=1;i<=n;i++) {
            if(a[i] > a[i-1] && a[i] > a[i+1])
                ans -= (a[i] - max(a[i-1],a[i+1]));
        }
        cout<<ans<<endl;
    }
    return 0;
}