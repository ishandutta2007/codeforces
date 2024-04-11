#include<bits/stdc++.h>
using namespace std;
int n,d,a[2005],ans=0;
int main()
{
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]<=a[i-1]){
            ans+=(a[i-1]-a[i])/d+1;
            a[i]+=((a[i-1]-a[i])/d+1)*d;
        }
    }
    cout<<ans;
    return 0;
}