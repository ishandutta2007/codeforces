#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,a[maxn],sum,b,ans,d;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        sum+=(a[i]);
        }
        ans=sum;
    sort(a+1,a+1+n);

    for(int i=2;i<=n;i++){
        for(int l=2;l<=a[i];l++){
            if(a[i]%l==0){
                d=sum;
                d-=a[i];
                d+=a[i]/l;
                d+=(a[1]*(l-1));
                ans=min(ans,d);
            }
        }
    }
    printf("%d\n",ans);
}