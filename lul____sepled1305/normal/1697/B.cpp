#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,m; cin>>n>>m;
    long long p[n];
    long long a[n+1];
    for(int i=0;i<n;i++)
        cin>>p[i];
    sort(p,p+n);
    long long cur = 0;
    a[0] = 0;
    for(int i=0;i<n;i++) {
        cur += p[i];
        a[i+1] = cur;
    }
    for(int i=0;i<m;i++) {
        int x,y; cin>>x>>y;
        cout<<a[n-x+y]-a[n-x]<<endl;
    }
    return 0;
}