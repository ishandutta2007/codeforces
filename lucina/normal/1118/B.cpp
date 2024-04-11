#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
long long qs[maxn][2],w[maxn],n,ans,sum;
int main(){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&w[i]);
        qs[i][0]=qs[i-1][0],qs[i][1]=qs[i-1][1];
        qs[i][i&1]+=(w[i]);
        sum+=w[i];
    }
    for(int i=1;i<=n;i++){
        if(((2*(qs[i-1][i&1]-qs[i][(i+1)&1]+qs[n][(i+1)&1]))==(sum-w[i])))
            ans++;
    }
    printf("%lld\n",ans);

}