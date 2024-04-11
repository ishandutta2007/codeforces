#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,k,a[1005],x,ans,lf;

int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&x);
        a[x]++;
    }
    lf=(n+1)/2;
    for(int i=1;i<=1000;i++){
        if(a[i]){
            lf-=a[i]/2;
            ans+=(2*(a[i]/2));
            a[i]%=2;
        }
    }
    printf("%d\n",ans+lf);
}
/*
    Good Luck
        -Lucina
*/