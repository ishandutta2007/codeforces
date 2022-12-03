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

/*long long factor[100][2];
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
}*/

int main(){
    int i,j,k,m,n,s=0,num;
    long long sum,l;
    int a[100010],b[100010],c[10010];
    cin>>n;
    for(i=0;i<n;i++) {
        cin>>a[i];
        s+=a[i];
        b[i]=s;
    }
    if (s==1) {
        cout<<-1;
        return 0;
    }

    num=0;
    for(i=1;i*i<s;i++) {
        if (s%i==0) {
            c[num++]=i;
            c[num++]=s/i;
        }
    }
    if (i*i==s) c[num++]=i;
    sum=100000000000;
    for(i=1;i<num;i++) {
        l=0;
        k=0;
        for(j=0;j<s/c[i];j++) {
            int p=0;
            if (a[k]==1) p=1;
            while(p<=c[i]/2) {
                k++;
                l+=p;
                if (a[k]==1) p++;
            }
            
            while(p<=c[i]) {
                k++;
                l+=c[i]-p;
                if (a[k]==1) p++;
            }
        }
        if (l<sum) sum=l;
    }
    cout<<sum;

    return 0;
}