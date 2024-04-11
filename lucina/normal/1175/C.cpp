#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int T,n,k,a[maxn],d;
bool ch(int x){
    for(int i=1;i+k-1<=n;i++){
        int ans1=-1;
        int t=a[i]+2*x;
        if(a[i+k-1]<=t){
            d=a[i]+x;
            return true;
        }
        }

    return false;
}

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&k);
        k++;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        int l=0,r=a[n],mid;
        while(l<=r){
            mid=(l+r)>>1;
            if(ch(mid)){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        printf("%d\n",d);
    }
}