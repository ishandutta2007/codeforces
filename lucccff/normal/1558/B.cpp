#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int a[4000010],n,p;

int lowbit(int x) {
    return x&(-x);
}

void addk(int x,int k) {
    if (k>0) {
        while(x<=n) {
            a[x]+=k;
            if (a[x]>=p) a[x]-=p;
            x+=lowbit(x);
        }
    }
    else {
        while(x<=n) {
            a[x]+=k;
            if (a[x]<0) a[x]+=p;
            x+=lowbit(x);
        }
    }
}

int getsum(int x) {
    int ans=0;
    while(x>0) {
        ans+=a[x];
        if (ans>=p) ans-=p;
        x-=lowbit(x);
    }
    return ans;
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long i,j,k,l,m;
    cin>>n>>p;
    memset(a,0,sizeof(a));
    addk(1,1);
    addk(2,-1);
    k=0;
    m=0;
    for(i=1;i<=n;i++) {
        //addk(i,k);
        k=m+getsum(i);
        if (k>=p) k-=p;
        m+=k;
        if (m>=p) m-=p;
        for(j=0;j<=n;j+=i*(i+1)) {
            for(l=1;l<=i&&l*i+j<=n;l++) {
                addk(l*i+j,k);
                if (l*i+j+l<=n) addk(l*i+j+l,-k);
            }
            if (j+i*(i+1)<=n) addk(j+i*(i+1),k);
        }
    }
    cout<<k<<endl;
    return 0;
}