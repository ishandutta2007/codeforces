#include<bits/stdc++.h>
using namespace std;
struct rectangle {
    pair<int,int> ul;
    pair<int,int> br;
};
struct flow {
    int v;
    int cap;
    int inv;
};
bool inside_one(pair<int,int> t,rectangle r) {
    if(t.first<r.ul.first || t.first>r.br.first) return false;
    if(t.second<r.ul.second || t.second>r.br.second) return false;
    return true;
}
rectangle r[100];
int n,m;
bool inside_any(pair<int,int> t) {
    for(int i=1;i<=m;i++) {
        if(inside_one(t,r[i])) return true;
    }
    return false;
}
vector<int> x;
vector<int> y;
int s=0;
int t=10000;
int inf=1e9;
vector<flow> graph[10001];
int lvl[10001];
int augment(int u,int gf) {
    if(u==t) return gf;
    int rt=0;
    for(int i=0;i<graph[u].size();i++) {
        int v=graph[u][i].v;
        int c=graph[u][i].cap;
        int inv=graph[u][i].inv;
        if(c!=0 && lvl[v]==lvl[u]+1) {
            int pf=min(gf,c);
            int rf=augment(v,pf);
            gf-=rf;
            rt+=rf;
            graph[u][i].cap-=rf;
            graph[v][inv].cap+=rf;
        }
    }
    return rt;
}
void bfs() {
    for(int i=0;i<=t;i++) lvl[i]=-1;
    lvl[0]=0;
    vector<int> q;
    q.push_back(0);
    int ind=0;
    while(ind<q.size()) {
        int u=q[ind];
        for(int i=0;i<graph[u].size();i++) {
            int v=graph[u][i].v;
            int c=graph[u][i].cap;
            if(c>0 && lvl[v]==-1) {
                lvl[v]=lvl[u]+1;
                q.push_back(v);
            }
        }
        ind++;
    }
}
int max_flow() {
    int rt=0;
    bfs();
    while(lvl[t]!=-1) {
        int t=augment(s,inf);
        while(t!=0) {
            rt+=t;
            t=augment(s,inf);
        }
        bfs();
    }
    return rt;
}
int main() {
    scanf("%d %d",&n,&m);
    int a,b,c,d;
    for(int i=1;i<=m;i++) {
        scanf("%d %d %d %d",&a,&b,&c,&d);
        r[i].ul={a,b};
        r[i].br={c,d};
        x.push_back(a);
        x.push_back(c+1);
        y.push_back(b);
        y.push_back(d+1);
    }
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    int k=x.size();
    int l=y.size();
    for(int i=0;i+1<k;i++) {
        graph[s].push_back({i+1,x[i+1]-x[i],0});
        graph[i+1].push_back({s,0,graph[s].size()-1});
    }
    for(int j=0;j+1<l;j++) {
        graph[j+k].push_back({t,y[j+1]-y[j],graph[t].size()});
        graph[t].push_back({j+k,0,0});
    }
    for(int i=0;i+1<k;i++) {
        for(int j=0;j+1<l;j++) {
            if(x[i]!=x[i+1] && y[j]!=y[j+1]) {
                if(inside_any({x[i],y[j]})) {
                    graph[i+1].push_back({j+k,inf,graph[j+k].size()});
                    graph[j+k].push_back({i+1,0,graph[i+1].size()-1});
                }
            }
        }
    }
    printf("%d",max_flow());
    return 0;
}