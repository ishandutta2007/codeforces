#include<bits/stdc++.h>
#define maxn 10000
using namespace std;
struct flow_edge {
    int v,inv;
    long long cap;
};
vector<flow_edge> edges[maxn];
void add_edge(int u,int v,long long cap) {
    edges[u].push_back({v,edges[v].size(),cap});
    edges[v].push_back({u,edges[u].size()-1,0});
}
int lvl[maxn];
int iter[maxn];
vector<int> q;
int sink;
void bfs() {
    for(int i=1;i<=sink;i++) {
        lvl[i]=-1;
        iter[i]=0;
    }
    lvl[0]=iter[0]=0;
    int ind=0;
    q.push_back(0);
    while(ind<q.size()) {
        int u=q[ind];
        for(auto edge:edges[u]) {
            int v=edge.v;
            long long cap=edge.cap;
            if(cap>0 && lvl[v]==-1) {
                lvl[v]=lvl[u]+1;
                q.push_back(v);
            }
        }
        ind++;
    }
    q.clear();
}
long long augment_flow(int u,long long cur_flow) {
    if(u==sink) return cur_flow;
    for(;iter[u]<edges[u].size();iter[u]++) {
        flow_edge edge=edges[u][iter[u]];
        int v=edge.v;
        long long cap=edge.cap;
        int inverse_edge=edge.inv;
        if(cap>0 && lvl[v]==lvl[u]+1) {
            long long ret_flow = augment_flow(v,min(cur_flow,cap));
            if(ret_flow!=0) {
                edges[u][iter[u]].cap-=ret_flow;
                edges[v][inverse_edge].cap+=ret_flow;
                return ret_flow;
            }
        }
    }
    return 0;
}
long long flow() {
    bfs();
    long long total_flow=0;
    while(lvl[sink]!=-1) {
        long long cur_flow=augment_flow(0,1e18);
        while(cur_flow!=0) {
            total_flow+=cur_flow;
            cur_flow=augment_flow(0,1e18);
        }
        bfs();
    }
    return total_flow;
}
bool in_s[maxn];
void reconstruct_cut(int u) {
    in_s[u]=true;
    for(auto edge:edges[u]) {
        int v=edge.v;
        long long cap=edge.cap;
        if(cap>0) {
            reconstruct_cut(v);
        }
    }
}

int n,m;
int a[maxn];
vector<int> v;
vector<pair<int,int> > good_pairs;
int main() {
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<m;i++) {
        int u,v;
        scanf("%d %d",&u,&v);
        if(u%2==1) good_pairs.push_back({u,v});
        else good_pairs.push_back({v,u});
    }
    for(int i=1;i<=n;i++) {
        int tmp=a[i];
        for(int p=2;p*p<=tmp;p++) {
            if(tmp%p==0) {
                v.push_back(p);
                while(tmp%p==0) tmp/=p;
            }
        }
        if(tmp>1) v.push_back(tmp);
    }
    sort(v.begin(),v.end());
    int total=0;
    for(int j=0;j<v.size();j++) {
        if(j==0 || v[j]!=v[j-1]) {
            int p=v[j];
            sink=n+1;
            for(int i=1;i<=n;i++) {
                int cnt=0;
                int tmp=a[i];
                while(tmp%p==0) {
                    tmp/=p;
                    cnt++;
                }
                if(cnt>0) {
                    if(i%2==1) add_edge(0,i,cnt);
                    else add_edge(i,sink,cnt);
                }
            }
            for(int i=0;i<m;i++) {
                add_edge(good_pairs[i].first,good_pairs[i].second,100);
            }
            total+=flow();
            for(int i=0;i<=sink;i++) edges[i].clear();
        }
    }
    printf("%d",total);
}