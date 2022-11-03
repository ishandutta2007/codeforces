#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
inline int read(){
    register int x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
struct node{
    mutable int l,r,v;
    node(int L,int R,int V):l(L),r(R),v(V){}
    bool operator < (const node & a)const{
        return l<a.l;
    }
};
set<node> s;
#define IT set<node>::iterator
inline IT split(int x){
    IT it=s.lower_bound(node(x,-1,0));
    if(it!=s.end()&&it->l==x) return it;
    --it;
    int l=it->l,r=it->r,v=it->v;
    s.erase(it);s.insert(node(l,x-1,v));
    return s.insert(node(x,r,v)).first;
}
int sum=0;
inline void assign(int l,int r,int v){
    if(l>r) return;
    IT itr=split(r+1),itl=split(l),it=itl;
    for(; it!=itr; ++it) sum-=it->v*(it->r-it->l+1);
    s.erase(itl,itr);s.insert(node(l,r,v));
    sum+=v*(r-l+1);
}
int main(){
    int n,q;
    n=read(),q=read();sum=n;
    s.insert(node(1,n,1));s.insert(node(n+1,n+1,0));
    int l,r,k;
    while(q--){
        l=read(),r=read(),k=read();
        assign(l,r,k-1);
        printf("%d\n",sum);
    }
    return 0;
}