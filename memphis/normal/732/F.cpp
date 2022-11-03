#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int inf=0x3f3f3f3f;
const int N=400005;

int n,m,sn[N],nx[N<<1],ed[N<<1];
int dfn[N],low[N],st[N],post[N],ans,ind;
pii sideop[N];
int linep[N];
bool inloop[N];

inline int getM(int x){
    return x>m?x-m:x;
}

void tarjan(int x,int fa) {
    dfn[x]=low[x]=++ind;
    st[++*st]=x;
    post[x]=*st;
    //printf("input x=%d\n",x);
    for(int j=sn[x];j;j=nx[j]){
        if(ed[j]==fa) continue;
        if(dfn[ed[j]])
            low[x]=min(low[x],low[ed[j]]);
        else{
            tarjan(ed[j],x);
            low[x]=min(low[x],low[ed[j]]);
            if(low[ed[j]]>dfn[x]){
                bool flag=0;
                if(*st-post[ed[j]]+1>ans){
                    ans=*st-post[ed[j]]+1;
                    flag=1;
                }
                int len=0;
                while(st[*st]!=ed[j]){
                    if(flag) linep[++len]=st[*st];
                    --*st;
                }
                if(flag) linep[++len]=st[*st];
                --*st;
            }
        }
    }
}

bool vis[N];
void dfs_ori(int x){
    //printf("cur = %d\n",x);
    vis[x]=1;
    for(int j=sn[x];j;j=nx[j]){
        if(x==linep[ans] && ed[j]==linep[1]) continue;
        if(vis[ed[j]]){
            if(sideop[getM(j)]==pii(0,0))
                sideop[getM(j)]=pii(x,ed[j]);
            continue;
        }
        if(inloop[ed[j]]){
            sideop[getM(j)]=pii(x,ed[j]);
            if(inloop[x])
                dfs_ori(ed[j]);
            continue;
        }
        sideop[getM(j)]=pii(ed[j],x);
        dfs_ori(ed[j]);
    }
}

void solve(){
    scanf("%d%d",&n,&m);
    rep(i,1,m){
        int x,y;
        scanf("%d%d",&x,&y);
        nx[i]=sn[x],sn[x]=i,ed[i]=y;
        nx[i+m]=sn[y],sn[y]=i+m,ed[i+m]=x;
    }
    tarjan(1,0);
    if(*st>ans){
        ans=*st;
        rep(i,1,*st) linep[ans-i+1]=st[i];
    }
    rep(i,1,ans) inloop[linep[i]]=1;
    //rep(i,1,ans) printf("%d ",linep[i]);
    //puts("");
    //exit(0);

    dfs_ori(linep[ans]);
    printf("%d\n",ans);
    rep(i,1,m) printf("%d %d\n",sideop[i].first,sideop[i].second);
}

int main(){

	int ca=1;
	while(ca--){
		solve();
	}
}