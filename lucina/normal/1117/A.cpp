#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,a[maxn],ma,ans;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        ma=max(ma,a[i]);
    }
    int pt;
    for(int i=1;i<=n;i++){
         pt=i;
        while(a[i]==ma&&i<=n){
            i++;
        }
        ans=max(ans,i-pt);
    }
    printf("%d\n",ans);
}