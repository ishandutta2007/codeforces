#include<bits/stdc++.h>
using namespace std;
int p[35],a,b,x,d,s,t,r,u,v;

int main(){
    p[0]=1;
    for(int i=1;i<=30;i++)
        p[i]=p[i-1]<<1;
    printf("? %d %d\n",0,0);
    fflush(stdout);
    scanf("%d",&x);
    for(int i=29;i>=0;i--){
        printf("? %d %d\n",a+p[i],b);
        fflush(stdout);
        scanf("%d",&u);
        printf("? %d %d\n",a,b+p[i]);
        fflush(stdout);
        scanf("%d",&v);
        if(u==v){
            if(x==1)
                a+=p[i];
            else
                b+=p[i];
            x=u;
        }
        else{
            if(u==-1)
                a+=p[i],b+=p[i];
        }
    }
    printf("! %d %d\n",a,b);
    fflush(stdout);
}