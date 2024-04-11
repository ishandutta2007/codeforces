#include<bits/stdc++.h>
using namespace std;
int n,a[500],ans;
void sor(int l,int r){
    if(l==r)return;
    int mid=(l+r)>>1;
    bool x=true;
    for(int i=l+1;i<=r;i++){
        if(a[i]<a[i-1])x=false;
    }
    if(x) ans=max(ans,r-l+1);
    sor(l,mid);sor(mid+1,r);
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    scanf("%d",&a[i]);
    sor(1,n);
    printf("%d\n",max(ans,1));
}