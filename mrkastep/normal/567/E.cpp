#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <map>
#include <time.h>
#include <string>
#include <algorithm>
#include <queue>
#include <assert.h>

using namespace std;

#define For(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define ll long long int
#define all(v) (v).begin(),(v).end()

const int INF=1e9;
const int mod=1e9+7;
const ll LONGINF=4e18;
const double eps=1e-9;
const double PI=3.1415926535897932384626433832795;

typedef pair<double,double> point;


ll ds[200200],dt[200200];

int T;

vector<vector<pair<int,int>>> g;
vector<int> tme;
vector<bool> gd;
map<pair<int,int>,int> bridge;
vector<vector<int>> g1;
map<pair<int,int>,int> notbad;

int dfs(int v,int pr){
    gd[v]=false;
    int call=T;
    For(i,g1[v].size()){
        if(g1[v][i]==pr) continue;
        if(!gd[g1[v][i]]){
            call=min(call,tme[g1[v][i]]);
        }
        else{
            T++;
            tme[g1[v][i]]=T;
            int tm=dfs(g1[v][i],v);
            if(tm>tme[v]){
                if(notbad[mp(v,g1[v][i])]==0){
                    bridge[mp(v,g1[v][i])]=1;
                }
            }
            call=min(call,tm);
        }
    }
    return call;
}


void solve(int n){
    int m,s,t,a,b,c;
    scanf("%d%d%d",&m,&s,&t);
    map<ll,map<int,int>> tmp;
    map<pair<int,int>,int> mine;
    vector<pair<int,int>> e;
    vector<int> l;
    vector<vector<int>> rel;
    s--;
    t--;
    g.resize(n);
    rel.resize(n);
    For(i,m){
        scanf("%d%d%d",&a,&b,&c);
        a--;
        b--;
        if(mine[mp(a,b)]==0) mine[mp(a,b)]=c;
        else mine[mp(a,b)]=min(mine[mp(a,b)],c);
        e.pb(mp(a,b));
        l.pb(c);
        g[a].pb(mp(b,c));
        g[b].pb(mp(a,-c));
    }
    For(i,n){
        dt[i]=ds[i]=LONGINF;
    }
    ds[s]=0;
    tmp[0][s]=0;
    For(i,n){
        if(i!=s){
            tmp[LONGINF][i]=1;
        }
    }
    For(it,n){
        int v=tmp.begin()->y.begin()->x;
        For(i,g[v].size()){
            if(g[v][i].y<0) continue;
            int to=g[v][i].x;
            if(ds[to]>=ds[v]+g[v][i].y){
                rel[to].pb(v);
                if(ds[t]==ds[v]+g[v][i].y) continue;
                rel[to].clear();
                rel[to].pb(v);
                tmp[ds[to]].erase(to);
                if(tmp[ds[to]].size()==0) tmp.erase(ds[to]);
                ds[to]=ds[v]+g[v][i].y;
                tmp[ds[to]][to]=1;
            }
        }
        tmp.begin()->y.erase(v);
        if(tmp.begin()->y.size()==0) tmp.erase(tmp.begin());
    }
    tmp.clear();
    dt[t]=0;
    tmp[0][t]=0;
    For(i,n){
        if(i!=t){
            tmp[LONGINF][i]=1;
        }
    }
    For(it,n){
        int v=tmp.begin()->y.begin()->x;
        For(i,g[v].size()){
            if(g[v][i].y>0) continue;
            g[v][i].y*=-1;
            int to=g[v][i].x;
            if(dt[to]>dt[v]+g[v][i].y){
                tmp[dt[to]].erase(to);
                if(tmp[dt[to]].size()==0) tmp.erase(dt[to]);
                dt[to]=dt[v]+g[v][i].y;
                tmp[dt[to]][to]=1;
            }
            g[v][i].y*=-1;
        }
        tmp.begin()->y.erase(v);
        if(tmp.begin()->y.size()==0) tmp.erase(tmp.begin());
    }
    vector<pair<int,int>> goode;
    map<int,int> st;
    st[t]=1;
    vector<int> ready(n,true);
    ready[t]=false;
    For(i,m){
        pair<int,int> p=e[i];
        if(ds[p.x]+dt[p.y]+l[i]==ds[t]){
            goode.pb(p);
        }
    }
    g1.resize(n);
    map<pair<int,int>,bool> already;
    For(i,goode.size()){
        pair<int,int> p=goode[i];
        if(already[p]||already[mp(p.y,p.x)]){
            notbad[p]=1;
            notbad[mp(p.y,p.x)]=1;
            continue;
        }
        already[p]=1;
        already[mp(p.y,p.x)]=1;
        g1[p.x].pb(p.y);
        g1[p.y].pb(p.x);
    }
    tme.assign(n,INF);
    gd.assign(n,true);
    gd[s]=false;
    T=0;
    tme[s]=0;
    dfs(s,-1);
    For(i,m){
        a=e[i].x;
        b=e[i].y;
        c=l[i];
        if(bridge[mp(a,b)]==1&&c==mine[mp(a,b)]){
            printf("YES\n");
            continue;
        }
        if(ds[a]+dt[b]+1<ds[t]){
            printf("CAN %d\n",c-(ds[t]-1-(ds[a]+dt[b])));
            continue;
        }
        printf("NO\n");
    }
}

int main(){
#pragma comment(linker,"/STACK:268435456")
#ifdef _DEBUG
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#endif
    char c[5555];
    int n;
    while(scanf("%d",&n)==1) solve(n);
    /*printf("100000 99999 1 100000\n");
    For(i,99999){
        printf("%d %d %d\n",i+1,i+2,rand());
    }
*/


    return 0;
}