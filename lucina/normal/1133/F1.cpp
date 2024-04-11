#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,m,u,v,best,ma;
vector<int> a[maxn];
bool vis[maxn];
queue<int> q;

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d%d",&u,&v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        if(a[i].size()>ma){
            ma=a[i].size();
            best=i;
        }
    }
    vis[best]=true;
    q.push(best);
    int s;
    while(!q.empty()){
        s=q.front();
        q.pop();
        for(auto i:a[s]){
            if(!vis[i]){
                printf("%d %d\n",s,i);
                vis[i]=true;
                q.push(i);
            }
        }
    }
}