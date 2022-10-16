#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[50002];
signed main(){
    int n;
    cin>>n;
    int sum=0;
    for(int x=1;x<=n;x++)
    cin>>a[x],sum+=a[x];
    sum/=n;
    int ans=0;
    for(int x=1;x<=n;x++)
    ans+=abs(sum-a[x]),a[x+1]+=a[x]-sum;
    cout<<ans<<endl;
}