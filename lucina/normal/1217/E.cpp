/**
    Finally my own implementation :D
*/
#include<bits/stdc++.h>
using namespace std;
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
const int maxn=1e9+7,N=2e5+10,MM=2e9+7;
struct pa{
    int x,y;
    pa () :x(maxn), y(maxn){}
    pa(int _x,int _y) :x(_x) ,y(_y){}
    pa operator +(const pa & a) const{
        pa ret = *this;
        if(a.x < x){
            ret.x = a.x;
            ret.y = x;
            if(a.y <ret.y)
                ret.y = a.y;
        }
        else if(a.x < y) ret.y = a.x;
        return ret;
    }
}sg[16][524288];
const pa inf ={maxn,maxn};
int dig;
inline void update(int v,int l,int r,int pos,int val){
    if(l==r){
        return (void)(sg[dig][v] = pa(val,maxn));

    }
    int mid=l+r>>1;
    (pos>mid)? update(v*2+1,mid+1,r,pos,val): update(v*2,l,mid,pos,val);
    return (void)(sg[dig][v] = sg[dig][v*2] + sg[dig][v*2+1]);
}
inline pa getmin(int v,int x,int y,int l, int r){
    if(l > r)return inf;
    if(l==x && r==y){
        return sg[dig][v];
    }
    int mid=x+y>>1;
    return getmin(v*2,x,mid,l,min(r,mid)) + getmin(v*2+1,mid+1,y,max(l,mid+1),r);
}
int n,q,s,ret,cur,ans;
pa res ;

int main(){
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%d", &s);
        cur=s;
        for (dig = 0 ;dig < 9; dig++){
            (s%10) ? update(1,1,n,i,cur) : update(1,1,n,i,maxn);
            s/=10;
        }
    }
    int ty,x,y;
    while(q--){
        scanf("%d %d %d",&ty, &x, &y);
        if(ty == 1){
            cur = y;
            for(dig = 0;dig <9 ;dig++){
                (y%10) ? update(1,1,n,x,cur) : update(1,1,n,x,maxn);
                y/=10;
            }
        }
        else{
            ans = MM;
            for (dig =0;dig<9; dig++){
                res= getmin(1,1,n,x,y);
                if(res.x !=maxn && res.y !=maxn)
                ans = min(ans, res.x + res.y);
            }
            printf("%d ",ans==MM? -1: ans);
        }
    }
}