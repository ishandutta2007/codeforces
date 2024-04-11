#include<cstdio>
#include<algorithm>
using namespace std;
const int N=600002;
int n,p,m,q,a[N],lz[N],op,l,r,id,w[N],i;
struct Uzi{
    int val[5],cnt[5];
    void clear(){
        for(int i=0;i<m;i++)
            val[i]=cnt[i]=0;
    }
    void pushup(Uzi A,Uzi B){
        int i,j,k,op;
        for(i=0;i<m;i++)
            val[i]=A.val[i],cnt[i]=A.cnt[i];
        for(k=0;k<m;k++)
            if(B.cnt[k]){
                op=0;
                for(i=0;i<m;i++)
                    if(val[i]==B.val[k]){
                        cnt[i]+=B.cnt[k];
                        op=1;
                        break;
                    }
                if(op)continue;
                for(i=0;i<m;i++)
                    if(!cnt[i]){
                        cnt[i]=B.cnt[k];
                        val[i]=B.val[k];
                        op=1;
                        break;
                    }

                if(!op){
                    j=0;
                    for(i=0;i<m;i++)
                        if(cnt[i]<cnt[j])
                            j=i;
                    if(cnt[j]>B.cnt[k]){
                        for(i=0;i<m;i++)
                            cnt[i]-=B.cnt[k];
                    }
                    else{
                        val[j]=B.val[k];
                        i=cnt[j];
                        cnt[j]=B.cnt[k];
                        for(j=0;j<m;j++)
                            cnt[j]-=i;
                    }
                }
            }
    }
}f[N],Ans;
void Build(int rt,int l,int r){
    w[rt]=r-l+1;
    if(l==r){
        f[rt].val[0]=a[l];
        f[rt].cnt[0]=1;
        return;
    }
    int mid=l+r>>1;
    Build(rt<<1,l,mid);
    Build(rt<<1|1,mid+1,r);
    f[rt].pushup(f[rt<<1],f[rt<<1|1]);
}
void init(){
    scanf("%d%d%d",&n,&q,&p);
    m=100/p;
    for(i=1;i<=n;i++)
        scanf("%d",a+i);
    Build(1,1,n);
}
void Change(int rt,int x){
    f[rt].clear();
    f[rt].val[0]=x;
    f[rt].cnt[0]=w[rt];
    lz[rt]=x;
}
void Pushdown(int rt){
    if(lz[rt]){
        Change(rt<<1,lz[rt]);
        Change(rt<<1|1,lz[rt]);
        lz[rt]=0;
    }
}
void Query(int rt,int l,int r,int x,int y){
    if(x<=l&&r<=y){
        Ans.pushup(Ans,f[rt]);
        return;
    }
    Pushdown(rt);
    int mid=l+r>>1;
    if(x<=mid)
        Query(rt<<1,l,mid,x,y);
    if(y>mid)
        Query(rt<<1|1,mid+1,r,x,y);
}
void Update(int rt,int l,int r,int x,int y,int z){
    if(x<=l&&r<=y){
        Change(rt,z);
        return;
    }
    Pushdown(rt);
    int mid=l+r>>1;
    if(x<=mid)
        Update(rt<<1,l,mid,x,y,z);
    if(y>mid)
        Update(rt<<1|1,mid+1,r,x,y,z);
    f[rt].pushup(f[rt<<1],f[rt<<1|1]);
}
void work(){
    while(q--){
        scanf("%d",&op);
        if(op==2){
            Ans.clear();
            scanf("%d%d",&l,&r);
            Query(1,1,n,l,r);
            printf("%d ",m);
            for(i=0;i<m;i++)
                printf("%d ",Ans.val[i]);
            printf("\n");
        }
        else{
            scanf("%d%d%d",&l,&r,&id);
            Update(1,1,n,l,r,id);
        }
    }
}
int main(){
    init();
    work();
    return 0;
}