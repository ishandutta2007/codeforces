#include <iostream>
#include <vector>
#include <queue>
#define F first
#define S second

using namespace std;

typedef long long ll;

struct dij{
    ll x,l,t;
};

struct comp{
    bool operator () (dij d1, dij d2){
        if (d1.l!=d2.l){
            return d1.l>d2.l;
        }
        return d1.t>d2.t;
    }
};

vector<pair<ll,ll> > gt[100001];

priority_queue<dij,vector<dij>, comp> bfs;

int used[100001];

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    int v=k;
    for (int i=0;i<m;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        gt[a].push_back(make_pair(b,c));
        gt[b].push_back(make_pair(a,c));
    }
    for (int i=0;i<k;i++){
        ll a,b;
        cin>>a>>b;
        dij d;
        d.x=a;
        d.l=b;
        d.t=1;
        bfs.push(d);
    }
    used[1]=1;
    for (auto nx:gt[1]){
        dij d;
        d.x=nx.F;
        d.l=nx.S;
        d.t=0;
        bfs.push(d);
    }
    while (!bfs.empty()){
        dij dd=bfs.top();
        bfs.pop();
        if (!used[dd.x]){
            //cout<<dd.x<<" "<<dd.t<<" "<<dd.l<<endl;
            used[dd.x]=1;
            if (dd.t) v--;
            for (auto nx:gt[dd.x]){
                dij d;
                d.x=nx.F;
                d.l=nx.S+dd.l;
                d.t=0;
                bfs.push(d);
            }
        }
    }
    cout<<v<<endl;
}