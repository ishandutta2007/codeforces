#include<bits/stdc++.h>
using namespace std;
int n,b[1000000];
int main(){
    scanf("%d",&n);
    if(n==1){
        printf("1 0");
        return 0;
    }
    int ans=1;
    int t=0,x,maxp=0;
    bool check=true;
    for(int i=2;i<=n;i++){
            if(n%i==0){
                ans*=i;
            t++;
            while(n%i==0){
                b[t]++;
                n/=i;
            }
            if(b[t]>maxp)maxp=b[t];
        }
    }
    for(int i=1;i<=t;i++){
        if(b[i]!=maxp) check=false;
    }
    int sum=0;
    int f=1,l=0;
    while(f<maxp){
        f<<=1;
        l++;
    }
    if(check&&f==maxp){
        sum=0;
    }
    else sum++;
    sum+=l;
    printf("%d %d",ans,sum);
}