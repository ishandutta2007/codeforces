#include<bits/stdc++.h>
using namespace std;
int n,m,c,x,pt,a[1005];

int main(){
    scanf("%d%d%d",&n,&m,&c);
    while(m--){
        scanf("%d",&x);
        if(x*2>c)for(pt=n;a[pt]>=x;--pt);
        else for(pt=1;x>=a[pt]&&a[pt]>0;++pt);
        printf("%d\n",pt);
        fflush(stdout);
        a[pt]=x;
        x=1;
        for(int i=1;i<=n;i++)
            if(a[i]==0){
                x=0;
                break;
            }
        if(x)return 0;
    }
}