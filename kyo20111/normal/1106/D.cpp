#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,chk[101010];
vector<int> v[101010];
priority_queue<int,vector<int>,greater<int> > pq;
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    pq.push(1);
    chk[1]=1;
    while(!pq.empty()){
        int nw=pq.top();
        pq.pop();
        printf("%d ",nw);
        for(int i=0;i<v[nw].size();i++){
            if(chk[v[nw][i]]) continue;
            chk[v[nw][i]]=1;
            pq.push(v[nw][i]);
        }
    }
}