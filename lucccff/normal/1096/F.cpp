#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int a[200010],b[200010],c[200010],d[200010],n;

LL inv(LL x) {
    if (x==1) return 1;
    else return inv(MOD%x)*(MOD-MOD/x)%MOD;
}

int q[200010];

void add(int x) {
    while(x<=n) {
        q[x]++;
        x+=x&(-x);
    }
}

int gets(int x) {
    int ans=0;
    while(x>=1) {
        ans+=q[x];
        x-=x&(-x);
    }
    return ans;
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int i,j,k,l,m,t,s=0;
    LL ans=0;
    cin>>n;
    for(i=1;i<=n;i++) {
        cin>>a[i];
        if (a[i]!=-1) {
            b[a[i]]=i;
            c[i]=c[i-1];
        }
        else {
            s++;
            c[i]=c[i-1]+1;
        }
    }
    ans=0;
    for(i=n;i>=1;i--) {
        if (b[i]) {
            ans+=gets(b[i]);
            add(b[i]);
        }
    }
    for(i=1;i<=n;i++) {
        if (b[i]) {
            d[i]=d[i-1];
        }
        else {
            d[i]=d[i-1]+1;
        }
    }
    ans+=inv(4)*s%MOD*(s-1);
    ans%=MOD;
    if (s>0) t=inv(s);
    else t=0;
    for(i=1;i<=n;i++) {
        if (b[i]) {
            ans+=(1ll*d[i]*(s-c[b[i]])+1ll*(s-d[i])*c[b[i]])%MOD*t;
            ans%=MOD;
        }
    }
    cout<<ans;
    return 0;
}