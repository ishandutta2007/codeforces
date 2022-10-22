#include<bits/stdc++.h>
#define maxn 500000
#define maxl 25000000
using namespace std;
int n;
int a[maxn];
int c[maxl];
int sum(int l,int r) {
    r=min(r,maxl-1);
    if(l>=maxl) return 0;
    if(l<=0) return c[r];
    return c[r]-c[l-1];
}
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%d",&a[i]);
        c[a[i]]++;
    }
    for(int i=1;i<maxl;i++) c[i]+=c[i-1];
    int k=1<<24;
    int ans=0;
    while(k>0) {
        long long x=0;
        for(int i=0;i<n;i++) {
            x=x+sum(k-a[i],2*k-1-a[i]);
            if(a[i]>=k-a[i] && a[i]<=2*k-1-a[i]) x--;
            x=x+(sum(3*k-a[i],4*k-1-a[i]));
            if(a[i]>=3*k-a[i] && a[i]<=4*k-1-a[i]) x--;
        }
        x/=2;
        if(x&1ll) ans|=k;
        for(int i=0;i<n;i++) if(a[i]&k) a[i]^=k;
        for(int i=0;i<min(maxl,4*k);i++) c[i]=0;
        for(int i=0;i<n;i++) c[a[i]]++;
        for(int i=1;i<min(maxl,4*k);i++) c[i]+=c[i-1];
        k>>=1;
    }
    printf("%d",ans);
    return 0;
}