#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
#define Unique(x)  sort(all(x)),x.erase(unique(all(x)),x.end())
const int maxn=4e5+10;
int n,k[maxn],m,u,v,l,r,ans,mid,d[maxn],la[maxn];
vector<int> sp[maxn];
vector<pair<int,int>> offer;
bool ch(int x){
    int mon=0;
    for(int i=1;i<=n;i++)
        d[i]=k[i];
    for(int i=1;i<=400000;i++)
        sp[i].clear();
    memset(la,0,sizeof(la));
    for(auto i:offer){
        if(i.first<=x){
            sp[i.first].push_back(i.second);
            la[i.second]=max(la[i.second],i.first);
        }
    }
    for(int i=1;i<=400000;i++)
        Unique(sp[i]);
    for(int i=1;i<=x;i++){
            mon++;
        vector<int> last;
        for(auto j:sp[i]){
            if(d[j]>0){
                if(la[j]==i)
                    last.push_back(j);
            }
        }
        for(int j:last){
            if(mon>=d[j]){
                mon-=d[j];
                d[j]=0;
            }
            else{
                d[j]-=mon;
                mon=0;break;
            }
        }
    }
    for(int i=1;i<=n;i++){
        mon-=(2*d[i]);
    }
    return mon>=0;
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&k[i]);
    }
    while(m--){
        scanf("%d%d",&u,&v);
        offer.push_back(make_pair(u,v));
    }

    int l=1,r=400000,ans=1e9;
    while(l<=r){
        mid=(l+r)>>1;
        if(ch(mid)){
            ans=mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    printf("%d\n",ans);
}