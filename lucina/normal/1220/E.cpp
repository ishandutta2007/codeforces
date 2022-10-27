#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e5+10;
int n,m,deg[maxn],w[maxn];
vector<int> a[maxn];
long long b[maxn];

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&w[i]);
    int u,v;
    while(m -- ){
        scanf("%d%d",&u,&v);
        a[u].push_back(v);
        a[v].push_back(u);
        deg[u] ++;
        deg[v] ++;
    }
    int s;
    scanf("%d" ,&s);
    deg[s] = maxn;
    vector<int> st;
    for(int i=1;i<=n;i++){
        if(deg[i] == 1)
            st.push_back(i);
    }
    while(!st.empty()){
        s = st.back();
        --deg[s];
        st.pop_back();
        for(int i:a[s]){
            if(deg[i] == 0)continue;
            b[i] = max(b[i], b[s] + w[s]);
            deg[i] -- ;
            if(deg[i] == 1)
                st.push_back(i);
        }
    }
    long long ans = 0, best = 0;
    for(int i=1;i<=n;i++){
        if(deg[i] == 0)continue;
        ans += w[i];
        best = max(best,b[i]);
    }
    printf("%lld\n", ans + best);
    ///stack or queue :O

}