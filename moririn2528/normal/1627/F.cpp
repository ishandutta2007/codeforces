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
const int INF=1<<30;
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
template<typename T1,typename T2> istream& operator>>(istream& is,pair<T1,T2>& p){
    is>>p.first>>p.second;
    return is;
}

namespace sol{

    void init(){
        
    }
    void solve(){
        int n,m;
        int i,j,k;
        int a,b,c,d;
        cin>>n>>m;
        vector<vector<int>> grid(2*m+2,vector<int>(2*m+2));
        for(i=0;i<n;i++){
            cin>>a>>b>>c>>d;
            grid[a+c-1][b+d-1]++;
        }
        vector<vector<P>> path((m+1)*(m+1));
        for(i=0;i<m-1;i++){
            for(j=0;j<m;j++){
                a=(i+1)*(m+1)+j;
                b=(i+1)*(m+1)+j+1;
                c=grid[2*i+2][2*j+1]+grid[2*(m-i)-2][2*(m-j)-1];
                path[a].push_back({b,c});
                path[b].push_back({a,c});
                a=j*(m+1)+i+1;
                b=(j+1)*(m+1)+i+1;
                c=grid[2*j+1][2*i+2]+grid[2*(m-j)-1][2*(m-i)-2];
                path[a].push_back({b,c});
                path[b].push_back({a,c});
            }
        }
        priority_queue<P,vector<P>,greater<P>> q1;
        for(i=0;i<=m;i++){
            q1.push({0,(m+1)*i});
            q1.push({0,(m+1)*i+m});
            q1.push({0,i});
            q1.push({0,(m+1)*m+i});
        }
        vector<int> dis((m+1)*(m+1),-1);
        while(!q1.empty()){
            a=q1.top().first,b=q1.top().second;
            q1.pop();
            if(dis[b]!=-1)continue;
            dis[b]=a;
            for(auto node:path[b]){
                int to=node.first,cost=node.second;
                q1.push({a+cost,to});
            }
        }
        cout<<n-dis[m/2*(m+1)+m/2]<<endl;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,i;
    sol::init();
    cin>>n;
    for(i=0;i<n;i++){
        sol::solve();
    }
}