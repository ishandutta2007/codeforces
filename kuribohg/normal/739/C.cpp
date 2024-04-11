#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const int MAXN=300010;
int n,m,a[MAXN];
struct Node
{
    int l,r;
    LL vl,vr;
    int ul,ur;
    int dl,dr;
    int ml,mr;
    int mn;
    LL lazy;
}T[MAXN<<2];
void update(int x)
{
    int lc=(x<<1),rc=(lc|1),ls=T[lc].r-T[lc].l+1,rs=T[rc].r-T[rc].l+1;
    T[x].vl=T[lc].vl,T[x].vr=T[rc].vr;
    T[x].ul=T[lc].ul+(T[lc].ul==ls&&T[lc].vr<T[rc].vl?T[rc].ul:0);
    T[x].ur=T[rc].ur+(T[rc].ur==rs&&T[rc].vl<T[lc].vr?T[lc].ur:0);
    T[x].dl=T[lc].dl+(T[lc].dl==ls&&T[lc].vr>T[rc].vl?T[rc].dl:0);
    T[x].dr=T[rc].dr+(T[rc].dr==rs&&T[rc].vl>T[lc].vr?T[lc].dr:0);
    T[x].ml=max(max(T[lc].ml,(T[lc].ul==ls&&T[lc].vr<T[rc].vl?ls+T[rc].ml:0)),(T[lc].ml==ls&&T[lc].vr>T[rc].vl?ls+T[rc].dl:0));
    T[x].mr=max(max(T[rc].mr,(T[rc].ur==rs&&T[rc].vl<T[lc].vr?rs+T[lc].mr:0)),(T[rc].mr==rs&&T[rc].vl>T[lc].vr?rs+T[lc].dr:0));
    T[x].mn=max(T[lc].mn,T[rc].mn);
    T[x].mn=max(T[x].mn,max((T[lc].vr>T[rc].vl?T[lc].mr+T[rc].dl:0),(T[lc].vr<T[rc].vl?T[rc].ml+T[lc].dr:0)));
}
void pushdown(int x)
{
    int lc=(x<<1),rc=(lc|1);
    T[lc].vl+=T[x].lazy,T[lc].vr+=T[x].lazy;
    T[lc].lazy+=T[x].lazy;
    T[rc].vl+=T[x].lazy,T[rc].vr+=T[x].lazy;
    T[rc].lazy+=T[x].lazy;
    T[x].lazy=0;
}
void MakeTree(int x,int l,int r)
{
    T[x].l=l,T[x].r=r;
    if(l==r)
    {
        T[x].vl=T[x].vr=a[l];
        T[x].ul=T[x].ur=T[x].dl=T[x].dr=T[x].ml=T[x].mr=T[x].mn=1;
        return;
    }
    int mid=(l+r)>>1;
    MakeTree(x<<1,l,mid);
    MakeTree(x<<1|1,mid+1,r);
    update(x);
}
void Change(int x,int l,int r,int tar)
{
    if(T[x].l==l&&T[x].r==r)
    {
        T[x].vl+=(LL)tar,T[x].vr+=(LL)tar;
        T[x].lazy+=(LL)tar;
        return;
    }
    pushdown(x);
    int mid=(T[x].l+T[x].r)>>1;
    if(r<=mid) Change(x<<1,l,r,tar);
    else if(l>mid) Change(x<<1|1,l,r,tar);
    else {Change(x<<1,l,mid,tar);Change(x<<1|1,mid+1,r,tar);}
    update(x);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    MakeTree(1,1,n);
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        int l,r,w;
        scanf("%d%d%d",&l,&r,&w);
        Change(1,l,r,w);
        printf("%d\n",T[1].mn);
    }
    return 0;
}