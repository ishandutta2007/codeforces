#include <bits/stdc++.h>
using namespace std;
const int maxlog=19;
const int maxnode=(1<<21)+((maxlog+5)<<1);
int rt,tag[maxnode][2],frk[maxnode],ch[maxnode][2],sz[maxnode],sta[maxnode],top,tot; // 0000->tag[0] 1111->tag[1] frk:can merge
// time complexity: potetion:#nodes, ~delta*log
inline int newnode() { return ((top>=0)?assert(sta[top]),sta[top--]:++tot); }
// { return ++tot; }
inline void pushup(int rt,int l)
{
    if(!rt) return;
    assert(l>=0);
    sz[rt]=sz[ch[rt][0]]+sz[ch[rt][1]];
    frk[rt]=frk[ch[rt][0]]|frk[ch[rt][1]]|((ch[rt][0] && ch[rt][1])<<l);
}
void push(int rt,int l,int c0,int c1)
{
    if(!rt) return;
    // if(((c0>>l)&1) || !((c1>>l)&1)) swap(ch[rt][0],ch[rt][1]);
    if(!(((c0^c1)>>l)&1))
    {
        assert(!ch[rt][0] || !ch[rt][1]);
        ch[rt][(c0>>l)&1]|=ch[rt][!((c0>>l)&1)];
        ch[rt][!((c0>>l)&1)]=0;
    }
    else if((c0>>l)&1) swap(ch[rt][0],ch[rt][1]);
    int _=((~tag[rt][0])&c0)|(tag[rt][0]&c1);
    tag[rt][1]=((~tag[rt][1])&c0)|(tag[rt][1]&c1);
    tag[rt][0]=_;
}
inline void pushdown(int rt,int l)
{
    if(!rt || !l) return;
    if(tag[rt][0]==0 && tag[rt][1]==-1) return;
    push(ch[rt][0],l-1,tag[rt][0],tag[rt][1]),push(ch[rt][1],l-1,tag[rt][0],tag[rt][1]);
    tag[rt][0]=0,tag[rt][1]=-1;
}
void insert(int &rt,int l,int x)
{
    if(!rt) rt=++tot,ch[rt][0]=ch[rt][1]=0,frk[rt]=0,tag[rt][0]=0,tag[rt][1]=-1;
    if(l<0) { sz[rt]=1; return; }
    insert(ch[rt][(x>>l)&1],l-1,x),pushup(rt,l);
}
void split(int &rt1,int &rt2,int L,int l,int r,int x,int y)
{
    if(x<=l && r<=y) { rt2=rt1,rt1=0; return; }
    if(!rt1) { rt2=0; return; }
    int mid=(l+r)>>1; pushdown(rt1,L);
    rt2=newnode(),ch[rt2][0]=ch[rt2][1]=0,frk[rt2]=0,tag[rt2][0]=0,tag[rt2][1]=-1;
    assert(rt2);
    if(x<=mid) split(ch[rt1][0],ch[rt2][0],L-1,l,mid,x,y);
    if(mid<y) split(ch[rt1][1],ch[rt2][1],L-1,mid+1,r,x,y);
    pushup(rt1,L),pushup(rt2,L);
    if(!sz[rt1]) assert(rt1),sta[++top]=rt1,rt1=0; // dprintf("- %d\n",sta[top]);
    if(!sz[rt2]) assert(rt2),sta[++top]=rt2,rt2=0; // dprintf("- %d\n",sta[top]);
}
void merge(int &rt1,int rt2,int l)
{
    if(!rt1 || !rt2) { rt1|=rt2; return; }
    if(l<0) { sta[++top]=rt2/*,dprintf("- %d\n",sta[top])*/; return; }
    pushdown(rt1,l),pushdown(rt2,l);
    merge(ch[rt1][0],ch[rt2][0],l-1),merge(ch[rt1][1],ch[rt2][1],l-1);
    pushup(rt1,l),sta[++top]=rt2/*,dprintf("- %d\n",sta[top])*/;
    // printf(".!. %d\n",sz[rt1]);
}
void merge(int rt,int l,int x,int y)
{
    if(!rt) return;
    if(!((frk[rt]>>x)&1)) { push(rt,l,y<<x,~((y^1)<<x)); /*printf("... %d %d %d %d\n",l,x,y,frk[rt]);*/ return; }
    pushdown(rt,l);
    if(l==x)
    {
        assert(ch[rt][0] && ch[rt][1]);
        merge(ch[rt][y],ch[rt][y^1],l-1);
        /*sta[++top]=ch[rt][y^1],*/ch[rt][y^1]=0;//printf("- %d\n",sta[top]);
    }
    else merge(ch[rt][0],l-1,x,y),merge(ch[rt][1],l-1,x,y);
    pushup(rt,l);
}
int query(int rt,int L,int l,int r,int x,int y)
{
    if(!rt) return 0;
    if(x<=l && r<=y) return sz[rt];
    int mid=(l+r)>>1,res=0; pushdown(rt,L);
    if(x<=mid) res+=query(ch[rt][0],L-1,l,mid,x,y);
    if(mid<y) res+=query(ch[rt][1],L-1,mid+1,r,x,y);
    return res;
}
void print(int rt,int L,int l,int r)
{
    if(!rt) return;
    if(l==r) { assert(sz[rt]==1); printf("%d ",l); return; }
    int mid=(l+r)>>1; pushdown(rt,L);
    // printf("%d %d\n%d %d\n",rt,ch[rt][0],rt,ch[rt][1]);
    print(ch[rt][0],L-1,l,mid),print(ch[rt][1],L-1,mid+1,r);
}
int main()
{
    int n,q,l,r,x,t;
    scanf("%d%d",&n,&q);
    rt=0,ch[0][0]=ch[0][1]=0,sz[0]=0,frk[rt]=0,tot=0,top=-1;
    while(n--) scanf("%d",&x),insert(rt,maxlog,x);
    while(q--)
    {
        scanf("%d%d%d",&t,&l,&r);
        if(t!=4)
        {
            scanf("%d",&x);
            split(rt,n,maxlog,0,(2<<maxlog)-1,l,r);
            // printf("??? %d: ",sz[n]); print(n,maxlog,0,(2<<maxlog)-1); printf("\n");
            if(t==1)
            {
                for(l=0;l<=maxlog;l++)
                    if(!((x>>l)&1))
                        merge(n,maxlog,l,0);//printf("%d: ",l),print(n,maxlog,0,(2<<maxlog)-1),printf("\n");
            }
            else if(t==2)
            {
                for(l=0;l<=maxlog;l++)
                    if((x>>l)&1)
                        merge(n,maxlog,l,1);
            }
            else push(n,maxlog,x,~x);
            // printf("??? %d: ",sz[rt]); print(rt,maxlog,0,(2<<maxlog)-1); printf("\n");
            // printf("??? %d: ",sz[n]); print(n,maxlog,0,(2<<maxlog)-1); printf("\n");
            merge(rt,n,maxlog);
            // printf("!!! %d: ",sz[rt]); print(rt,maxlog,0,(2<<maxlog)-1); printf("\n");
        }
        else printf("%d\n",query(rt,maxlog,0,(2<<maxlog)-1,l,r));
    }
    return 0;
}