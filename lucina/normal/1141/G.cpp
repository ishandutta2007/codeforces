#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,k,u,v,deg[maxn],c,b[maxn];
vector<int> a[maxn];
map<pair<int,int>,int> edge;

void dfs(int nod,int pa,int col){
    int d=0;
    for(auto i:a[nod]){
        if(i!=pa){
            ++d;
            u=i,v=nod; if(u>v)swap(u,v);
            int q=col+(d%c)>c?col+(d%c)-c:col+(d%c);
            b[edge[{u,v}]]=q;
            dfs(i,nod,q);
        }
    }
    return ;

}

int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<n;i++){
        scanf("%d%d",&u,&v);
        a[u].push_back(v);
        a[v].push_back(u);
        deg[u]++,deg[v]++;
        if(u>v)swap(u,v);
        edge[{u,v}]=i;
    }
    sort(deg+1,deg+1+n);
    c=deg[n-k];
    dfs(1,0,1);
    printf("%d\n",c);
    for(int i=1;i<n;i++)
        printf("%d ",b[i]);
}