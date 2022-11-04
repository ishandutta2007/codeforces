#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,m,a[1010];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++) scanf("%d",a+i);
 
        if(m < n || n <= 2){
            printf("-1\n");
            continue;
        }

        ll cost = 0;
        for(int i=1;i<=n;i++) cost += a[i]*2;

        printf("%lld\n",cost);
        for(int i=1;i<=n;i++) printf("%d %d\n",i,i%n+1);
    }
}