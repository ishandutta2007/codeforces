#include<bits/stdc++.h>
using namespace std;
int n,x,ct,d[2][2],q=2019;

void ask(int a,int b,int c,int d){
    printf("? %d %d %d %d\n",a,b,c,d);
    fflush(stdout);
    scanf("%d",&x);
    return;
}
void waste(){
    while(q--)
        ask(1,1,1,1);
    return ;
}
void ans(int a,int b,int c,int d){
    printf("! %d %d %d %d\n",a,b,c,d);
    fflush(stdout);
    return ;
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        ask(i,1,i,n);
        q--;
        if(x&1){
            int l=1,r=n,mid,ans;
            while(l<=r){
                mid=(l+r)>>1;
                ask(i,mid,i,n);q--;
                if(x&1){
                    ans=mid;
                    l=mid+1;
                }
                else
                    r=mid-1;
            }
            d[ct][0]=i,d[ct][1]=ans;
            ct++;
        }
    }
    if(ct){
        waste();
        ans(d[0][0],d[0][1],d[1][0],d[1][1]);
        return 0;
    }
    for(int i=1;i<=n;i++){
        ask(1,i,n,i);
        q--;
        if(x&1){
            if(ct){
                waste();
                ans(d[0][0],d[0][1],d[0][0],i);
                return 0;
            }
            int l=1,r=n,mid,ans;
            while(l<=r){
                mid=(l+r)>>1;
                ask(mid,i,n,i);
                q--;
                if(x&1){
                    ans=mid;
                    l=mid+1;
                }
                else{
                    r=mid-1;
                }
            }

        d[0][0]=ans;d[0][1]=i;
        ct++;
    }
}
}