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
const int N_ = 300030;

struct UNF{
    int p[N_], w[N_];
    void init(){for(int i=0;i<N_;i++)p[i] = i, w[i] = 1;}
    int Find(int x){
        if(p[x] == x)return x;
        return p[x] = Find(p[x]);
    }
    bool Union(int x,int y){
        x = Find(x), y = Find(y);
        if(x == y)return false;
        if(w[x] < w[y])p[x] = y, w[y] += w[x];
        else p[y] = x, w[x] += w[y];
        return true;
    }
}unf, unf2;

Pi para[N_];
int st[N_], en[N_<<1], nxt[N_<<1];
inline void addE(int s,int e,int c){nxt[c]=st[s],st[s]=c,en[c]=e;}
int qua[N_][3];
int dep[N_], up[N_][20];

int Q[N_];
int vis[N_];
int dis[N_];

int get_longest(int x,int mode){
    int *fr = Q, *re = Q;
    vis[x] = 1;
    dis[x] = 0;
    *fr++ = x;
    while(fr != re){
        int t = *re++;
        for(int i=st[t];i;i=nxt[i]){
            if(vis[en[i]])continue;
            *fr++ = en[i];
            dis[en[i]] = dis[t] + 1;
            vis[en[i]] = 1;
        }
    }
    if(mode){
        for(int *i = Q;i!=fr;i++)vis[*i] = 0, dis[*i] = 0;
    }
    return *(--fr);
}
int ans[N_];

int main()
{
    unf.init();unf2.init();
    int n, m, q;
    scanf("%d%d%d",&n,&m,&q);
    int i;
    for(i=1;i<=m;i++){
        int x, y;
        scanf("%d%d",&x,&y);
        addE(x, y, i<<1);
        addE(y, x, i<<1|1);
        unf.Union(x, y);
        unf2.Union(x, y);
    }
    for(i=1;i<=n;i++){
        if(!vis[i]){
            int a = get_longest(i, 1);
            int b = dis[get_longest(a, 0)];
            ans[unf.Find(i)] = b;
        }
    }
    int now_e = m;
    for(i=1;i<=q;i++){
        scanf("%d",qua[i]);
        if(qua[i][0] == 1){
            scanf("%d",qua[i]+1);
            printf("%d\n",ans[unf.Find(qua[i][1])]);
        }
        else{
            scanf("%d%d",qua[i]+1,qua[i]+2);
            int a = ans[unf.Find(qua[i][1])];
            int b = ans[unf.Find(qua[i][2])];
            if(unf.Union(qua[i][1], qua[i][2])){
                ans[unf.Find(qua[i][1])] = max(max(a, b), (a+1)/2+(b+1)/2+1);
            }
        }
    }
    return 0;
}