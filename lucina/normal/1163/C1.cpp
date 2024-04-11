#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,u,v,d,r;
using pii=pair<double,double>;
#define all(b) b.begin(),b.end()
#define Unique(b)  sort(all(b)),b.erase(unique(all(b)),b.end())
pii a[maxn];
pii intersect(pii b,pii c){
    if(b.first==c.first){
        return {1e18+7,1e18+7};
    }
    pii line1={0.0,0.0};
    line1.first=(b.second-c.second)/(b.first-c.first);
    line1.second=(b.second-(line1.first*b.first));
    return line1;
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&u,&v);
        a[i].first=(double)u;
        a[i].second=(double)v;
    }
    vector<pii> line;
    vector<double> l;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            pii temp=intersect(a[i],a[j]);
            if(temp.first!=1e18+7||temp.second!=1e18+7)
             line.push_back(temp);
             else
                l.push_back(a[i].first);
        }
    }
    Unique(line);
    Unique(l);
    d=line.size();
    int e=l.size();
    long long ans=0;
    ans+=(1ll*d*(d-1))/2;
    ans+=(1ll*d*e);
    for(int i=0;i<d;i++){
        int j=i;
        while(j+1<d&&line[j+1].first==line[i].first)
            j++;
        ans-=((j-i+1)*(j-i))/2;
        i=j;
    }
    printf("%lld\n",ans);
}