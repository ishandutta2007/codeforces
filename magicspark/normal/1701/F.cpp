#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=200005;
typedef long long ll;
int ls[N],rs[N],val[N],rnd[N],sz[N],tot,root;
ll sum[N],ans[N],add[N];
int eval(int x){return sz[x]*add[x]+ans[x];}
void pushdown(int x){
    add[ls[x]]+=add[x];
    add[rs[x]]+=add[x];
    sum[x]+=add[x];
    add[x]=0;
}
void update(int x){
    ans[x]=sum[x]+eval(ls[x])+eval(rs[x]);
    sz[x]=1+sz[ls[x]]+sz[rs[x]];
}
void split(int rt,int v,int &rt1,int &rt2){
    if(!rt){rt1=rt2=0;return;}
    pushdown(rt);
    if(val[rt]<=v){
        rt1=rt;
        split(rs[rt],v,rs[rt],rt2);
    }else{
        rt2=rt;
        split(ls[rt],v,rt1,ls[rt]);
    }
    update(rt);
}
int merge(int x,int y){
    if(!x||!y)return x+y;
    if(rnd[x]<rnd[y]){
        pushdown(x);
        rs[x]=merge(rs[x],y);
        update(x);
        return x;
    }else{
        pushdown(y);
        ls[y]=merge(x,ls[y]);
        update(y);
        return y;
    }
}
int new_node(int x,int y){
    tot++;sz[tot]=1;rnd[tot]=rand();val[tot]=x;ls[tot]=rs[tot]=0;sum[tot]=ans[tot]=y;add[tot]=0;return tot;
}
void insert(int x,int y){
    int rtl=0,rtr=0;
    split(root,x,rtl,rtr);
    int rtv=new_node(x,y);
    root=merge(rtl,merge(rtv,rtr));
}
void erase(int x){
    int rtl=0,rtv=0,rtr=0;
    split(root,x-1,rtl,rtv);
    split(rtv,x,rtv,rtr);
    root=merge(rtl,rtr);
}
int func(int x){return 1ll*x*(x-1)/2;}
int q,d,hv[200005];ll fans;
signed main(){
    cin>>q>>d;
    while(q--){
        int x;cin>>x;
        int rt1=0,rt2=0,rt3=0,rt4=0,rt5=0;
        split(root,x-d-1,rt1,rt2);
        split(rt2,x-1,rt2,rt3);
        split(rt3,x,rt3,rt4);
        split(rt4,x+d,rt4,rt5);
        //rt1:[-inf,x-d-1]
        //rt2:[x-d,x-1]
        //rt3:x
        //rt4:[x+1,x+d]
        //rt5:[x+d+1,+inf]
        if(hv[x]){
            add[rt2]--;
            fans-=eval(rt2);
            fans-=func(sum[rt3]);
            root=merge(merge(rt1,rt2),merge(rt4,rt5));
        }else{
            fans+=eval(rt2);
            add[rt2]++;
            int got=sz[rt4];
            rt3=new_node(x,got);
            fans+=func(sum[rt3]);
            root=merge(rt1,merge(rt2,merge(rt3,merge(rt4,rt5))));
        }
        hv[x]^=1;
        cout<<fans<<endl;
    }
    return 0;
}