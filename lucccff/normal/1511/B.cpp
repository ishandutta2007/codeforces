#include <bits/stdc++.h>
using namespace std;

const int MAXN=200000;
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

int main(){
    int i,j,k,l,m,n,t,a,b,c;
    getPrime();
    cin>>t;
    for(i=0;i<t;i++){
        cin>>a>>b>>c;
        a=a-c+1;
        b=b-c+1;
        k=n=1;
        if (a>5) {
            k=prime[6000];
        }
        if (b>5) {
            n=prime[6001];
        }

        for(j=1;j<=prime[0];j++) {
            m=prime[j]*k;
            l=0;
            while(m!=0) {
                l++;
                m=m/10;
            }
            if ((j!=6001)&&(l==a)) break;
        }
        
        k=k*prime[j];
        int s=prime[j];

        for(j=1;j<=prime[0];j++) {
            m=prime[j]*n;
            l=0;
            while(m!=0) {
                l++;
                m=m/10;
            }
            if ((prime[j]!=s)&&(j!=6000)&&(l==b)) break;
        }
        
        n=n*prime[j];

        for(j=1;j<c;j++) {
            k=k*10;
            n=n*10;
        }
        cout<<k<<' '<<n<<endl;
    }
    return 0;
}