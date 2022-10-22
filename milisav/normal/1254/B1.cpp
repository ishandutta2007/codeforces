#include<bits/stdc++.h>
using namespace std;
int n;
int a[2000000];
long long inf=1e18;
long long count(int p) {
    int t=0;
    int j=0;
    long long rt=0;
    for(int i=0;i<n;i++) {
        t+=a[i];
        if(t==p) {
            int q=(p+1)/2;
            for(int k=j;k<=i;k++) {
                q-=a[k];
                if(q==0) {
                    for(int l=j;l<=i;l++) {
                        if(a[l]==1) rt+=abs(k-l);
                    }
                    break;
                }
            }
            j=i+1;
            t=0;
        }
    }
    return rt;
}
int main() {
    scanf("%d",&n);
    int s=0;
    for(int i=0;i<n;i++) {
        scanf("%d",&a[i]);
        s+=a[i];
    }
    long long ans=inf;
    for(int p=2;p*p<=s;p++) {
        if(s%p==0) {
            ans=min(ans,count(p));
            while(s%p==0) s/=p;
        }
    }
    if(s>1) ans=min(ans,count(s));
    if(ans==inf) printf("-1");
    else printf("%lld",ans);
    return 0;
}