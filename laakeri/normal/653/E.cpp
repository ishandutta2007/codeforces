#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

set<int> fe[303030];

int co[303030];

set<int> need;

void dfs(int x, int c){
    co[x]=c;
    vector<int> go;
    for (int nx:need){
        if (fe[x].count(nx)==0){
            go.push_back(nx);
        }
    }
    for (int nx:go){
        need.erase(nx);
    }
    for (int nx:go){
        dfs(nx, c);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    if (k>n-1){
        cout<<"impossible"<<endl;
        return 0;
    }
    for (int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        fe[a].insert(b);
        fe[b].insert(a);
    }
    for (int i=2;i<=n;i++){
        need.insert(i);
    }
    int cs=0;
    for (int i=2;i<=n;i++){
        if (co[i]==0){
            need.erase(i);
            dfs(i, i);
            cs++;
        }
    }
    set<int> cf;
    int ee=0;
    for (int i=2;i<=n;i++){
        if (fe[1].count(i)==0){
            cf.insert(co[i]);
            ee++;
        }
    }
    if ((int)cf.size()>k||(int)cf.size()!=cs||ee<k){
        cout<<"impossible"<<endl;
        return 0;
    }
    cout<<"possible"<<endl;
}