#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
#include<utility>
using namespace std;
typedef long long LL;
typedef pair<LL,int> PLI;
const int MAXN=1000010;
struct Node
{
    int id;
    LL l,r;
    Node(){}
    Node(LL _l,LL _r,int _id):l(_l),r(_r),id(_id){}
    friend bool operator<(const Node &p,const Node &q)
    {
        return p.l>q.l;
    }
}A[MAXN];
int n,m,ans[MAXN];
LL L[MAXN],R[MAXN],a[MAXN];
PLI P[MAXN];
multiset<PLI> S;
multiset<PLI>::iterator it;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%I64d%I64d",&L[i],&R[i]);
    for(int i=1;i<=m;i++) scanf("%I64d",&a[i]),P[i]=make_pair(a[i],i),S.insert(P[i]);
    for(int i=1;i<n;i++)
    {
        LL Min=L[i+1]-R[i];
        LL Max=R[i+1]-L[i];
        A[i]=Node(Min,Max,i);
    }
    sort(A+1,A+n);
    int sub=1;
    bool ok=true;
    for(int i=1;i<n;i++)
    {
        it=S.upper_bound(make_pair(A[i].r+1,0));
        if(it==S.begin()) {ok=false;break;}
        it--;
        if(it->first<A[i].l) {ok=false;break;}
        ans[A[i].id]=it->second;
        S.erase(it);
    }
    if(!ok) puts("No");
    else
    {
        puts("Yes");
        for(int i=1;i<n;i++)
            printf("%d ",ans[i]);
        puts("");
    }
    return 0;
}