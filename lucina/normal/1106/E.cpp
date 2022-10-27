#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
#define ll long long
int n,k,m,u,v,w,e;
struct event{
int s,t,d,w;
bool si;
bool operator<(const event x)const{
    return w==x.w?d<x.d:w<x.w;
}
};
bool cmp(event x,event y){
    return x.s>y.s;
}
ll dp[2][maxn],ans=(ll)1e18;
vector<event> q;
priority_queue<event> heap;
pair<int,int>a[maxn];

int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=k;i++){
        scanf("%d%d%d%d",&u,&v,&w,&e);
        q.push_back({u,v,w,e});
    }
    sort(q.begin(),q.end(),cmp);
    for(int i=1;i<=n;i++){
        while(!q.empty()&&q.back().s<=i){
            heap.push(q.back());q.pop_back();
        }
        while(!heap.empty()&&heap.top().t<i)
            heap.pop();
        if(heap.empty()){
            a[i]={i,0};
        }
        else{
            event it=heap.top();
            a[i]={it.d,it.w};
        }
    }
    dp[0][1]=0;
    for(int j=0;j<=m;j++){
            for(int i=1;i<=n+1;i++)
            dp[j&1][i]=(ll)1e18;
            dp[j&1][1]=0;
        for(int i=1;i<=n;i++){
            dp[j&1][a[i].first+1]=min(dp[j&1][a[i].first+1],dp[j&1][i]+a[i].second);
            if(j>0)
            dp[j&1][i+1]=min(dp[j&1][i+1],dp[(j&1)^1][i]);

        }
        ans=min(ans,dp[j&1][n+1]);
    }
    printf("%lld\n",ans);
}