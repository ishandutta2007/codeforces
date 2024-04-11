#include<bits/stdc++.h>
#define maxn 50000
using namespace std;
int n,m;
int dp[maxn];
int a[maxn];
int main() {
    scanf("%d %d",&n,&m);
    dp[1]=0;
    dp[2]=0;
    if(n<=2) {
        if(m==0) {
            for(int i=1;i<=n;i++) printf("%d ",i);
            return 0;
        }
        else {
            printf("-1");
            return 0;
        }
    }
    for(int i=3;i<=n;i++) {
        dp[i]=dp[i-1]+(i-1)/2;
    }
    if(m>dp[n]) {
        printf("-1");
        return 0;
    }
    if(m==0) {
        for(int i=0;i<n;i++) printf("%d ",n+i);
        return 0;
    }
    int k=n;
    while(m<=dp[k-1]) k--;
    for(int i=1;i<=k-1;i++) a[i]=i;
    int r=m-dp[k-1];
    int l=k-1;
    int t=k;
    //cout<<r<<" "<<l<<endl;
    while(r!=l/2) {
        l--;
        t++;
    }
    a[k]=t;
    t+=5;
    r=2*t+1;
    for(int i=k+1;i<=n;i++) {
        a[i]=r;
        r+=t;
    }
    for(int i=1;i<=n;i++) printf("%d ",a[i]);
    return 0;
}