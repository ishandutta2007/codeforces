
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
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
        os<<v1[i]+1;
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
    vector<vector<int>> path,dis;
    int s=0;
    vector<int> vs;

    void check(int a,int b,int c,int d){
        int x=dis[a][b]+dis[b][c]+dis[c][d];
        if(s>=x)return;
        s=x;
        vs={a,b,c,d};
    }

    void solve(){
        int n,m;
        int i,j,k;
        int a,b,c;
        cin>>n>>m;
        path.resize(n);
        dis.assign(n,vector<int>(n,-INF));
        for(i=0;i<m;i++){
            cin>>a>>b;
            a--,b--;
            path[a].push_back(b);
        }
        vector<vector<P>> v1(n),v2(n);
        for(i=0;i<n;i++){
            queue<int> q1;
            q1.push(i);
            for(k=0;!q1.empty();k++){
                c=q1.size();
                while(c--){
                    b=q1.front();q1.pop();
                    if(dis[i][b]!=-INF)continue;
                    dis[i][b]=k;
                    for(auto to:path[b]){
                        if(dis[i][to]!=-INF)continue;
                        q1.push(to);
                    }
                }
            }
        }
        for(i=0;i<n;i++){
            v1[i].resize(n-1);
            v2[i].resize(n-1);
            for(j=0,k=0;j<n;j++){
                if(i==j)continue;
                v1[i][k]={dis[i][j],j};
                v2[i][k]={dis[j][i],j};
                k++;
            }
            sort(v1[i].rbegin(),v1[i].rend());
            sort(v2[i].rbegin(),v2[i].rend());
        }
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(i==j)continue;
                int va[2],vb[2];
                a=0,b=0;
                for(k=0;k<n-1 && (a<2 ||b<2);k++){
                    if(a<2 && v2[i][k].second!=j)va[a++]=v2[i][k].second;
                    if(b<2 && v1[j][k].second!=i)vb[b++]=v1[j][k].second;
                }
                if(va[0]!=vb[0])check(va[0],i,j,vb[0]);
                else{
                    check(va[0],i,j,vb[1]);
                    check(va[1],i,j,vb[0]);
                }
            }
        }
        cout<<vs<<endl;

    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    sol::solve();
}