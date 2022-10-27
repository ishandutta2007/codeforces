#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int b[maxn],x,y,n;
long long sum1,sum2,m;
int main(){
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&x,&y);
        b[i]=x-y;
        sum2+=y,sum1+=x;
    }
    if(sum2>m){
        printf("-1\n");
        return 0;
    }
    sort(b+1,b+1+n);
    for(int i=n;i>=0;i--){
        if(sum1<=m){
            printf("%d ",n-i);
            return 0;
    }
    else
        sum1-=b[i];
    }
}