#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

const int MAXN=10000;
const int N=200000;
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
long long factor[100][2];
int fatCnt;
int getFactors(long long x){
    fatCnt=0;
    long long tmp=x;
    for(int i=1;prime[i]<=tmp/prime[i];i++){
        factor[fatCnt][1]=0;
        if(tmp%prime[i]==0){
            factor[fatCnt][0]=prime[i];
            while(tmp%prime[i]==0){
                factor[fatCnt][1]++;
                tmp/=prime[i];
            }
            fatCnt++;
        }
    }
    if(tmp!=1){
        factor[fatCnt][0]=tmp;
        factor[fatCnt++][1]=1;
    }
    return fatCnt;
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long i,j,k,l,m,n,t;
    long long a[200010],f[200010][20],b[200010],c[200010];
    getPrime();
    for(i=1;i<=N;i++) {
        getFactors(i);
        f[i][0]=fatCnt;
        for(j=0;j<fatCnt;j++) {
            f[i][j+1]=factor[j][0];
        }
    }

    scanf("%d",&t);
    for(i=0;i<t;i++) {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        scanf("%d",&n);
        for(j=0;j<n;j++) {
            scanf("%d",&k);
            a[k]++;
        }
        for(j=N;j>=1;j--) {
            a[j]+=b[j];
            for(k=1;k<=f[j][0];k++) {
                if (a[j]>b[j/f[j][k]]) b[j/f[j][k]]=a[j];
            }
        }
        cout<<n-a[1]<<endl;
    }
    return 0;
}