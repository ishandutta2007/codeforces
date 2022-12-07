#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<utility>
#include<cstdlib>
using namespace std;
typedef long long LL;
const int MAXN=2000010;
struct Treap
{
    int ch[2],key,size,cnt;
    LL dat,sum;
}T[MAXN];
int root,tot;
inline int cmp(int x,int tar)
{
    if(T[x].dat==tar) return -1;
    return (tar>T[x].dat)?1:0;
}
inline void maintain(int x)
{
    T[x].size=T[T[x].ch[0]].size+T[T[x].ch[1]].size+T[x].cnt;
    T[x].sum=T[T[x].ch[0]].sum+T[T[x].ch[1]].sum+(LL)T[x].cnt*T[x].dat;
}
inline void rotate(int &x,int d)
{
    int p=T[x].ch[d^1];
    T[x].ch[d^1]=T[p].ch[d];
    T[p].ch[d]=x;
    maintain(x);
    maintain(p);
    x=p;
}
void Insert(int &x,LL tar)
{
    if(!x)
    {
        x=++tot;
        T[x].key=rand();
        T[x].size=T[x].cnt=1;
        T[x].dat=T[x].sum=tar;
        return;
    }
    int d=cmp(x,tar);
    if(d==-1)
    {
        T[x].cnt++;
        T[x].size++;
        T[x].sum+=tar;
        return;
    }
    Insert(T[x].ch[d],tar);
    if(T[T[x].ch[d]].key>T[x].key) rotate(x,d^1);
    maintain(x);
}
void Delete(int &x,int tar)
{
    int d=cmp(x,tar);
    if(d==-1)
    {
        if(T[x].cnt>1)
        {
            T[x].cnt--;
            T[x].size--;
            T[x].sum-=tar;
            return;
        }
        if(!T[x].ch[0]&&!T[x].ch[1]) x=0;
        else if(T[x].ch[0]&&!T[x].ch[1]) x=T[x].ch[0];
        else if(T[x].ch[1]&&!T[x].ch[0]) x=T[x].ch[1];
        else
        {
            int d2=(T[T[x].ch[0]].key>T[T[x].ch[1]].key)?0:1;
            rotate(x,d2^1);
            Delete(T[x].ch[d2^1],tar);
        }
    }
    else Delete(T[x].ch[d],tar);
    maintain(x);
}
LL Query(int x,int k)
{
    if(k==0) return 0;
    if(k<=T[T[x].ch[0]].size) return Query(T[x].ch[0],k);
    k-=T[T[x].ch[0]].size+T[x].cnt;
    if(k<=0) return T[T[x].ch[0]].sum+(LL)(k+T[x].cnt)*(LL)T[x].dat;
    else return T[T[x].ch[0]].sum+(LL)T[x].dat*T[x].cnt+Query(T[x].ch[1],k);
}
int n,m,sub,t[MAXN],top;
pair<pair<LL,LL>,int> a[MAXN];
pair<LL,int> b[MAXN];
LL ans=1000000000000000000LL,S[MAXN];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%I64d%I64d",&a[i].first.second,&a[i].first.first),a[i].second=i;
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) swap(a[i].first.first,a[i].first.second);
    if(m==1)
    {
        for(int i=1;i<=n;i++)
            if(ans>a[i].first.first) sub=a[i].second,ans=a[i].first.first;
        printf("%I64d\n",ans);
        for(int i=1;i<=n;i++)
            if(i==sub) putchar('1');
            else putchar('0');
        puts("");
        return 0;
    }
    for(int i=1;i<=n;i++) S[i]=S[i-1]+a[i].first.first;
    for(int i=1;i<=n;i++) Insert(root,a[i].first.first);
    for(int i=1;i<=n;i++)
    {
        if(i+1>m) {Delete(root,a[i].first.first);Insert(root,a[i].first.second-a[i].first.first);continue;}
        if(m-1-i>n-1) {Delete(root,a[i].first.first);Insert(root,a[i].first.second-a[i].first.first);continue;}
        LL con=a[i].first.second+S[i-1];
        Delete(root,a[i].first.first);
        con+=Query(root,m-1-i);
        if(con<ans) ans=con,sub=i;
        Insert(root,a[i].first.second-a[i].first.first);
    }
    if(m<n)
    {
        LL con=0;
        sort(a+1,a+n+1);
        for(int i=1;i<=m;i++) con+=(LL)a[i].first.first;
        if(ans>con)
        {
            ans=con;
            printf("%I64d\n",ans);
            for(int i=1;i<=m;i++) t[a[i].second]++;
            for(int i=1;i<=n;i++) printf("%d",t[i]);
            puts("");
            return 0;
        }
    }
    for(int i=1;i<=n;i++) swap(a[i].first.first,a[i].first.second);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) swap(a[i].first.first,a[i].first.second);
    t[a[sub].second]=2;
    for(int i=1;i<sub;i++) t[a[i].second]++;
    for(int i=1;i<sub;i++) b[++top]=make_pair(a[i].first.second-a[i].first.first,a[i].second);
    for(int i=sub+1;i<=n;i++) b[++top]=make_pair(a[i].first.first,a[i].second);
    sort(b+1,b+top+1);
    for(int i=1;i<=m-sub-1;i++) t[b[i].second]++;
    printf("%I64d\n",ans);
    for(int i=1;i<=n;i++) printf("%d",t[i]);
    puts("");
    return 0;
}