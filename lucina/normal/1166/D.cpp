#include<bits/stdc++.h>
using namespace std;
#define ll long long
int q;
ll p[52],a,b,m,r[52],c[52];
bool ch(int k){
    memset(r,0,sizeof(r));
    double x,y,z;
    x=a,y=b,z=p[k-2];
    if(y-z*x<0)return false;
    ll res=(b-(p[k-2]*a));
    int pt=0;
    c[k-1]=1;
    for(int i=k-2;i>=1;i--){
        c[i]=p[pt];pt++;
    }
    for(int i=1;i<=k-1;i++){
        if(res>=c[i]){
            res-=c[i];
            r[i]=1;
        }
    }
    for(int i=1;i<=k-1;i++){
        ll f=(res/c[i]);
        f=min(m-1,f);
        res-=(c[i]*f);
        r[i]+=f;
    }
    if(res>0){
        return false;
    }
    bool ch=true;
    for(int i=1;i<=k-1;i++){
        ch&=(r[i]>=1&&r[i]<=m);
    }
    if(!ch)return false;
        printf("%d %lld ",k,a);
        ll s=a;
        printf("%lld ",s+r[1]);
        s+=r[1];
        for(int i=3;i<=k;i++){
            s=2*s+r[i-1]-r[i-2];
            printf("%lld ",s);
        }
        printf("\n");
        return true;
}

int main(){
    scanf("%d",&q);
    p[0]=1;
    for(int i=1;i<=50;i++)
        p[i]=p[i-1]<<1;
    while(q--){
        scanf("%lld%lld%lld",&a,&b,&m);
        if(a==b){
                printf("1 %lld\n",a);
                continue;
        }
        bool x=false;
        for(int i=2;i<=50;i++){
            x|=ch(i);
            if(x)break;
        }
        if(!x)printf("-1\n");
    }

}