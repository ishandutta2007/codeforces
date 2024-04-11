#include <cstdio>
#include <cstring>
#include <iostream>
#include <set>
#include <vector>

#define INF (1LL<<62)
#define mp make_pair
#define fst first
#define snd second
#define pb push_back
using namespace std;

set<pair<long long,int> > pq;
bool v[1024];

int tt[1024];
int ct[1024];

long long dist[1024][1024];

vector<pair<int,int> > graph1[1024];
vector<pair<int,int> > graph2[1024];

void dijkstra(vector<pair<int,int> > graph[], int n, int s, long long *d){
    pq.clear();
    int i,j;
    d[s]=0;
    for(i=0;i<n;++i){
        if(i!=s){
            d[i]=INF;
        }
        pq.insert(mp(d[i],i));
    }

    memset(v,false,sizeof(v));
    for(i=0;i<n;++i){
        int x=pq.begin()->snd;
        v[x]=true;
        pq.erase(pq.begin());
        for(j=0;j<graph[x].size();++j){
            int y=graph[x][j].fst, c=graph[x][j].snd;if(v[y])continue;
            if(d[x]+c<d[y]){
                pq.erase(mp(d[y],y));
                d[y]=d[x]+c;
                pq.insert(mp(d[y],y));
            }
        }
    }
}

int main(){
    int n,m,i,j,s,t;
    scanf("%d %d",&n,&m);
    scanf("%d %d",&s,&t);s--;t--;
    for(i=0;i<m;++i){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);a--;b--;
        graph1[a].pb(mp(b,c));
        graph1[b].pb(mp(a,c));
    }
    for(i=0;i<n;++i){
        scanf("%d %d",tt+i,ct+i);
    }
    for(i=0;i<n;++i){
        dijkstra(graph1,n,i,dist[i]);
    }
    for(i=0;i<n;++i){
        for(j=0;j<n;++j){
            if(i==j)continue;
            if(dist[i][j]<=tt[i]){
                graph2[i].pb(mp(j,ct[i]));
            }
        }
    }
    dijkstra(graph2,n,s,dist[0]);
    if(dist[0][t]>=INF)puts("-1");
    else cout<<dist[0][t]<<endl;
    return 0;
}