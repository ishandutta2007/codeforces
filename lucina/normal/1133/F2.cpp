#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,m,u,v,c[maxn],pt,d;
bool vis[maxn],vv[maxn],used[maxn],vis1[maxn];
vector<int> a[maxn];
vector<pair<int,int>> q;
queue<int> q1;
void dfs(int nod){
    vis[nod]=true;
    c[nod]=pt;
    for(auto i:a[nod]){
        if(!vis[i]){
            dfs(i);
        }
    }
    return;
}

int main(){
    scanf("%d%d%d",&n,&m,&d);
    for(int i=1;i<=m;i++){
        scanf("%d%d",&u,&v);
        if(u!=1&&v!=1){
            a[u].push_back(v);
            a[v].push_back(u);
        }
        else{
            if(u>1)swap(u,v);
            q.push_back({u,v});
        }
    }
    for(int j=2;j<=n;j++){
        if(!vis[j]){
            pt++;
            dfs(j);
        }
    }
    if(pt>d||d>q.size()){
        printf("NO");
        return 0;
    }
    for(int i=0;i<q.size();i++){
        if(!vv[c[q[i].second]]){
            a[1].push_back(q[i].second);
            a[q[i].second].push_back(1);
            d--;
            vv[c[q[i].second]]=true;
            used[i]=true;
        }
    }
    for(int i=0;i<q.size();i++){
        if(d==0)
            break;
        if(!used[i]){
            a[1].push_back(q[i].second);
            a[q[i].second].push_back(1);
            d--;
            used[i]=true;
        }
    }
    int s;
    printf("YES\n");
    q1.push(1);
    vis1[1]=true;
    while(!q1.empty()){
        s=q1.front();
        q1.pop();
        for(auto i:a[s]){
            if(!vis1[i]){
                printf("%d %d\n",s,i);
                vis1[i]=true;
                q1.push(i);
            }
        }
    }

}