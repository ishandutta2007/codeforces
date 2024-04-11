#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define maxn 1000000
using namespace std;
int n,m;
vector<int> a[maxn];
pair<int,int> t[maxn];
int w[maxn];
bool s[maxn];
int main() {
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++) {
        int u,v;
        scanf("%d %d",&u,&v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for(int i=1;i<=n;i++) {
        int x;
        scanf("%d",&x);
        t[i]={x,i};
    }
    sort(t+1,t+n+1);
    for(int i=1;i<=n;i++) {
        int g=1;
        int u=t[i].second;
        int x=t[i].first;
        for(auto v:a[u]) {
            s[w[v]]=true;
        }
        while(s[g]) g++;
        if(g!=x) {
            printf("-1");
            return 0;
        }
        w[u]=g;
        for(auto v:a[u]) {
            s[w[v]]=false;
        }
    }
    for(int i=1;i<=n;i++) printf("%d ",t[i].second);
	return 0;
}