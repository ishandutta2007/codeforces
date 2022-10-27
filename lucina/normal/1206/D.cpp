#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10,INF=1e9;
int n,bit[65],x;
long long a[maxn];
vector<int> cc[maxn];
set<pair<int,int>> in;
vector<int> g[maxn],r[2][maxn];
int t[maxn],k;
bool vis[maxn];
int sz,dis[maxn];



int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        for(int j=0;j<=61;j++){
            if(a[i]&(1LL<<j)){
                bit[j]++;
                cc[j].push_back(i);
                if(bit[j]>=3){
                    return !printf("3\n");
                }
            }
        }
    }
    vector<pair<int,int>> laz;
    vector<int> all;
    all.push_back(-1);
    for(int i=0;i<=61;i++){
        for(auto j:cc[i])
            all.push_back(j);
    }
    sort(all.begin(),all.end());
    all.erase(unique(all.begin(),all.end()),all.end());
    for(int i=0;i<=61;i++){
        if((int)cc[i].size()<=1){
            continue;
        }
        int x=lower_bound(all.begin(),all.end(),cc[i][0])-all.begin(),y=lower_bound(all.begin(),all.end(),cc[i][1])-all.begin();
        if(!in.count(make_pair(x,y))){
        g[x].push_back(y);
        in.insert(make_pair(x,y));
        laz.push_back(make_pair(x,y));
        }
        if(!in.count(make_pair(y,x))){
        g[y].push_back(x);
        in.insert(make_pair(y,x));
        }
    }
    /*printf("#:\n");
    for(int i=1;i<=n;i++){
        for(auto j:g[i]){
            printf("%d %d\n",i,j);
        }
    }*/
    //cerr<<".................\n";
    int ans=1e9;
    for(auto it:laz){
         //   cerr<<it.first<<' '<<it.second<<'\n';
        queue<int> q;
        for(int i=1;i<=n;i++){
            dis[i]=-1;
        }
        q.push(it.first);
        dis[it.first]=0;
        while(!q.empty()){
            int top=q.front();
            q.pop();
            for(int i:g[top]){
                if((top!=it.first||i!=it.second)&&(top!=it.second||i!=it.first)){
                    if(dis[i]==-1){
                        dis[i]=dis[top]+1;
                        q.push(i);
                    }
                }
            }
        }
        if(dis[it.second]!=-1)
        ans=min(ans,dis[it.second]+1);
    }
    printf("%d\n",ans==1e9?-1:ans);
}
/*
    Good Luck
        -Lucina
*/