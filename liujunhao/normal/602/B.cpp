#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 100000
int n,a[MAXN+10],mi,mx,ans;
void Read(int &x){
    char c;
    while(c=getchar(),c!=EOF)
        if(c>='0'&&c<='9'){
            x=c-'0';
            while(c=getchar(),c>='0'&&c<='9')
                x=x*10+c-'0';
            ungetc(c,stdin);
            return;
        }
}
struct node{
    int mx,mi;
    node *ch[2];
}tree[MAXN*4+100],*tcnt=tree,*root;
inline void update(node *p){
    p->mx=max(p->ch[0]->mx,p->ch[1]->mx);
    p->mi=min(p->ch[0]->mi,p->ch[1]->mi);
}
inline void init(node *p){
    p->mx=0,p->mi=0x7fffffff;
}
void build(node *&p,int l,int r){
    p=++tcnt;
    init(p);
    if(l==r){
        p->mi=p->mx=a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(p->ch[0],l,mid);
    build(p->ch[1],mid+1,r);
    update(p);
}
void find(node *p,int l,int r,int ll,int rr){
    if(r<ll||l>rr)
        return;
    if(l>=ll&&r<=rr){
        mi=min(mi,p->mi);
        mx=max(mx,p->mx);
        return;
    }
    int mid=(l+r)>>1;
    find(p->ch[0],l,mid,ll,rr);
    find(p->ch[1],mid+1,r,ll,rr);
}
int main()
{
    int i,j;
    Read(n);
    for(i=1;i<=n;i++)
        Read(a[i]);
    i=j=1;
    build(root,1,n);
    while(j<=n){
        mx=0,mi=0x7fffffff;
        find(root,1,n,i,j);
        if(mx-mi<=1)
            ans=max(ans,++j-i);
        else
            i++;
    }
    printf("%d\n",ans);
}