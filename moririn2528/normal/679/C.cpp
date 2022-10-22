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
template<typename T> istream& operator>>(istream& is,vector<T>& v1){
    int n=v1.size();
    for(int i=0;i<n;i++)is>>v1[i];
    return is;
}

namespace sol{
    int n,m;
    vector<vector<int>> cnt,cid,su;
    string grid[555];

    int dfs(int x,int y,int id,vector<P>& v1){
        if(x<0 || n<=x || y<0 || n<=y)return 0;
        if(grid[x][y]=='X' || cid[x][y]!=-1)return 0;
        cid[x][y]=id;
        v1.push_back({x,y});
        int s=1;
        int i,j;
        for(i=-1;i<=1;i++){
            for(j=-1;j<=1;j++){
                if((i+j+2)%2==0)continue;
                s+=dfs(x+i,y+j,id,v1);
            }
        }
        return s;
    }

    vector<int> vs;
    int s=0;

    int s_init(){
        vs.assign(n*n,0);
        s=0;
    }

    void s_in(int x,int y){
        if(x<0 || y<0 || n<=x || n<=y)return;
        if(grid[x][y]=='X')return;
        int id=cid[x][y];
        if(vs[id]==0)s+=cnt[x][y];
        vs[id]++;
    }
    void s_out(int x,int y){
        if(x<0 || y<0 || n<=x || n<=y)return;
        if(grid[x][y]=='X')return;
        int id=cid[x][y];
        vs[id]--;
        if(vs[id]==0)s-=cnt[x][y];
    }

    int block_range_count(int x,int y){
        int ex=min(n,x+m),ey=min(n,y+m);
        return su[ex][ey]-su[ex][y]-su[x][ey]+su[x][y];
    }

    void solve(){
        int i,j,k;
        int a,b,c;
        cin>>n>>m;
        cnt.assign(n,vector<int>(n,0));
        cid.assign(n,vector<int>(n,-1));
        su.assign(n+1,vector<int>(n+1,0));
        for(i=0;i<n;i++){
            cin>>grid[i];
        }
        vector<P> vp;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                a=0;
                vp.clear();
                b=dfs(i,j,i*n+j,vp);
                for(auto node:vp){
                    cnt[node.first][node.second]=b;
                }
                su[i+1][j+1]=su[i+1][j]+su[i][j+1]-su[i][j];
                if(grid[i][j]=='X')su[i+1][j+1]++;
            }
        }
        int ss=0;
        for(i=0;i<=n-m;i++){
            s_init();
            for(j=-1;j<=m;j++){
                for(k=-1;k<=m;k++){
                    a=0;
                    if(j==-1 || j==m)a++;
                    if(k==-1 || k==m)a++;
                    if(a==2)continue;
                    s_in(i+j,k);
                }
            }
            ss=max(ss,s+block_range_count(i,0));
            for(j=0;j<n-m;j++){
                for(k=0;k<m;k++){
                    s_out(i+k,j-1);
                    s_in(i+k,j+m+1);
                }
                s_out(i-1,j),s_out(i+m,j);
                s_in(i-1,j+m),s_in(i+m,j+m);
                ss=max(ss,s+block_range_count(i,j+1));
            }
        }
        cout<<ss<<endl;
    }
}

int main(){
    sol::solve();
}