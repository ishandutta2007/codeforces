#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;
int n,m;
set<pair<int,int>> connect;
vector<int> group[4];
bool del[maxn];
bool isin(int u,int v){
    if( u > v) swap(u,v);
    return connect.count(make_pair(u,v));
}
int col[maxn],ct[20];
vector<pair<int,int>> edge;

int main(){
    scanf("%d%d",&n,&m);
    int u,v;
    for(int i=1;i<=m;i++){
        scanf("%d %d",&u,&v);
        edge.emplace_back(u,v);
        if(u > v) swap(u,v);
        connect.insert({u,v});
    }
    for(int j=1;j<=3;j++){
    int found  = -1;
    for(int i=1;i<=n;i++){
        if(!del[i]){
            found = i;
            break;
        }
    }
    if(found == -1) return !printf("-1");
    group[j].push_back(found); del[found] = true;
    for(int i=found + 1;i <= n;i++){
        if(del[i]) continue;
        if(!isin(found,i)){
            group[j].push_back(i);
            del[i] = true;
        }
    }
    }
    int sum = (int)group[1].size() + (int)group[2].size() + (int)group[3].size();
    if(sum != n)
        return !printf("-1");

    for(int j=1;j<=3;j++)
        for(int i:group[j])
            col[i] = j;

    for(auto i:edge){
        if(col[i.first] == col[i.second]) return !printf("-1");
        ct[col[i.first] * col[i.second]] ++ ;
    }
    bool ok = true;
    for(int i=1;i<=2;i++)
        for(int j=i+1;j<=3;j++)
            ok &= ((1LL * (int)group[i].size() * (int)group[j].size()) == ct[i*j]);
    if(!ok) return !printf("-1");
    for(int i=1;i<=n;i++)
        printf("%d ",col[i]);
}
/*
    Good Luck
        -Lucina
*/