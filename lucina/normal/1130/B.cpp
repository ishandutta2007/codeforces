#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,x,pos[maxn][2];
long long ans;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=2*n;i++){
        scanf("%d",&x);
        pos[x][0]>0?pos[x][1]=i:pos[x][0]=i;
    }
    ans+=(pos[1][0]-1+pos[1][1]-1);
    for(int i=2;i<=n;i++){
        ans+=(min(abs(pos[i][0]-pos[i-1][0])+abs(pos[i][1]-pos[i-1][1]),abs(pos[i][0]-pos[i-1][1])+abs(pos[i][1]-pos[i-1][0])));
    }
    printf("%lld\n",ans);
}