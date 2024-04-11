#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

long long inv1(long long a){
    long long m=MOD;
    if(a == 1) return 1;
    return inv1(m%a)*(m-m/a)%m;
}

int main(){
    std::ios::sync_with_stdio(false);
    long long i,j,k,l,m,n,t,q,ans,x;
    long long a[200010],b[200010],c[200010],d[200010],next[200010],f[200010],p[200010];
    long long inv[200];
    inv[1]=1;
    inv[0]=0;
    m=MOD;
    for(i=2;i<=100;i++) {
        inv[i]=(inv[m%i]*(m-m/i))%m;
    }
    memset(f,0,sizeof(f));
    cin>>n>>q;
    for(i=0;i<n;i++) {
        cin>>a[i];
        c[i]=0;
    }
    c[n]=1;
    d[n]=0;
    for(i=n-1;i>=0;i--) {
        c[i]=((c[i+1]*inv[a[i]]%MOD)*100)%MOD;
        d[i]=(d[i+1]+c[i])%MOD;
    }

    ans=d[0];
    f[0]=f[n]=1;
    p[0]=n;
    x=sqrt(n);
    for(i=0;i*x<n;i++) {
        for(j=1;j+i*x<=n&&j<=x;j++) {
            next[j+i*x]=i*x;
        }
    }
    for(i=0;i<q;i++) {
        cin>>b[i];
        if (f[b[i]-1]==0) {
            f[b[i]-1]=1;
            k=next[b[i]-1];
            while(f[k]==0) {
                k=next[k];
            }
            l=b[i]-1;
            m=p[k];
            p[l]=m;
            p[k]=l;
            j=(l-1)/x;
            if ((m-1)/x!=(l-1)/x) {
                j=(l-1)/x;
                for(int y=l+1;y<=(j+1)*x&&y<=n;y++) next[y]=l;
            }
            else {
                j=(l-1)/x;
                for(int y=l+1;y<=m;y++) next[y]=l;
            }
            ans=(ans+((MOD+d[k]-d[l])%MOD)*(MOD+inv1(c[l])-inv1(c[m]))%MOD)%MOD;
        }
        else {
            f[b[i]-1]=0;
            k=next[b[i]-1];
            l=b[i]-1;
            while(f[k]==0) {
                k=next[k];
            }
            m=p[l];
            p[k]=m;
            if ((k-1)/x==(l-1)/x) {
                j=(l-1)/x;
                if ((m-1)/x!=(l-1)/x) for(int y=l+1;y<=(j+1)*x&&y<=n;y++) next[y]=k;
                else for(int y=l+1;y<=m;y++) next[y]=k;
            }
            else {
                j=(l-1)/x;
                if ((m-1)/x!=(l-1)/x) for(int y=l+1;y<=(j+1)*x&&y<=n;y++) next[y]=j*x;
                else for(int y=l+1;y<=m;y++) next[y]=j*x;
            }
            ans=(ans+((MOD+d[k]-d[l])%MOD)*(MOD+inv1(c[m])-inv1(c[l]))%MOD)%MOD;
        }
        ans=(ans+MOD)%MOD;
        cout<<ans<<endl;
    }
    return 0;
}