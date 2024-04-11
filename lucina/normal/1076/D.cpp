#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10*x+ch-'0';ch=getchar();}
    return x*f;
}
struct fuck{
long long va;
int nod;
int ed;
bool operator<(const fuck d)const{
    return va>d.va;
}
};
struct edge{
    int to;
    int vall;
    int pos;
};
int n,m,k,u,v,w,f1,f2;
long long val[maxn];
vector<int> ans;
bool vis[maxn];
vector<edge> a[maxn];

int main(){
    n=read();m=read();k=read();
    for(int i=1;i<=m;i++){
        u=read();v=read();w=read();
        a[u].push_back({v,w,i});
        a[v].push_back({u,w,i});
    }
    priority_queue<fuck> q;
    for(int i=1;i<=n;i++){
        val[i]=2e18;
        vis[i]=false;
    }
    q.push({(long long)0,1,0});
    val[1]=(long long)0;
    while(!q.empty()&&k>=0){
        k--;
        while(!q.empty()&&vis[q.top().nod])
        q.pop();
        if(q.empty())
            break;
        u=q.top().nod;
        vis[u]=true;
        ans.push_back(q.top().ed);
        q.pop();
        for(auto i:a[u]){
            if(!vis[i.to]){
                if(val[i.to]>val[u]+(long long)i.vall){
                    val[i.to]=val[u]+(long long)i.vall;
                    q.push({(long long)val[i.to],i.to,i.pos});
                }
            }
        }
    }
    printf("%d\n",ans.size()-1);
   for(int i=1;i<ans.size();i++)
        printf("%d ",ans[i]);
}