#include<bits/stdc++.h>
using namespace std;
const int maxn=10010;
template<class T>struct BIT{
    T bit[maxn];
    BIT(){
        memset(bit,0,sizeof(bit));
    }
    void update(int idx,int val){
        while(idx<maxn){
            bit[idx]+=val;
            idx+=(idx&(-idx));
        }
        return;
    }
    T get(int idx){
        T sum=0;
        while(idx>0){
            sum+=(bit[idx]);
            idx-=(idx&(-idx));
        }
        return sum;
    }
    T get(int l,int r){
        return get(r)-get(l-1);
    }
};
int n,x1,x2,y1,y2;
vector<pair<int,int>> hor[maxn],ver[maxn];
vector<int> sc[maxn];
long long ans;
long long cal(int x){
    return 1LL*x*(x-1)/2;
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        x1+=5001,x2+=5001,y1+=5001,y2+=5001;
        if(x1==x2){
            ver[x1].push_back({min(y1,y2),max(y1,y2)});
        }
        else{
            hor[y1].push_back({min(x1,x2),max(x1,x2)});
        }
    }
    for(int i=0;i<=10003;i++){
        for(auto x:hor[i]){
            BIT<int> f;
            for(int j=0;j<=10003;j++)sc[j].clear();
            for(int j=x.first;j<=x.second;j++){
                for(auto y:ver[j]){
                    if(y.first<=i&&y.second>i){
                    f.update(j,1);
                    sc[y.second].push_back(j);
                }
            }
        }
        for(int j=i+1;j<=10003;j++){
            for(auto y:hor[j]){
                ans+=cal((f.get(y.first,y.second)));
            }
            for(auto y:sc[j]){
                f.update(y,-1);
            }
        }
    }
    }
    printf("%lld\n",ans);
}