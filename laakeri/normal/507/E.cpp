#include <iostream>
#include <vector>
#include <queue>
#include <map>
#define F first
#define S second

using namespace std;

vector<pair<pair<int, int>, int> > rs;

vector<pair<int, int> > g[100001];
map<pair<int, int>, int> f;
int fr[100001];

struct nn{
    int d;
    int r;
    int x;
    int f;
    bool operator<(const nn&nn2)const{
        if (d!=nn2.d) return d>nn2.d;
        else return r>nn2.r;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=0;i<m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        rs.push_back({{min(x, y), max(x, y)}, z});
        g[x].push_back({y, z});
        g[y].push_back({x, z});
    }
    priority_queue<nn> dij;
    dij.push({0, 0, 1, -1});
    while (1){
        auto asd=dij.top();
        dij.pop();
        if (fr[asd.x]) continue;
        fr[asd.x]=asd.f;
        if (asd.x==n){
            break;
        }
        for (auto nx:g[asd.x]){
            if (nx.S==1){
                dij.push({asd.d+1, asd.r, nx.F, asd.x});
            }
            else{
                dij.push({asd.d+1, asd.r+1, nx.F, asd.x});
            }
        }
    }
    int x=n;
    while (x>-1){
        f[{min(x, fr[x]), max(x, fr[x])}]=1;
        x=fr[x];
    }
    vector<pair<pair<int, int>, int> > v;
    for (auto asd:rs){
        if (f[asd.F]&&asd.S==0){
            v.push_back({asd.F, 1});
        }
        if ((!f[asd.F])&&asd.S==1){
            v.push_back({asd.F, 0});
        }
    }
    cout<<v.size()<<endl;
    for (auto asd:v){
        cout<<asd.F.F<<" "<<asd.F.S<<" "<<asd.S<<'\n';
    }
}