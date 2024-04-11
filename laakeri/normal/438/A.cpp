#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define F first
#define S second

using namespace std;

typedef long long ll;

int isremoved[1002];
ll p[1002];
vector<int> g[1002];
vector<pair<int,int> > asd;

ll cost(int x){
    ll ret=0;
    for (int nx:g[x]){
        if (!isremoved[nx]){
            ret+=p[nx];
        }
    }
    return ret;
}

ll dcost (int x){
    ll ret=0;
    for (int nx:g[x]){
        if (!isremoved[nx]){
            ret++;
        }
    }
    return ret*p[x];
}

int main(){
    int n,m;
    cin>>n>>m;
    for (int i=0;i<n;i++){
        cin>>p[i+1];
        asd.push_back(make_pair(p[i+1],i+1));
    }
    for (int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    ll v=0;
    sort(asd.rbegin(),asd.rend());
    for (auto a:asd){
        v+=cost(a.S);
        isremoved[a.S]=1;
    }
    cout <<v<<endl;
}