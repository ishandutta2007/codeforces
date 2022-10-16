#include<cstdio>

int n,x,y,c;

long long calc(int v){
    if(v<=0)
        return 0;
    return 1LL*v*v;
}
long long calc2(int v){
    if(v<=0)
        return 0;
    return 1LL*v*(v+1)/2;
}

bool check(int t){
    long long outer=0;
    outer=1LL*(t+1)*(t+1)*2-1LL*(t+1)*2+1;

    outer-=calc(t+1-x);
    outer-=calc(t+1-y);
    outer-=calc(t-(n-x));
    outer-=calc(t-(n-y));

    outer+=calc2(t-x-y+1);
    outer+=calc2(t-x-(n-y));
    outer+=calc2(t-(n-x)-y);
    outer+=calc2(t-(n-x)-(n-y)-1);

    if(outer>=c)
        return true;
    else
        return false;
}

int main(){
    scanf("%d%d%d%d",&n,&x,&y,&c);
    int l=0,r=n*2,ans;
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid)){
            ans=mid;r=mid-1;
        }else
            l=mid+1;
    }
    printf("%d\n",ans);

    return 0;
}