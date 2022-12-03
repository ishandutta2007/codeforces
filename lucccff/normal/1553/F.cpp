#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;
const int MAX=300000;

long long a[300010],b[300010],c[300010];

int lowbit(int x) {
    return x & -x;
}

void addb(int x, int k) {
    while (x <= MAX) {  // 
        b[x] = b[x] + k;
        x = x + lowbit(x);
    }
}

void addc(int x, int k) {
    while (x <= MAX) {  // 
        c[x] = c[x] + k;
        x = x + lowbit(x);
    }
}


long long getsumb( int k) {
    long long ret = 0;
    while (k) {
        ret += b[k];
        k -= lowbit(k);
    }
    return ret;
}

long long getsumc( int k) {
    long long ret = 0;
    while (k) {
        ret += c[k];
        k -= lowbit(k);
    }
    return ret;
}


int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long i,j,k,l,m,n,t,ans,s;
    cin>>n;
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    ans=0;
    for(i=0;i<n;i++) {
        cin>>a[i];
        addb(a[i],a[i]);
        addc(a[i],1);
        ans+=getsumb(300000)-a[i];
        ans+=(i+2)*a[i];
        l=getsumc(300000);
        for(j=a[i];j<=MAX;j+=a[i]) {
            ans-=(l-getsumc(j-1))*a[i];
        }
        l=0;
        for(j=1;j*j<=a[i];j++) {
            m=getsumc(j);
            ans+=(m-l)*(a[i]%j);
            l=m;
        }
        for(j=1;j*j<a[i];j++) {
            ans-=getsumb(a[i]/j);
        }
        k=j-1;
        l=0;
        for(j=1;j*j<=a[i];j++) {
            m=getsumc(j);
            ans-=(m-l)*(a[i]-k*j);
            l=m;
        }
        cout<<ans<<' ';
    }
    return 0;
}