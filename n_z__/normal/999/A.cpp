#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[100001];
main() {
    int n,k;
    cin>>n>>k;
    int q=0;
    for(int x=1;x<=n;x++)
    {
        cin>>a[x];
        if(q==x-1&&a[x]<=k)q++;
    }
    int w=0;
    for(int x=1;x<=n;x++)
    if(w==x-1&&a[n-x+1]<=k)w++;
    cout<<min(q+w,n);
}