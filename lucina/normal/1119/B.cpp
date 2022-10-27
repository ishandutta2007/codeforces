#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,a[maxn],ans,b[maxn];
long long h,sum;
int main(){
    scanf("%d%lld",&n,&h);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
            sum=0;
            for(int j=1;j<=i;j++){
                b[j]=a[j];
            }
            sort(b+1,b+1+i);
        for(int j=i;j>=1;j-=2){
            sum+=max(b[j],b[j-1]);
        }
        if(sum<=h){
            ans=max(ans,i);
        }
    }
    printf("%d\n",ans);

}
/*
    Lucina
*/