#include<cstdio>
#include<iostream>
#include<cmath> 
using namespace std;
const int N = 200000 + 5;
int n,k,q,l,r,d[N],c[N],maxn,sum[N];
int main(){
    scanf("%d%d%d",&n,&k,&q);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&l,&r);
        d[l]++,d[r+1]--;
    }
    for(int i=1;i<=200000;i++){
        c[i] = c[i-1] + d[i];
        sum[i] = sum[i-1] + (c[i]>=k?1:0);
    } 
    for(int i=1;i<=q;i++){
        scanf("%d%d",&l,&r);
        printf("%d\n",sum[r]-sum[l-1]);
    }
    return 0;
}