#include<bits/stdc++.h>
using namespace std;
int n;
vector<pair<int,int> > edg;
bool com[3000000];
bool con[3000000];
stack<int> s;
int main() {
    com[0]=com[1]=true;
    for(int i=2;i<=1000;i++) {
        if(!com[i]) {
            for(int j=i*i;j<=1000000;j+=i) com[j]=true;
        }
    }
    scanf("%d",&n);
    for(int i=1;i<n;i++) {
        edg.push_back({i,i+1});
    }
    edg.push_back({n,1});
    int cur=n;
    int u=1,v;
    while(com[cur]) {
        v=(u+2>n) ? (u+2-n) : (u+2);
        if(!con[u] && !con[v]) {
            edg.push_back({u,v});
            cur++;
            con[u]=true;
            con[v]=true;
        }
        u++;
    }
    printf("%d\n",cur);
    for(int i=0;i<cur;i++) printf("%d %d\n",edg[i].first,edg[i].second);
    return 0;
}