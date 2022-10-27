#include<bits/stdc++.h>
using namespace std;
const int maxn=4e5+10;
int a[maxn],n;

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        a[n+i]=a[i];
    }
    int ct=0,ans=0;
    for(int i=1;i<=2*n;i++){
        if(a[i]){
            ct++;
            ans=max(ans,ct);
            }
        else{
            ans=max(ans,ct);
            ct=0;
        }
    }
    cout<<ans;
}