#include <iostream>
#include <vector>
#define F first
#define S second

using namespace std;

vector<pair<int,int> >g[100001];
int usede[100001];

struct va{
    int a,b,c;
};

vector<va> vas;

int dfs (int x,int eid){
    if (eid>=0) usede[eid]=1;
    vector<int> f;
    for (auto nx:g[x]){
        if (!usede[nx.S]){
            int asd=dfs (nx.F,nx.S);
            if (asd==0){
                f.push_back(nx.F);
            }
            else{
                va v1;
                v1.a=asd;
                v1.b=nx.F;
                v1.c=x;
                vas.push_back(v1);
            }
        }
    }
    for (int i=0;i<f.size()/2;i++){
        va v1;
        v1.a=f[i*2];
        v1.b=x;
        v1.c=f[i*2+1];
        vas.push_back(v1);
    }
    if (f.size()%2==1){
        return f[f.size()-1];
    }
    else{
        return 0;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    if (m%2==1){
        cout <<"No solution"<<endl;
        return 0;
    }
    for (int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(make_pair(b,i));
        g[b].push_back(make_pair(a,i));
    }
    dfs (1,-1);
    for (int i=0;i<vas.size();i++){
        cout <<vas[i].a<<" "<<vas[i].b<<" "<<vas[i].c<<'\n';
    }
}