// #include <bits/stdc++.h>
// using namespace std;
// const int maxn=300005;
// // int n,maxx[maxn<<2],pos[maxn],tr[maxn];
// int n,a[maxn],pos[maxn],tr[maxn];
// // int rt,tot,pri[maxn],lc[maxn],rc[maxn],val[maxn],maxx_[maxn],sz[maxn];
// // inline void pushup_st(int rt) { maxx[rt]=max(maxx[rt<<1],maxx[(rt<<1)|1]); }
// // void build(int rt,int l,int r)
// // {
// //     if(l==r) { scanf("%d",&maxx[rt]); pos[maxx[rt]]=l; return; }
// //     int mid=(l+r)>>1;
// //     build(rt<<1,l,mid),build((rt<<1)|1,mid+1,r);
// //     pushup_st(rt);
// // }
// // int query(int rt,int l,int r,int x,int y)
// // {
// //     if(x<=l && r<=y) return maxx[rt];
// //     int mid=(l+r)>>1,res=0;
// //     if(x<=mid) res=max(res,query(rt<<1,l,mid,x,y));
// //     if(mid<y) res=max(res,query((rt<<1)|1,mid+1,r,x,y));
// //     return res;
// // }
// // void erase(int rt,int l,int r,int x)
// // {
// //     if(l==r) { maxx[rt]=0; return; }
// //     int mid=(l+r)>>1;
// //     if(x<=mid) erase(rt<<1,l,mid,x);
// //     else erase((rt<<1)|1,mid+1,r,x);
// //     pushup_st(rt);
// // }

// // inline void pushup_treap(int x) { sz[x]=sz[lc[x]]+sz[rc[x]]+1,maxx_[x]=max(val[x],max(maxx_[lc[x]],maxx_[rc[x]])); }
// // inline int newnode(int x)
// // {
// //     // printf("newnode %d\n",x);
// //     val[tot]=x;
// //     lc[tot]=rc[tot]=0,pri[tot]=rand(),pushup_treap(tot);
// //     return tot++;
// // }
// // void split(int rt,int &l,int &r,int x)
// // {
// //     if(!rt) { l=r=0; return; }
// //     if(x<val[rt]) r=rt,split(lc[rt],l,lc[r],x),pushup_treap(r);
// //     else l=rt,split(rc[rt],rc[l],r,x),pushup_treap(l);
// // }
// // void split_sz(int rt,int &l,int &r,int x)
// // {
// //     if(!rt) { l=r=0; return; }
// //     if(x<=sz[lc[rt]]) r=rt,split_sz(lc[rt],l,lc[r],x),pushup_treap(r);
// //     else l=rt,split_sz(rc[rt],rc[l],r,x-sz[lc[rt]]-1),pushup_treap(l);
// // }
// // void merge(int &rt,int l,int r)
// // {
// //     if(!l || !r) { rt=l|r; return; }
// //     if(pri[l]<pri[r]) rt=l,merge(rc[rt],rc[l],r);
// //     else rt=r,merge(lc[rt],l,lc[r]);
// //     pushup_treap(rt);
// // }
// // inline int query(int rt,int k)
// // {
// //     int res=0;
// //     for(;rt;)
// //         if(maxx_[lc[rt]]>k)
// //             rt=lc[rt];
// //         else if(val[rt]>k)
// //             return res;
// //         else res+=sz[lc[rt]]+1,rt=rc[rt];
// //     return res;
// // }

