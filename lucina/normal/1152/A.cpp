#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,m,a[2],x,ans;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&x);
        a[x%2]++;
    }
    for(int i=1;i<=m;i++){
        scanf("%d",&x);
        if(a[(x%2)^1]){
            ans++;
            a[(x%2)^1]--;
        }
    }
    printf("%d\n",ans);

}