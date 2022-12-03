#include <bits/stdc++.h>
using namespace std;

const int MAXN=100000;
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


int main() {
    long long i,j,l,m,n,t,a,b,k;
    cin>>t;
    getPrime();
    for(i=0;i<t;i++) {
        cin>>a>>b>>k;
        m=0;
        getFactors(a);
        for(j=0;j<fatCnt;j++) {
            m+=factor[j][1];
        }
        getFactors(b);
        for(j=0;j<fatCnt;j++) {
            m+=factor[j][1];
        }
        if (a==b) {
            if (k>=0&&k<=m&&k!=1) {
                cout<<"YES\n";
            }
            else {
                cout<<"NO\n";
            }
        }
        else if (a%b==0||b%a==0) {
            if (k>=1&&k<=m) {
                cout<<"YES\n";
            }
            else {
                cout<<"NO\n";
            }
        }
        else {
            if (k>=2&&k<=m) {
                cout<<"YES\n";
            }
            else {
                cout<<"NO\n";
            }
        }
    }
    return 0;
}