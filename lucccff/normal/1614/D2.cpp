#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int a[20000010];
LL b[20000010];
int p[100010],q[1010];

const int MAXN=20000030;
int prime[MAXN+1];
void getPrime(){
    memset(prime,0,sizeof(prime));
    for(int i=2;i<=MAXN;i++){
        if(!prime[i])prime[++prime[0]]=i;
        for(int j=1;j<=prime[0]&&prime[j]<=MAXN/i;j++){
            prime[prime[j]*i]=1;
            if(i%prime[j]==0) break;
        }
    }
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int i,j,k,l,m,n,t,s=0;
    LL ans=0;
    getPrime();
    cin>>n;
    for(i=0;i<n;i++) {
        cin>>k;
        a[k]++;
    }
    for(i=1;i<=prime[0];i++) {
        k=2e7;
        k/=prime[i];
        for(j=k;j>0;j--) {
            a[j]+=a[j*prime[i]];
        }
    }
    for(i=1;i<=2e7;i++) b[i]=1ll*a[i]*i;
    for(i=1;i<=2e7;i++) {
        if (a[i]) {
            for(j=1;prime[j]*i<=2e7;j++) {
                b[i*prime[j]]=max(b[i*prime[j]],1ll*a[i*prime[j]]*i*(prime[j]-1)+b[i]);
            }
        }
    }
    for(i=1;i<=2e7;i++) ans=max(ans,b[i]);
    cout<<ans<<endl;
    return 0;
}