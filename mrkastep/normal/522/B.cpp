#include<stdio.h>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<math.h>     
#include<queue>
using namespace std;
  
long long int n,st[200005],w[200005],h[200005];

void solve() {
    long long int i,j,q,k,maxi1=0,maxi2=0,sum=0;
    q=0;
    for(i=0;i<n;i++) {
        scanf("%I64d%I64d",&w[i],&h[i]);
        sum+=w[i];
        if(maxi1<h[i]) {
            maxi1=h[i];
            q=i;
        }
    }
    for(i=0;i<n;i++) {
        if(i!=q) {
            maxi2=max(maxi2,h[i]);
        }
    }
    for(i=0;i<n;i++) {
        if(i!=q) {
            printf("%I64d ",(sum-w[i])*maxi1);
        }else{
            printf("%I64d ",(sum-w[i])*maxi2);
        }
    }
    return;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    scanf("%I64d",&n);
    solve();
    return 0;
}