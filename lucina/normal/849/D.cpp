#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
struct pa{
    int u,v,pos;
    bool operator<(const pa x)const{
        return u==x.u?v<x.v:u<x.u;
    }
};
int n,w,h,x,y,z;
pair<int,int> ans[maxn];
deque<int> d[2][maxn];
vector<int> b[2][maxn];
vector<pa> p[3];


int main(){
    scanf("%d%d%d",&n,&w,&h);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&x,&y,&z);
        p[x].push_back({y,z,i});
    }
    for(int i=1;i<=2;i++)
    sort(p[i].begin(),p[i].end());
    for(auto i:p[2]){
        //u position v waiting time
        x=i.u-i.v;
        y=(x<0)?0:1;x=abs(x);
        d[y][x].push_back(i.pos);
        b[y][x].push_back(i.u);
    }
    for(auto i:p[1]){
            x=i.u-i.v;
        y=(x<0)?0:1;x=abs(x);
        if(!d[y][x].empty()){
            z=d[y][x].back();
            d[y][x].push_front(i.pos);
            d[y][x].pop_back();
            ans[z]=make_pair(i.u,h);
        }
        else{
            ans[i.pos]=make_pair(i.u,h);
        }
    }
    for(auto i:p[2]){
        x=i.u-i.v;
        y=(x<0)?0:1;x=abs(x);
        ans[d[y][x].back()]=make_pair(w,b[y][x].back());
        d[y][x].pop_back();b[y][x].pop_back();
    }
    for(int i=1;i<=n;i++)
        printf("%d %d\n",ans[i].first,ans[i].second);
}