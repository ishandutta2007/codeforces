#include<bits/stdc++.h>
using namespace std;
int a[20],n,x,b,ans;
char fuck;
int main(){
    for(int i=0;i<20;i++)
        a[i]=2;
    scanf("%d",&n);
    while(n--){
        scanf(" %c %d",&fuck,&x);
    for(int i=0;i<10;i++){
        b=x%2;x=x/2;
        if(fuck=='&'){
            if(b==1) continue;
            else if(b==0){
                a[i]=0;
                continue;
            }
        }
        else if(fuck=='|'){
            if(b==1) {
                a[i]=1;continue;
            }
            else if(b==0){
                continue;
            }
        }
        else if(fuck=='^'){
            if(a[i]!=1&&a[i]!=0){
                if(b==1){
                    a[i]=-a[i];
                    continue;
                }
                else continue;
            }
            else{
                a[i]=a[i]^b;
                continue;
            }
        }
    }
    }
    printf("%d\n",3);
    int t=1;
    ans=0;
    for(int i=0;i<10;i++){
        if(a[i]==1){
            ans+=t;
        }
        t*=2;
    }
    printf("| %d\n",ans);
    ans=0,t=1;
    for(int i=0;i<10;i++){
        ans+=t;
        if(a[i]==0)
            ans-=t;
        t*=2;
    }
    printf("& %d\n",ans);
    ans=0,t=1;
    for(int i=0;i<10;i++){
        if(a[i]==-2)
            ans+=t;
        t*=2;
    }
    printf("^ %d\n",ans);


}