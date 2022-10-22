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
using namespace std;
typedef long long int LL;
typedef pair<int,int> P;
typedef pair<LL,int> LP;
const int INF=1<<30;
const LL MAX=998244353;

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

vector<vector<int>> dis(220000,vector<int>(22,INF));
vector<vector<int>> path;
vector<vector<int>> rpath;
typedef tuple<int,int,int> T;
priority_queue<T,vector<T>,greater<T>> q1;
typedef tuple<int,int,int,int> T2;
priority_queue<T2,vector<T2>,greater<T2>> q2;
LL pow2[220000];

int main(){
    int n,m;
    int i,j,k;
    int a,b,c,d;
    const int M=20;
    pow2[0]=1;
    for(i=0;i<2e5+7;i++){
        pow2[i+1]=pow2[i]*2%MAX;
    }
    cin>>n>>m;
    path.assign(n,vector<int>());
    rpath.assign(n,vector<int>());
    for(i=0;i<m;i++){
        cin>>a>>b;
        a--,b--;
        path[a].push_back(b);
        rpath[b].push_back(a);
    }
    q1.push(make_tuple(0,0,0));
    dis[0][0]=0;
    while(!q1.empty()){
        tie(a,b,c)=q1.top(),q1.pop();
        if(dis[b][c]!=a)continue;
        vector<int>* pat;
        if(c%2==0)pat=&path[b];
        else pat=&rpath[b];
        for(auto to:*pat){
            if(dis[to][c]<=a+1)continue;
            dis[to][c]=a+1;
            q1.push(make_tuple(a+1,to,c));
        }
        if(c<M && dis[b][c+1]>a+pow2[c]){
            dis[b][c+1]=a+pow2[c];
            q1.push(make_tuple(dis[b][c+1],b,c+1));
        }
    }
    a=INF;
    for(i=0;i<=M;i++){
        a=min(a,dis[n-1][i]);
    }
    if(a!=INF){
        cout<<a<<endl;
        return 0;
    }
    vector<vector<P>> disp(n,vector<P>(2,make_pair(INF,INF)));
    q2.push(make_tuple(0,0,0,0));
    disp[0][0]=make_pair(0,0);
    while(!q2.empty()){
        tie(a,b,c,d)=q2.top();q2.pop();
        if(disp[c][d]!=make_pair(a,b))continue;
        if(d==0){
            for(auto to:path[c]){
                if(disp[to][d]<=make_pair(a,b+1))continue;
                disp[to][d]=make_pair(a,b+1);
                q2.push(make_tuple(a,b+1,to,d));
            }
        }else{
            for(auto to:rpath[c]){
                if(disp[to][d]<=make_pair(a,b+1))continue;
                disp[to][d]=make_pair(a,b+1);
                q2.push(make_tuple(a,b+1,to,d));
            }
        }
        if(disp[c][1-d]>make_pair(a+1,b)){
            disp[c][1-d]=make_pair(a+1,b);
            q2.push(make_tuple(a+1,b,c,1-d));
        }
    }
    P pa=min(disp[n-1][0],disp[n-1][1]);
    a=(pow2[pa.first]+MAX-1+pa.second)%MAX;
    cout<<a<<endl;
}