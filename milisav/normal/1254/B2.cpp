#include<bits/stdc++.h>
using namespace std;
int n;
long long a[2000000];
long long b[2000000];
long long inf=1e18;
long long count(long long p) {
    long long t=0;
    int j=0;
    long long rt=0;
    for(int i=0;i<n;i++) b[i]=a[i]%p;
    for(int i=0;i<n;i++) {
        t+=b[i];
        if(t>=p) {
            long long q=(p+1)/2;
            long long r=p;
            for(int k=j;k<=i;k++) {
                q-=b[k];
                if(q<=0) {
                    for(int l=j;l<=i;l++) {
                        rt+=min(r,b[l])*abs(k-l);
                        r-=min(r,b[l]);
                    }
                    break;
                }
            }
            t-=p;
            b[i]=t;
            if(t>0) j=i;
            else j=i+1;
        }
    }

    return rt;
}
int main() {
    scanf("%d",&n);
    long long s=0;
    for(int i=0;i<n;i++) {
        scanf("%d",&a[i]);
        s+=a[i];
    }
    long long ans=inf;
    for(long long p=2;p*p<=s;p++) {
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