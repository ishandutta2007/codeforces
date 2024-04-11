#include<bits/stdc++.h>
using namespace std;
int a[300];
int main(){
    int n,ans,ct;
    scanf("%d",&n);
     ans=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    a[n+1]=1001;
     ct=0;
    for(int i=1;i<=n+1;i++){
        if(a[i]-1==a[i-1])
            ct++;
        else
            ans=max(ct-1,ans),ct=0;
    }
    ans=max(ct-1,ans);
    printf("%d\n",ans);

}