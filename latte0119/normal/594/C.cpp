#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<string>
#include<cstring>
using namespace std;

typedef long long ll;
const int mod=1000000007;
const ll INF=4000000000000000010ll;

int N,K;
int x[100000],y[100000];
vector<pair<int,int>>xs,ys;

ll f(int lx,int hx,int ly,int hy){
    if(lx>hx||ly>hy)return INF;
    set<int>taken;
    for(int i=0;i<lx;i++)taken.insert(xs[i].second);
    for(int i=hx+1;i<N;i++)taken.insert(xs[i].second);
    for(int i=0;i<ly;i++)taken.insert(ys[i].second);
    for(int i=hy+1;i<N;i++)taken.insert(ys[i].second);

    if(taken.size()>K)return INF;
    return (ll)((max(1,xs[hx].first-xs[lx].first)+1)/2)*((max(1,ys[hy].first-ys[ly].first)+1)/2);
}

int main(){
    scanf("%d%d",&N,&K);
    for(int i=0;i<N;i++){
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        x[i]=x1+x2;
        y[i]=y1+y2;
        xs.push_back({x[i],i});
        ys.push_back({y[i],i});
    }
    sort(xs.begin(),xs.end());
    sort(ys.begin(),ys.end());

    ll ans=INF;

    for(int i=0;i<=K;i++){
        for(int j=N-1-K;j<N;j++){
            for(int k=0;k<=K;k++){
                for(int l=N-1-K;l<N;l++){
                    ans=min(ans,f(i,j,k,l));
                }
            }
        }
    }

    printf("%lld\n",ans);

    return 0;
}