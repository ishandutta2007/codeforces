#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<ctype.h>
using namespace std;

#define X first
#define Y second
typedef long long ll;
typedef pair<int,int> Pi;

int S[100010], D[100010], now;
const int SZ = 310;
struct Qua{
    Qua(){}
    Qua(int l,int r,int v,int c):l(l),r(r),v(v),c(c){}
    int l,r,v,c;
    bool operator<(const Qua &L)const{
        if(l/SZ != L.l/SZ)return l<L.l;
        return r<L.r;
    }
}qua[100010];
int color[100010], ans[100010];
int n, m;
int st[100010], en[200020], next[200020];
int inc[100010];
int cnt[100010], ccnt[100010];

void addedge(int s,int e,int c){next[c]=st[s],st[s]=c,en[c]=e;}

void dfs(int x,int f)
{
    S[x] = now+1;
    for(int i=st[x];i;i=next[i])if(f!=en[i])dfs(en[i],x);
    inc[D[x] = ++now] = color[x];
}

int main()
{
    scanf("%d%d",&n,&m);
    int i;
    for(i=1;i<=n;i++)scanf("%d",color+i);
    for(i=1;i<n;i++){
        int x, y;
        scanf("%d%d",&x,&y);
        addedge(x, y, i<<1);
        addedge(y, x, i<<1|1);
    }
    dfs(1,-1);
    for(i=1;i<=m;i++){
        int x, y;
        scanf("%d%d",&x,&y);
        qua[i] = Qua(S[x],D[x],y,i);
    }
    sort(qua+1,qua+1+m);
    int L=1,R=0;
    for(i=1;i<=m;i++){
        while(R<qua[i].r)++cnt[++ccnt[inc[++R]]];
        while(L<qua[i].l)--cnt[ccnt[inc[L++]]--];
        while(R>qua[i].r)--cnt[ccnt[inc[R--]]--];
        while(L>qua[i].l)++cnt[++ccnt[inc[--L]]];
        ans[qua[i].c] = cnt[qua[i].v];
    }
    for(i=1;i<=m;i++)printf("%d\n",ans[i]);
    return 0;
}