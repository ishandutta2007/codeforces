#include<bits/stdc++.h>
#define maxn 500000
using namespace std;
int n;
vector<int> a[maxn];
int d;
vector<pair<int,int> > rez;
void dfs(int u,int tu=0,int p=-1) {
    int ch=0;
    //cout<<u<<" "<<tu<<" "<<p<<endl;
    for(auto v:a[u]) {
        if(v!=p) ch++;
    }
    if(u==1) {
        for(int i=0;i<a[u].size();i++) {
            int v=a[u][i];
            if(v!=p) {
                rez.push_back({v,tu+1});
                dfs(v,tu+1,u);
                tu++;
                ch--;
            }
        }
        return;
    }
    if(ch==0) {
        rez.push_back({u,tu-1});
        rez.push_back({p,tu});
        return;
    }
    int tv=tu;
    int to=tu;
    int i=0;
    for(i=0;i<a[u].size() && ch+1>tv;i++) {
        int v=a[u][i];
        if(v!=p) {
            rez.push_back({v,tu+1});
            dfs(v,tu+1,u);
            tu++;
            ch--;
        }
    }
    rez.push_back({u,tv-ch-1});
    tu=tv-ch-1;
    for(;i<a[u].size();i++) {
        int v=a[u][i];
        if(v!=p) {
            rez.push_back({v,tu+1});
            dfs(v,tu+1,u);
            tu++;
            ch--;
        }
    }
    rez.push_back({p,to});
}
int main() {
    scanf("%d",&n);
    for(int i=0;i<n-1;i++) {
        int u,v;
        scanf("%d %d",&u,&v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
    if(n==1) {
        printf("1\n");
        printf("1 0\n");
        return 0;
    }
    for(int i=0;i<n;i++) d=max(d,(int)a[i].size());
    rez.push_back({1,0});
    dfs(1);
    printf("%d\n",rez.size());
    for(auto t:rez) printf("%d %d\n",t.first,t.second);
	return 0;
}