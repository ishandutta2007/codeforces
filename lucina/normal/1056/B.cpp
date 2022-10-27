#include<stdio.h>
long long x[2000];
int n,m;
long long ans;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        if(i>n)
        break;
        x[i]=(n-i)/m+1;
    }
    x[0]--;
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            if((i*i+j*j)%m==0){
                ans+=(long long)x[i]*x[j];
            }
        }
    }
    printf("%lld\n",ans);


}