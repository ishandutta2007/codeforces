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
using namespace std;
typedef long long int LL;
typedef pair<int,int> P;
typedef pair<LL,int> LP;
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

vector<int> path[220000];
int deg[220000];

int main(){
    int n,m,p;
    int i,j,k;
    int a,b,c;
    vector<P> vp;
    queue<int> q1;
    vector<int> vs;
    int cnt=0;
    cin>>n>>m>>p;
    for(i=0;i<m;i++){
        cin>>a>>b;
        a--,b--;
        vp.push_back(make_pair(a,b));
        path[a].push_back(b);
        path[b].push_back(a);
        deg[a]++,deg[b]++;
    }
    for(i=0;i<n;i++){
        if(deg[i]<p){
            cnt++,deg[i]=0;
            q1.push(i);
        }
    }
    for(i=0;i<m;i++){
        while(!q1.empty()){
            a=q1.front(),q1.pop();
            for(auto to:path[a]){
                if(deg[to]==0)continue;
                deg[to]--;
                if(deg[to]<p){
                    cnt++,deg[to]=0;
                    q1.push(to);
                }
            }
        }
        vs.push_back(n-cnt);
        a=vp.back().first,b=vp.back().second;
        vp.pop_back();
        path[a].pop_back(),path[b].pop_back();
        if(deg[a]==0 || deg[b]==0)continue;
        deg[a]--,deg[b]--;
        if(deg[a]<p){
            cnt++,deg[a]=0;
            q1.push(a);
        }
        if(deg[b]<p){
            cnt++,deg[b]=0;
            q1.push(b);
        }
    }
    reverse(vs.begin(),vs.end());
    array_show(vs);
}