// #define lowbit(x) ((x)&-(x))
// inline void update(int x,int z)
// {
//     // printf("update %d\n",x);
//     // for(;x<=n;x+=lowbit(x))
//     //     tr[x]++/*,printf("update %d\n",x)*/;
//     for(;x;x-=lowbit(x))
//         tr[x]+=z;
// }
// inline int query(int x)
// {
//     int res=0;
//     // for(;x;x-=lowbit(x))
//     for(;x<=n;x+=lowbit(x))
//         res+=tr[x];
//     return res;
// }
// // inline int kth(int x)
// // {
// //     int i,res=0;
// //     for(i=1;(i<<1)<=n;i<<=1);
// //     for(;i;i>>=1)
// //         if(res+i<=n && tr[res+i]<x)
// //             x-=tr[res+i],res+=i;
// //     // assert(!x);
// //     return res+1;
// // }
// // set<int> s;
// int main()
// {
//     // int i,x,t,a,b,c,k,temp;
//     // set<int>::iterator it;
//     // scanf("%d",&n);
//     // build(1,1,n);
//     // sz[0]=0,maxx_[0]=0x80000000,tot=1,rt=0;
//     // for(i=1;i<=n;i++) tr[i]=0;
//     // // s.clear();
//     // for(i=0;i<n;i++)
//     // {
//     //     printf("%d ",maxx[1]);
//     //     if(i==n-1) break;
//     //     scanf("%d",&x);
//     //     // printf("\n! %d\n",query(1,1,n,1,x));
//     //     // t=query(x);
//     //     // split_sz(rt,a,b,t);
//     //     a=0,b=rt;
//     //     k=query(b,x);
//     //     // printf("\n!%d\n",k);
//     //     if(!k)
//     //     {
//     //         erase(1,1,n,temp=pos[query(1,1,n,1,x)]);
//     //         // merge(b,newnode(temp),b);
//     //     }
//     //     else
//     //     {
//     //         // split(b,b,c,k);
//     //         // printf("! %d\n",kth(sz[a]+k));
//     //         erase(1,1,n,temp=pos[query(1,1,n,1,kth(sz[a]+k))]);
//     //         // merge(b,b,newnode(temp));
//     //         // merge(b,b,c);
//     //         // split(b,b,c,x);
//     //         // merge(b,b,newnode(temp));
//     //         // merge(b,b,c);
//     //     }
//     //     // it=s.lower_bound(x);
//     //     // erase(1,1,n,temp=pos[query(1,1,n,1,(it==s.end())?x:*it)]);
//     //     // s.insert(x);
//     //     merge(rt,a,b);
//     //     split(rt,a,b,temp);
//     //     merge(b,newnode(temp),b);
//     //     merge(rt,a,b);
//     //     /*printf("%d\n",x);*/update(x);
//     //     // printf("removed %d\n",temp);
//     // }
//     // printf("\n");
//     int i,x,k;
//     scanf("%d",&n);
//     for(i=1;i<=n;i++) scanf("%d",&a[i]),pos[a[i]]=i,tr[i]=0;
//     for(i=1,k=n;i<=n;i++)
//     {
//         printf("%d ",k);
//         if(i==n) break;
//         scanf("%d",&x);
//         update(x,-1);
//         for(;query(pos[k])<0;k--)
//             update(pos[k],1);//update(pos[k]-1,-1);
//     }
//     printf("\n");
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// const int maxn=300005;
// int n,minn[maxn<<2],pos[maxn],a[maxn],lazy[maxn<<2];
// void build(int rt,int l,int r)
// {
//     lazy[rt]=0,minn[rt]=0;
//     if(l==r) return;
//     int mid=(l+r)>>1;
//     build(rt<<1,l,mid),build(rt<<1,mid+1,r);
// }
// inline void push(int rt,int x) { minn[rt]+=x,lazy[rt]+=x; }
// inline void pushdown(int rt) { if(lazy[rt]) push(rt<<1,lazy[rt]),push((rt<<1)|1,lazy[rt]),lazy[rt]=0; }
// inline void pushup(int rt) { minn[rt]=min(minn[rt<<1],minn[(rt<<1)|1]); }
// void update(int rt,int l,int r,int x,int y,int z)
// {
//     if(x<=l && r<=y) { push(rt,z); return; }
//     int mid=(l+r)>>1;
//     pushdown(rt);
//     if(x<=mid) update(rt<<1,l,mid,x,y,z);
//     if(mid<y) update((rt<<1)|1,mid+1,r,x,y,z);
//     pushup(rt);
// }
// int query(int rt,int l,int r,int x,int y)
// {
//     if(x<y) return 0;
//     if(x<=l && r<=y) return minn[rt];
//     int mid=(l+r)>>1,res=0x7fffffff;
//     pushdown(rt);
//     if(x<=mid) res=min(res,query(rt<<1,l,mid,x,y));
//     if(mid<y) res=min(res,query((rt<<1)|1,mid+1,r,x,y));
//     return res;
// }
// priority_queue<int> que;
// int main()
// {
//     int i,k,x;
//     scanf("%d",&n);
//     build(1,1,n);
//     for(i=1;i<=n;i++) scanf("%d",&a[i]),pos[a[i]]=i;
//     while(!que.empty()) que.pop();
//     for(k=n,i=1;i<=n;i++)
//     {
//         printf("%d ",k);
//         if(i==n) break;
//         scanf("%d",&x);
//         update(1,1,n,x,n,-1);
//         // que.push(x);
//         for(;query(1,1,n,pos[k],n)</*query(1,1,n,pos[k]-1,pos[k]-1)*//*0*/query(1,1,n,pos[k],pos[k])-query1(1,1,n,pos[k]);k--)
//             update(1,1,n,pos[k],n,1);
//         // for(;;)
//         // {
//         //     while(!que.empty() && query(1,1,n,que.top(),que.top())+(que.top()>=pos[k])>0)
//         //         update(1,1,n,que.top(),n,-1),que.pop();
//         //     if(query(1,1,n,pos[k],n)<0)
//         //         update(1,1,n,pos[k],n,1),k--;
//         //     else break;
//         // }
//     }
//     printf("\n");
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
const int maxn=300005;
struct data
{
    int s,pmn,smx;
    data(int x=0,int y=0,int z=0):s(x),pmn(y),smx(z) { }
    inline data operator +(const data &p) const
    {
        return data(s+p.s,min(pmn,s+p.pmn),max(smx+p.s,p.smx));
    }
}tr[maxn<<2];
int n,a[maxn],pos[maxn];
inline void pushup(int rt) { tr[rt]=tr[rt<<1]+tr[(rt<<1)|1]; }
void build(int rt,int l,int r)
{
    tr[rt]=data();
    if(l==r) return;
    int mid=(l+r)>>1;
    build(rt<<1,l,mid),build((rt<<1)|1,mid+1,r);
}
data query(int rt,int l,int r,int x,int y)
{
    if(x>y) return data();
    if(x<=l && r<=y) return tr[rt];
    int mid=(l+r)>>1;
    data res=data();
    if(x<=mid) res=res+query(rt<<1,l,mid,x,y);
    if(mid<y) res=res+query((rt<<1)|1,mid+1,r,x,y);
    return res;
}
void update(int rt,int l,int r,int x,int z)
{
    if(l==r) { tr[rt].s+=z,tr[rt].pmn=min(0,tr[rt].s),tr[rt].smx=max(0,tr[rt].s); return; }
    int mid=(l+r)>>1;
    if(x<=mid) update(rt<<1,l,mid,x,z);
    else update((rt<<1)|1,mid+1,r,x,z);
    pushup(rt);
}
int main()
{
    int i,k,x;
    scanf("%d",&n);
    build(1,1,n);
    for(i=1;i<=n;i++) scanf("%d",&a[i]),pos[a[i]]=i;
    for(k=n,i=1;i<=n;i++)
    {
        printf("%d ",k);
        if(i==n) break;
        scanf("%d",&x);
        update(1,1,n,x,-1);
        // printf("%d\n",query(1,1,n,pos[k],n).pmn);
        for(;query(1,1,n,pos[k],n).pmn+query(1,1,n,1,pos[k]-1).smx<0;k--)
            update(1,1,n,pos[k],1);
    }
    printf("\n");
    return 0;
}