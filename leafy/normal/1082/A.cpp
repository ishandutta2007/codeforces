#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
int n,x,y,d;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d%d",&n,&x,&y,&d);
        if(abs(y-x)%d==0){
            printf("%d\n",abs(y-x)/d);
            continue;
        }
        int ans=-1;
        if(y%d==1){
            ans=y/d+(x+d-1)/d;
        }
        if((n-y)%d==0){
            if(ans==-1) ans=(n-x+d-1)/d+(n-y)/d;
            else ans=min(ans,(n-x+d-1)/d+(n-y)/d);
        }
        printf("%d\n",ans);
    }
    return 0;
}