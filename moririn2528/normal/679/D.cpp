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
typedef pair<LL,LL> LP;
const int INF=1<<20;
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
template<typename T> ostream& operator<<(ostream& os,const vector<T>& v1){
    int n=v1.size();
    for(int i=0;i<n;i++){
        if(i)os<<" ";
        os<<v1[i];
    }
    return os;
}
template<typename T1,typename T2> ostream& operator<<(ostream& os,const pair<T1,T2>& p){
    os<<p.first<<" "<<p.second;
    return os;
}
template<typename T> istream& operator>>(istream& is,vector<T>& v1){
    int n=v1.size();
    for(int i=0;i<n;i++)is>>v1[i];
    return is;
}

namespace sol{

    vector<vector<int>> dis,path;

    void solve(){
        int n,m;
        int i,j,k;
        int a,b,c,d;
        cin>>n>>m;
        dis.assign(n,vector<int>(n,INF));
        path.resize(n);
        for(i=0;i<n;i++)dis[i][i]=0;
        for(i=0;i<m;i++){
            cin>>a>>b;
            a--,b--;
            path[a].push_back(b);
            path[b].push_back(a);
            dis[a][b]=1,dis[b][a]=1;
        }
        for(k=0;k<n;k++){
            for(i=0;i<n;i++){
                for(j=0;j<n;j++){
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
                }
            }
        }
        double s=0;
        double da,db,dc,dd;
        for(i=0;i<n;i++){
            da=0;
            for(d=0;d<=n;d++){
                vector<double> v1(n,0),v2(n,0);
                for(j=0,a=0;j<n;j++){
                    if(dis[i][j]!=d)continue;
                    a++;
                    for(auto to:path[j]){
                        v1[to]+=1.0/(path[j].size()*n);
                    }
                }
                if(a==0)continue;
                if(a==1){
                    da+=1.0/n;
                    continue;
                }
                dd=1.0/n;
                vector<pair<int,double>> vp;
                for(j=0;j<n;j++){
                    if(v1[j]==0)continue;
                    vp.push_back({j,v1[j]});
                }
                for(j=0;j<n;j++){
                    db=0;
                    for(auto& node:vp){
                        b=dis[j][node.first];
                        v2[b]=max(v2[b],node.second);
                    }
                    for(auto& node:vp){
                        b=dis[j][node.first];
                        db+=v2[b];
                        v2[b]=0;
                    }
                    dd=max(dd,db);
                }
                da+=dd;
            }
            s=max(s,da);
        }
        cout<<fixed<<setprecision(20);
        cout<<s<<endl;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    sol::solve();
}