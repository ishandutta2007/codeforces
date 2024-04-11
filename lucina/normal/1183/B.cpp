#include<bits/stdc++.h>
using namespace std;
const int inf=1e9;
const int maxn=3e5+10;
int q,n,k,a;

int main(){
    scanf("%d",&q);
    while(q--){
        scanf("%d%d",&n,&k);
        int l=-inf,r=inf;
        for(int i=1;i<=n;i++){
            scanf("%d",&a);
            r=min(r,a+k);
            l=max(l,a-k);
            }
        printf("%d\n",l<=r?r:-1);
    }
}