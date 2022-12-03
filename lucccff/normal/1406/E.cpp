#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

const int MAXN=100010;
long long prime[MAXN+1];
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
    fatCnt=1;
    long long tmp=x,l,k,s=x;
    for(int i=1;prime[i]<=tmp;i++){
        cout<<'B'<<' '<<prime[i]<<endl<<flush;
        cin>>l;
        x-=l;
        /*cout<<'A'<<' '<<prime[i]<<endl<<flush;
        cin>>l;
        if (l){
            k=prime[i];
            while(l&&k<=tmp) {
                k*=prime[i];
                cout<<'A'<<' '<<k<<endl<<flush;
                cin>>l;
            }
            fatCnt*=k/prime[i];
            tmp/=k/prime[i];
        }*/
        if (i%100==0||prime[i+1]>tmp) {
            cout<<'A'<<' '<<1<<endl<<flush;
            cin>>l;
            if (l!=x) {
                x=l;
                for(int j=(i-1)/100*100+1;j<=i;j++) {
                    cout<<'A'<<' '<<prime[j]<<endl<<flush;
                    cin>>l;
                    if (l){
                        k=prime[j]*prime[j];
                        while(l&&k<=tmp) {
                            cout<<'A'<<' '<<k<<endl<<flush;
                            cin>>l;
                            k*=prime[j];
                        }
                        if (l==1) {
                            fatCnt*=k/prime[j];
                            tmp/=k/prime[j];
                        }
                        else {
                            fatCnt*=k/prime[j]/prime[j];
                            tmp/=k/prime[j]/prime[j];
                        }
                    }
                }
            }
        }
    }
    return fatCnt;
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long i,j,k,l,m,n,t;
    getPrime();
    cin>>n;
    k=getFactors(n);
    cout<<'C'<<' '<<k<<endl<<flush;
    return 0;
}