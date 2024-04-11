#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,m,a[maxn],ans,b[maxn];
bool ch(int x){
    if(a[1]+x>=m)
        b[1]=0;
    else
        b[1]=a[1];
    for(int i=2;i<=n;i++){
        if(a[i]<b[i-1]){
            if(b[i-1]-a[i]>x)return false;
            else b[i]=b[i-1];
        }
        else if(a[i]>b[i-1]){
            if(m-a[i]+b[i-1]<=x){
                b[i]=b[i-1];
            }
            else{
                b[i]=a[i];
            }
        }
        else if(a[i]==b[i-1])
            b[i]=b[i-1];
    }
    return true;
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    int l=0,r=m,mid;ans=maxn;
    while(l<=r){
        mid=(l+r)>>1;
        if(ch(mid)){
            ans=mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    printf("%d\n",ans);


}