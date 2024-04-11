#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,a[maxn],z,ans,b,l,r;

int main(){
    scanf("%d%d",&n,&z);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+1+n);
    l=1,r=n/2+1;ans=0;
    while(l<=n/2&&r<=n){
        if(a[l]+z<=a[r]){
            ans++,l++,r++;
        }
        else
            r++;
    }
    printf("%d\n",ans);
}