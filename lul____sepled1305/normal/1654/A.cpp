#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; cin>>T;
    while(T--) {
        int n; cin>>n;
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        sort(a,a+n,greater<int>());
        cout<<a[0]+a[1]<<endl;
    }
    return 0;
}