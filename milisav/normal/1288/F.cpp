#include<bits/stdc++.h>
#define maxn 100000
using namespace std;
struct flow {
    int v;
    int ca;
    int co;
    int inv;
    int oid;
};
int n1,n2,m,r,b;
char s[maxn];
char t[maxn];
int gu[maxn];
int gv[maxn];
vector<flow> a[maxn];
int p,q,x,y;
int inf=1e5;
int dist[maxn];
pair<int,int> par[maxn];
void belfo() {
    for(int i=0;i<=y;i++) {
        dist[i]=inf;
        par[i]={-1,-1};
    }
    dist[x]=0;
    par[x]={x,0};
    bool ch=true;
    for(int iter=0;iter<=y && ch;iter++) {
        ch=false;
        for(int u=0;u<=y;u++) {
            for(int i=0;i<a[u].size();i++) {
                flow t = a[u][i];
                int v=a[u][i].v;
                if(t.ca>0) {
                    if(dist[v]>dist[u]+t.co) {
                        dist[v]=dist[u]+t.co;
                        par[v]={u,i};
                        ch=true;
                    }
                }
            }
        }
    }
}
char h[maxn];
void set_original() {
    for(int i=0;i<=y;i++) a[i].clear();
    int u,v;
    for(int i=0;i<m;i++) {
        u=gu[i];
        v=gv[i];
        a[u].push_back({v,1,r,a[v].size(),i});
        a[v].push_back({u,0,-r,a[u].size()-1,-1});
        a[v].push_back({u,1,b,a[u].size(),i});
        a[u].push_back({v,0,-b,a[v].size()-1,-1});
    }
    int bl=0;
    for(int i=0;i<n1;i++) {
        if(s[i]=='R') {
            a[p].push_back({i,inf,0,a[i].size(),-1});
            a[i].push_back({p,0,0,a[p].size()-1,-1});
            a[x].push_back({i,1,0,a[i].size(),-1});
            a[i].push_back({x,0,0,a[x].size()-1,-1});
            bl++;
        }
        else {
            if(s[i]=='B') {
                a[p].push_back({i,0,0,a[i].size(),-1});
                a[i].push_back({p,inf,0,a[p].size()-1,-1});
                a[y].push_back({i,0,0,a[i].size(),-1});
                a[i].push_back({y,1,0,a[y].size()-1,-1});
                bl--;
            }
            else {
                a[p].push_back({i,inf,0,a[i].size(),-1});
                a[i].push_back({p,inf,0,a[p].size()-1,-1});
            }
        }
    }
    if(bl>0) {
        a[p].push_back({y,bl,0,a[y].size(),-1});
        a[y].push_back({p,0,0,a[p].size()-1,-1});
    }
    if(bl<0) {
        a[x].push_back({p,-bl,0,a[p].size(),-1});
        a[p].push_back({x,0,0,a[x].size()-1,-1});
    }
    bl=0;
    for(int i=n1;i<n1+n2;i++) {
        if(t[i-n1]=='B') {
            a[q].push_back({i,inf,0,a[i].size(),-1});
            a[i].push_back({q,0,0,a[q].size()-1,-1});
            a[x].push_back({i,1,0,a[i].size(),-1});
            a[i].push_back({x,0,0,a[x].size()-1,-1});
            bl++;
        }
        else {
            if(t[i-n1]=='R') {
                a[q].push_back({i,0,0,a[i].size(),-1});
                a[i].push_back({q,inf,0,a[q].size()-1,-1});
                a[y].push_back({i,0,0,a[i].size(),-1});
                a[i].push_back({y,1,0,a[y].size()-1,-1});
                bl--;
            }
            else {
                a[q].push_back({i,inf,0,a[i].size(),-1});
                a[i].push_back({q,inf,0,a[q].size()-1,-1});
            }
        }
    }
    if(bl>0) {
        a[q].push_back({y,bl,0,a[y].size(),-1});
        a[y].push_back({q,0,0,a[q].size()-1,-1});
    }
    if(bl<0) {
        a[x].push_back({q,-bl,0,a[q].size(),-1});
        a[q].push_back({x,0,0,a[x].size()-1,-1});
    }
}

void test_flow() {
    set_original();
    int mf=0;
    for(auto t:a[x]) {
        mf+=t.ca;
    }
    a[p].push_back({q,m,0,a[q].size(),-1});
    a[q].push_back({p,m,0,a[p].size()-1,-1});
    belfo();
    int tc=0;
    int cf=0;
    while(dist[y]!=inf) {
        tc+=dist[y];
        int v=y;
        while(v!=x) {
            int u=par[v].first;
            int id=par[v].second;
            a[u][id].ca-=1;
            int inv=a[u][id].inv;
            a[v][inv].ca+=1;
            v=u;
        }
        cf++;
        belfo();
    }
    if(mf!=cf) {
        printf("-1");
        return;
    }
    printf("%d\n",tc);
    for(int j=0;j<m;j++) h[j]='U';
    for(int u=0;u<=y;u++) {
        for(auto t:a[u]) {
            if(t.oid!=-1 && t.ca==0) {
                if(u<n1) h[t.oid]='R';
                else h[t.oid]='B';
            }
        }
    }
    printf("%s",h);
}
int main() {
    scanf("%d %d %d %d %d",&n1,&n2,&m,&r,&b);
    scanf("%s",s);
    scanf("%s",t);
    int u,v;
    p=n1+n2;
    q=p+1;
    x=q+1;
    y=x+1;
    for(int i=0;i<m;i++) {
        scanf("%d %d",&u,&v);
        u--;
        v--;
        v+=n1;
        gu[i]=u;
        gv[i]=v;
    }
    test_flow();
    return 0;
}