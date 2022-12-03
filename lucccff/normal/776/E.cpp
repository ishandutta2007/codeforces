#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

typedef long long LL;

const int MAXN=1000100;
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

LL f(LL n) {
    LL ans=n;
    for(int i=1;prime[i]<=n/prime[i];i++) {
        if (n%prime[i]==0) {
            ans=ans/prime[i]*(prime[i]-1);
            while(n%prime[i]==0) n/=prime[i];
        }
    }
    if (n>1) ans=ans/n*(n-1);
    return ans;
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    LL i,j,k,l,m,n,t;
    cin>>n>>k;
    getPrime();
    k=(k+1)/2;
    while(k>0&&n>1) {
        k--;
        n=f(n);
    }
    cout<<n%MOD<<endl;
    return 0;
}