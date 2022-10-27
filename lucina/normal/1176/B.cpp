#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int a[3],t,n,x;

int main(){
    scanf("%d",&t);
    while(t--){
        memset(a,0,sizeof(a));
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&x);
            a[x%3]++;
        }
        int sum=a[0]+min(a[1],a[2]);
        int left=max(a[1],a[2])-min(a[1],a[2]);
        printf("%d\n",sum+left/3);
    }

}