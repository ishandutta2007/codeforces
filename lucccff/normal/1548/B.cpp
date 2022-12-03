#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

long long a[200010],b[200010],c[600010],d[600010],e[600010],g[600010];

void build(int l,int r,int i) {
    if (l!=r) {
        build(l,(l+r)/2,i<<1);
        build((l+r)/2+1,r,(i<<1)|1);
        c[i]=__gcd(c[i<<1],c[(i<<1)|1]);
    }
    else c[i]=b[l];
}

long long get(int l,int r,int s,int t,int i) {
    /*if (s>=l&&t<=r) {
        return c[i];
    }
    else {
        long long m=0;
        if ((s+t)/2>=l) m=__gcd(m,get(l,r,s,(s+t)/2,i<<1));
        if ((s+t)/2<r) m=__gcd(m,get(l,r,(s+t)/2+1,t,(i<<1)|1));
        return m;
    }*/
    d[0]=s;
    e[0]=t;
    g[0]=i;
    int x,y;
    long long ans=0;
    x=0;
    y=1;
    while(x<y) {
        if (d[x]>=l&&e[x]<=r) ans=__gcd(ans,c[g[x]]);
        else {
            if ((d[x]+e[x])/2>=l) {
                d[y]=d[x];
                e[y]=(d[x]+e[x])/2;
                g[y]=g[x]<<1;
                y++;
            }
            if ((d[x]+e[x])/2<r) {
                d[y]=(d[x]+e[x])/2+1;
                e[y]=e[x];
                g[y]=(g[x]<<1)|1;
                y++;
            }
        }
        x++;
    }
    return ans;
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long i,j,k,l,m,n,t,s,r,x,f;
    cin>>t;
    while(t--) {
        cin>>n;
        for(j=0;j<n;j++) {
            cin>>a[j];
        }
        if (n==1) {
            cout<<1<<endl;
            continue;
        }
        for(j=1;j<n;j++) b[j]=abs(a[j]-a[j-1]);
        build(1,n-1,1);
        l=1;
        r=n-1;
        m=(l+r)/2;
        while(l<r) {
            m=(l+r)/2;
            f=1;
            for(j=1;j<=n-m;j++) {
                if (get(j,j+m-1,1,n-1,1)!=1) {
                    f=0;
                    break;
                }
            }
            if (f==0) {
                l=m+1;
            }
            else {
                r=m-1;
            }
        }
        m=(l+r)/2;
        if (m<=0) m=1;
        f=1;
        for(j=1;j<=n-m;j++) {
            if (get(j,j+m-1,1,n-1,1)!=1) {
                f=0;
                break;
            }
        }
        if (f==0) cout<<m+1<<endl;
        else cout<<m<<endl;
    }
    return 0;
}