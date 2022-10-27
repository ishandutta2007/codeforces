#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,a[maxn],ans;

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int pt=0,pre=0;
    for(int i=1;i<=n;i++){
        while(a[pt+1]==a[i]&&pt<=n)
            pt++;
        ans=max(ans,min(pt-i+1,pre));
        pre=pt-i+1;
        i=pt;
        pt++;
    }
    printf("%d\n",2*ans);


}