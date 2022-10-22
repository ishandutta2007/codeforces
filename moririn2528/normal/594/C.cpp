#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
#include<deque>
#include<iomanip>
#include<tuple>
#include<cassert>
#include<set>
#include<complex>
#include<numeric>
#include<functional>
#include<unordered_map>
#include<unordered_set>
using namespace std;
typedef long long int LL;
typedef pair<int,int> P;
typedef pair<LL,int> LP;
const LL INF=1LL<<60;
const LL MAX=1e9+7;

void array_show(int *array,int array_n,char middle=' '){
    for(int i=0;i<array_n;i++)printf("%d%c",array[i],(i!=array_n-1?middle:'\n'));
}
void array_show(LL *array,int array_n,char middle=' '){
    for(int i=0;i<array_n;i++)printf("%lld%c",array[i],(i!=array_n-1?middle:'\n'));
}
void array_show(vector<int> &vec_s,int vec_n=-1,char middle=' '){
    if(vec_n==-1)vec_n=vec_s.size();
    for(int i=0;i<vec_n;i++)printf("%d%c",vec_s[i],(i!=vec_n-1?middle:'\n'));
}
void array_show(vector<LL> &vec_s,int vec_n=-1,char middle=' '){
    if(vec_n==-1)vec_n=vec_s.size();
    for(int i=0;i<vec_n;i++)printf("%lld%c",vec_s[i],(i!=vec_n-1?middle:'\n'));
}

namespace sol{
    int n,m;
    int X[110000],Y[110000];
    vector<P> vx,vy;
    int used[110000];
    int used_cnt=1;

    int set(int id){
        if(used[id]==used_cnt)return 0;
        used[id]=used_cnt;
        return 1;
    }

    LL check(int x1,int y1,int x2,int y2){
        if(x1>x2 || y1>y2)return INF;
        int i;
        used_cnt++;
        int rm=0;
        for(i=0;i<n && vx[i].first<x1;i++){
            rm+=set(vx[i].second);
        }
        for(i=0;i<n && vy[i].first<y1;i++){
            rm+=set(vy[i].second);
        }
        for(i=n-1;i>=0 && vx[i].first>x2;i--){
            rm+=set(vx[i].second);
        }
        for(i=n-1;i>=0 && vy[i].first>y2;i--){
            rm+=set(vy[i].second);
        }
        if(rm>m)return INF;
        LL s=max((x2-x1+1)/2,1);
        s*=max((y2-y1+1)/2,1);
        return s;
    }

    void solve(){
        int i,j,k,l;
        int a,b,c,d;
        cin>>n>>m;
        for(i=0;i<n;i++){
            cin>>a>>b>>c>>d;
            X[i]=a+c,Y[i]=b+d;
            vx.push_back({X[i],i});
            vy.push_back({Y[i],i});
        }
        sort(vx.begin(),vx.end());
        sort(vy.begin(),vy.end());
        LL s=INF;
        for(i=0;i<=m;i++){
            for(j=0;j<=m;j++){
                for(k=0;k<=m;k++){
                    for(l=0;l<=m;l++){
                        s=min(s,check(vx[i].first,vy[j].first,vx[n-1-k].first,vy[n-1-l].first));
                    }
                }
            }
        }
        cout<<s<<endl;
    }
}

int main(){
    sol::solve();
}